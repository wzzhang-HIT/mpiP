/* -*- C -*- 

   @PROLOGUE@

   ----- 

   Jeffrey Vetter vetter3@llnl.gov
   Center for Applied Scientific Computing, LLNL
   12 Aug 2001

   wrappers_special.c -- wrappers that demand special attention

 */

#ifndef lint
static char *rcsid =
  "$Header$";
#endif

#include "mpiPconfig.h"
#include "mpiPi.h"
#include "symbols.h"


/* ----- INIT -------------------------------------------------- */

static int
_MPI_Init (int *argc, char ***argv, void *pc)
{
  int rc = 0;
  int enabledStatus;

  enabledStatus = mpiPi.enabled;
  mpiPi.enabled = 0;

  rc = PMPI_Init (argc, argv);

  mpiPi.enabled = enabledStatus;

  if ( argv != NULL )
    mpiPi_init (GetBaseAppName (**argv));
  else
    mpiPi_init ("Unknown");

  return rc;
}

extern int
MPI_Init (int *argc, char ***argv)
{
  int rc = 0;
  jmp_buf jbuf;
  setjmp (jbuf);
  mpiPi.toolname = "mpiP";

  rc = _MPI_Init (argc, argv, GetPPC (jbuf));

  if ( argc != NULL && argv != NULL )
    mpiPi_copy_given_args (&(mpiPi.ac), mpiPi.av, 32, *argc, *argv);
  else
    mpiPi.ac = 0;

  return rc;
}

extern void
F77_MPI_INIT (int *ierr)
{
  int rc = 0;
  jmp_buf jbuf;
  char **tmp_argv;

  setjmp (jbuf);
  mpiPi.toolname = "mpiP";
  mpiPi_copy_args (&(mpiPi.ac), mpiPi.av, 32);

  tmp_argv = mpiPi.av;
  rc = _MPI_Init (&(mpiPi.ac), (char ***) &tmp_argv, GetPPC (jbuf));
  *ierr = rc;

  return;
}


/* ----- FINALIZE -------------------------------------------------- */

extern int
_MPI_Finalize (void *pc)
{
  int rc = 0;

  mpiPi_finalize ();
  mpiPi.enabled = 0;
  mpiPi_msg_debug ("calling PMPI_Finalize\n");
  rc = PMPI_Finalize ();
  mpiPi_msg_debug ("returning from PMPI_Finalize\n");

  return rc;
}

extern int
MPI_Finalize (void)
{
  int rc = 0;
  jmp_buf jbuf;

  setjmp (jbuf);
  rc = _MPI_Finalize (GetPPC (jbuf));

  return rc;
}

extern void
F77_MPI_FINALIZE (int *ierr)
{
  int rc = 0;
  jmp_buf jbuf;

  setjmp (jbuf);

  rc = _MPI_Finalize (GetPPC (jbuf));
  *ierr = rc;

  return;
}

/* eof */

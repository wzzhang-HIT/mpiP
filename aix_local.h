/* -*- C -*- 

   @PROLOGUE@

   ----- 

   Jeffrey Vetter vetter@llnl.gov
   Center for Applied Scientific Computing, LLNL
   01 Feb 2001

   aix_local.h -- local aix high res timers

*/

#ifndef _AIX_LOCAL_H
#define _AIX_LOCAL_H

/* read_real_time returns nanoseconds */
#define mpiPi_TIMER int
#define mpiPi_TIMER_INIT(timer_addr) {*(timer_addr) = 0;}
#define mpiPi_TIME timebasestruct_t
#define mpiPi_ASNTIME(lhs,rhs) {bcopy(rhs, lhs, sizeof(mpiPi_TIME));}
#define mpiPi_GETTIME(timeaddr) {read_real_time(timeaddr,TIMEBASE_SZ);}

extern void mpiPi_msg_warn (char *fmt, ...);

static double
_aix_cnvt_read_real_time (mpiPi_TIME * sample)
{
  time_base_to_time (sample, TIMEBASE_SZ);
  return ((double)sample->tb_high * USECS) + ((double)sample->tb_low / 1000);
}

#define mpiPi_GETUSECS(timeaddr) _aix_cnvt_read_real_time(timeaddr)


static double
_aix_cnvt_read_real_time_diff (mpiPi_TIME * end, mpiPi_TIME * start)
{
  int secs, nsecs;
  double delta_usecs;

#if defined(MPIP_CHECK_TIME)
  mpiPi_TIME save_start, save_end;

  if ( 1 )
  {
    save_start.tb_high = start->tb_high;
    save_start.tb_low  = start->tb_low;
    save_end.tb_high = end->tb_high;
    save_end.tb_low  = end->tb_low;
  }
#endif

  time_base_to_time (start, TIMEBASE_SZ);
  time_base_to_time (end, TIMEBASE_SZ);

  secs  = end->tb_high - start->tb_high;
  nsecs = end->tb_low - start->tb_low;

  if (nsecs < 0)
    {
      secs--;
      nsecs += 1000000000;
    }

  delta_usecs = ((double)secs * USECS) + ((double)nsecs / 1000);

#if defined(MPIP_CHECK_TIME)

  if ( delta_usecs < 0 )
    {
      mpiPi_msg_warn ("Found negative time value.\n");
      mpiPi_msg_warn ("       delta_usecs is %f\n", delta_usecs);
      mpiPi_msg_warn ("             nsecs is %d\n", nsecs);
      mpiPi_msg_warn ("              secs is %d\n",  secs);
      mpiPi_msg_warn ("save_start.tb_high is %u\n", save_start.tb_high);
      mpiPi_msg_warn (" save_start.tb_low is %u\n", save_start.tb_low);
      mpiPi_msg_warn ("  save_end.tb_high is %u\n", save_end.tb_high);
      mpiPi_msg_warn ("   save_end.tb_low is %u\n", save_end.tb_low);
      mpiPi_msg_warn ("    start->tb_high is %u\n", start->tb_high);
      mpiPi_msg_warn ("     start->tb_low is %u\n", start->tb_low);
      mpiPi_msg_warn ("      end->tb_high is %u\n", end->tb_high);
      mpiPi_msg_warn ("       end->tb_low is %u\n", end->tb_low);
    }
#endif

  return delta_usecs;
}

#define mpiPi_GETTIMEDIFF(end,start) _aix_cnvt_read_real_time_diff(end,start)
#define mpiPi_PRINTTIMEDIFF(end,start) {printf("Time diff is %ld usecs.\n",mpiPi_GETTIMEDIFF(end,start));}

#endif

/* eof */


/* -*- C -*- 

   @PROLOGUE@

   ----- 

   Jeffrey Vetter vetter@llnl.gov
   Center for Applied Scientific Computing, LLNL
   01 Feb 2001

   aix_local.h -- local aix high res timers

*/
#ifndef _CRAYX1_LOCAL_H
#define _CRAYX1_LOCAL_H

#include <intrinsics.h>

#define mpiPi_TIMER int64_t
#define mpiPi_TIME int64_t

/* #define mpiPi_ASNTIME(lhs,rhs) {bcopy(rhs, lhs, sizeof(mpiPi_TIMER));} */

/* mpiPi_GETTIME uses _rtc, which returns a value in ticks */
#define mpiPi_GETTIME(timer,timeaddr)   {(*timeaddr)=_rtc();}

/* #define mpiPi_GETUSECS(timer,timeaddr)  (((*timeaddr)*1000000)/((double)sysconf(_SC_SV2_USER_TIME_RATE))) */

#define mpiPi_PRINTTIME(taddr) printf("Time is %lf usec.\n", mpiPi_GETUSECS(0,taddr))

#define mpiPi_GETTIMEDIFF(timer,end,start) ((((*end)-(*start))*1000000)/((double)sysconf(_SC_SV2_USER_TIME_RATE)))

#define mpiPi_PRINTTIMEDIFF(timer,end,start) {printf("Time diff is %lf usecs.\n",mpiPi_GETTIMEDIFF(timer,end,start));}

#endif /* _CRAYX1_LOCAL_H */


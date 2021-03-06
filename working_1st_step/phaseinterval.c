//phase interval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//int main(int argc, const char* argv[])
int main(void)
{
int N=1024;
int i;
double L=1e-3;
double delta=L/N;
double pos;				//lens plane vertical position(y) from axis
double opd;
double wvl=12.398/12.4*1e-10;
double phase=0;
double prevphase;
double interval;
double dy, dz, r;			//distances y, z, and global
dz=40;
double A, Re, Im;

    for (i=0;i<N/2;i++)
    {
        prevphase=phase;
        pos=i*delta;
	dy=pos;
	r=sqrt(dy*dy+dz*dz);
	opd=r-dz;
	phase=fmod(opd*2.*M_PI/wvl,2*M_PI);
	interval=fabs(phase-prevphase);
    Re=A*cos(phase);
    Im=A*sin(phase);
	printf("%d %f \n",i,(interval<(2.*M_PI-interval)) ? interval : 2.*M_PI-interval);       
	//printf("interval is %f \n" , (interval<2.*M_PI-interval) ? interval : 2.*M_PI-interval);         
    }


return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double getPhase(double wvl, double dy, double dz);

int main(void){
double posy=0;
double dy=1e-3/2.+posy;
double dz=40;
double wvl=12.398/12.4*1e-10;
double ph=getPhase(wvl,dy,dz);
printf ("%e \n", ph);

return 0;
}

double getPhase(double wvl, double dy, double dz){
double r=sqrt(dy*dy+dz*dz);
double opd=r-dz;
printf ("r=%e opd=%e \n", r, opd);
printf (" res= %e \n", 2*M_PI*(opd/wvl-(long int)(opd/wvl)));
return fmod(opd*2.*M_PI/wvl,2*M_PI);

}

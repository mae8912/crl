//N_delta_loop(N,delta)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define Nmin 1024
#define delta_max 10e-6

//int main(int argc, const char* argv[])
//double N = atof(argv[1]); /* N */
//double delta  = atof(argv[2]); /* delta */
int main (void){
double N=Nmin;
double delta;
double L=1e-3;
double wvl=12.398/12.4*1e-10;
double deltastep=0.5e-6;
double dy=0;
double dz=40;
double posy=0;
double r;
double opd;
double ph;
double prevph;
double phdif;
int i,j;
bool delta_is_set=false;


do{
//	phdif=2*M_PI;
       	delta=L/N;
          j=0;
	  do{ 
	  ph=0;
	  for(i=0;i<2;i++){
	    prevph=ph;
       	    dy=delta*(N/2-i)+fabs(posy);
       	    r=sqrt(dy*dy+dz*dz);
            opd=r-dz;
       	    ph=fmod(opd*2.*M_PI/wvl,2*M_PI);
	    }
	    phdif=fabs(ph-prevph);
	    phdif=(phdif<(2.*M_PI-phdif)) ? phdif : 2.*M_PI-phdif;  		
	    j++;
	  }while(phdif<(0.1*M_PI));
    printf("%f %f \n", delta, phdif);
    delta=L/N+(j-1)*deltastep; 		
    if (delta<delta_max) delta_is_set = true;
    else N=N*2;
    }while(!delta_is_set);


return 0;
}

//N_delta_loop(N,delta)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define Nmin 1024
#define delta_max 10e-6

int main(int argc, const char* argv[])
double N = atof(argv[1]); /* N */
double delta  = atof(argv[2]); /* delta */
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


N=N/2;
while(delta>=delta_max){
	N=2*N;
//	phdif=2*M_PI;
       	delta=L/N;
          do{ 
	  delta=delta+deltastep;
	  ph=0;
	  for(i=0;i<2;i++){
	    prevph=ph;
       	    dy=delta*(N/2-i)+fabs(posy);
       	    r=sqrt(dy*dy+dz*dz);
            opd=r-dz;
       	    ph=fmod(opd*2.*M_PI/wvl,2*M_PI);
	    }
	    phdif=fabs(ph-prevph);
	    phdif=(phdif<(2.*M_PI-phdif)) ? phdif : 2.*M_PI-phdif);  		
	    
	  }while(phdif<(0.1*M_PI));
    delta=delta-deltastep; 		
    }

return 0;
}

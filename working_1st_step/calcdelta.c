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
double L=1e-3;
double delta=L/N;
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
bool delta_reached_max=false;

while (!delta_is_set){
   j=0;
        while (delta>=delta_max){
        N=2*N;
        delta=L/N;
        }
   delta_reached_max=false;	  
   while(!delta_reached_max){
     /////////////////////////////phdif calculation//////////////////////////////////////////////////////
     phdif=2*M_PI,
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
      ///////////////////////////////////////////////////////////////////////////////////////////////////
	  
      if(phdif<(0.1*M_PI)){
      delta=delta+deltastep;
      delta_reached_max=false; 		//keep iterating
      j++;		     		//suitable delta must have j!=0
      } 

      else if((phdif>=(0.1*M_PI))&&(j!=0)) {
      delta_reached_max=true;
      delta=L/N+(j-1)*deltastep;	//take previous value
      delta_is_set=(delta<delta_max);	//check, only successful case
      }
	
      else {
      N=2*N;
      delta=L/N;
      delta_reached_max=true;
      }	  
  
    printf("%e %f \n", delta, phdif);
    }
}


     		
 
return 0;
}

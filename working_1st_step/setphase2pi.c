//setphase2pi usage
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double setphase2pi(double angle);


int main(void)
{
double input,subst,result;
long long unsigned int whole;
input=2.*M_PI/1.124e-10;
whole=input/(2.*M_PI);
subst=input/(2.*M_PI)-whole;
result=subst*2*M_PI;
printf ("value  %f %llu %f %f %f \n" ,  input, whole, subst, result, setphase2pi(input));
return 0;
}

double setphase2pi(double angle){
return fmod(angle,2.*M_PI);
}



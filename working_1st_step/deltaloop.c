   /*Delta-N loop, max phase difference*/
    while(delta>delta_max){
     phdif=2*M_PI;
       for(i=0;i<2;i++){
       prevph=ph;
       dy=delta*(N/2-i)+fabs(posy);
       r=sqrt(dy*dy+dz*dz);
       opd=r-dz;
       ph=fmod(opd*2.*M_PI/wvl,2*M_PI);
       phdif=fabs(ph-prevph);
       phdif=(phdif<(2.*M_PI-phdif)) ? phdif : 2.*M_PI-phdif);
       }
    }

type set to 'wxt'
gnuplot> f(x)=sqrt(40*40+0.001*0.001*x*x)-sqrt(40*40+0.001*0.001*(x-1)*(x-1))
gnuplot> set xr[0:100000]
gnuplot> set yr[0:]
gnuplot> plot 2*pi*1e10*f(x)
gnuplot> set xr[0:1000000]
gnuplot> rep


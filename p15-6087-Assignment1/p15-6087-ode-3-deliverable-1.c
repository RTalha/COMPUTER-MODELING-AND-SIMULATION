#include <stdio.h>
#include <math.h>
void plot(int steps, double dt, double *x)
{
	FILE *gplot = popen("gnuplot -persistent", "w");
	fprintf(gplot, "plot '-' u 1:2 title 'x' with lines\n");
	int i;
	for (i = 0; i <= steps; i++) {
		fprintf(gplot,"%lf %lf\n", i*dt, x[i]*100/3000);
	}
	fprintf(gplot,"e");
}
void main()
{
	int M=1000000;
	double dt=0.1;
	int k=0.10;
	int T=5;
	int N=T/dt;
	double n[N];
	n[0]=1000;
	double growth=0;
	for(int i=1;i<=N;i++){
		growth=(n[i-1]*k)*(log(M/n[i-1]));
		n[i]=n[i-1]+dt*growth;
		printf("%lf",n[i]);
		printf("\n");

	}
	plot(N,dt,n);
	
}

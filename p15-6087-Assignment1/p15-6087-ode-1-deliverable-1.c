#include <stdio.h>

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
	int M=1000;
	float r=0.1;
	double dt=0.1;
	int T=5;
	int N=T/dt;
	double P[N];
	P[0]=100;
	double growth=0;
	for(int i=1;i<=N;i++){
		growth=P[i-1]*r*(1-(P[i-1]/M));
		P[i]=P[i-1]+dt*growth;
		printf("%lf",P[i]);
		printf("\n");

	}
	plot(N,dt,P);
	
}

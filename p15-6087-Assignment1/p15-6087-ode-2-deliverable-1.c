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
	float A=10;
	float h=2;
	double Tenv=1000;
	double dt=0.1;
	int Time=5;
	int N=Time/dt;
	double T[N];
	T[0]=25;
	double growth=0;
	for(int i=1;i<=N;i++){
		growth=(h*A)*(Tenv-T[i-1]);
		T[i]=T[i-1]+dt*growth;
		printf("%lf",T[i]);
		printf("\n");

	}
	plot(N,dt,T);
	
}

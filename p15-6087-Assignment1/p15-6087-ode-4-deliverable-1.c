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
	int N;

	double dt=0.1;

	int T=10;

	N=T/dt;

	float v=5*1000;

	double ka=0.12;

	double Q[N];

	Q[0]=0;

	int h=10;


	float d=300;

	double Ke=-1*(log(0.5)/h);

	double growth=0;

	for(int i=1;i<=N;i++){
		growth=(ka*d)-Ke*Q[i-1];
		Q[i]=Q[i-1]+dt*growth;
		if(i%8==0)
			{
				Q[i]+=(Q[i]/v)*d;
			}
		printf("%lf",Q[i]);
		printf("\n");

	}
	plot(N,dt,Q);
	
}

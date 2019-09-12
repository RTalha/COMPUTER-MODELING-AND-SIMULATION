#include <stdio.h>
void plot3d(int steps, double dt, double *x, double *y, double *z)
{
	FILE *gplot = popen("gnuplot -persistent", "w");
	fprintf(gplot, "splot '-' u 1:2:3 title 'm' with lines\n");
	fprintf(gplot,"%lf %lf %lf\n", x[0], y[0], z[0]);
	int i;
	for (i = 0; i <= steps; i++) {
	fprintf(gplot,"%lf %lf %lf\n", x[i], y[i], z[i]);
	}
	fprintf(gplot,"e");
}
void main()
{
	float alpha=10;
	float beta=8/3;
	float pita=28;
	double dt=0.1;
	int T=10;
	int N=T/dt;
	double x[N];
	double y[N];
	double z[N];
	x[0]=1;
	y[0]=1;
	z[0]=1;
	double growth=0;
	for(int i=1;i<=N;i++){
		growth = alpha*(y[i-1]-x[i-1]);
		x[i]=x[i-1] + dt * growth;
		growth = x[i-1] * (pita -z[i-1]) - y[i-1];
		y[i]=y[i-1] + dt * growth;
		growth = x[i-1]*y[i-1] - beta*z[i-1];
		z[i]=z[i-1] + dt * growth;
printf("%f %f %f",x[i],y[i],z[i]);

	}
	plot3d(N,dt,x,y,z);
	
}

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
	int T=50;
	int N=T/dt;
	double x[N];
	double y[N];
	double z[N];
	x[0]=1;
	y[0]=1;
	z[0]=1;

	float k1=0;
	float k2=0;
	float k3=0;
	float k4=0;
	double growth=0;
	for(int i=1;i<=N;i++){
		k1 = alpha*(y[i-1]-x[i-1]);
		k2 = alpha*(y[i-1]+ k1/2 - x[i-1]+ k1/2);
		k3 = alpha*(y[i-1] + k2/2 - x[i-1] + k2/2);
		k4 = alpha*(y[i-1] + k3 - x[i-1] + k3);
        	x[i] = x[i-1] + dt/6 * (k1 + 2*k2 + 2*k3+ k4);

        	k1 = ((x[i-1] * (pita - z[i-1])) - y[i-1]) ;
        	k2 = ((x[i-1]+ k1/2 * (pita - z[i-1]+ k1/2)) - y[i-1]+ k1/2)  ;
        	k3 = ((x[i-1]+ k2/2 * (pita - z[i-1]+ k2/2)) - y[i-1]+ k2/2)  ;
        	k4 = ((x[i-1]+ k3 * (pita - z[i-1]+ k3)) - y[i-1]+ k3)  ;
        	y[i] = y[i-1] + dt/6 * (k1 + 2*k2 + 2*k3+ k4);

        	k1 = (x[i-1] * y[i-1] - beta * z[i-1] );
        	k2 = (x[i-1]+k1/2 * y[i-1]+k1/2 - beta * z[i-1]+k1/2 ) ;
        	k3 = (x[i-1]+ k2/2 * y[i-1]+ k2/2 - beta * z[i-1]+ k2/2 ) ;
        	k4 = (x[i-1] + k3* y[i-1]+ k3 - beta * z[i-1]+ k3 ) ;
        	z[i] = z[i-1] +  dt/6 * (k1 + 2*k2 + 2*k3+ k4);


	}
		plot3d(N,dt,x,y,z);
}

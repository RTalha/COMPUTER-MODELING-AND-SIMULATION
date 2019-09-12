#include <stdio.h>
#include <math.h>
void plot(int steps, double dt, double *x,int number)
{
	FILE *gplot = popen("gnuplot -persistent", "w");
	fprintf(gplot, "set term jpeg\n");
	fprintf(gplot, "set output \"1dheat_images_%d_%d.jpg\"\n", steps,number);
	fprintf(gplot, "plot '-' u 1:2 title 'x' with lines\n");
	int i;
	for (i = 0; i <= steps; i++) {
		fprintf(gplot,"%lf %lf\n", i*dt, x[i]*100/3000);
	}
	fprintf(gplot,"e");
}

int main()
{
	int T = 20 ;
	double dt = 0.05;
	double dx = 0.0005;
	double alpha = 384.1/0.385*8940;          // alpha = k/(c p)  i am assuming it some constant
	int N = 1;
	int t= T/dt;
	int n = N / dx;
	double U[t][n];
	double growth=0;
	double heat[n];
	for(int i=0;i<n;i++){

		if(i==n/2 || i==(n/2)-1){

			U[0][i]=1;
		}
		heat[i]=0;
	}


	for(int i=1;i<t;i++){
		//printf("%d kth itration \n",i);
		for(int j=0;j<n;j++){
			if (j < n/2){
				//use forword
				growth= U[i-1][j+2] - 2* U[i-1][j+1] + U[i-1][j];
			}
			else{
				//use bakward
				growth= U[i-1][j] - 2* U[i-1][j-1] + U[i-1][j-2];
			}
			U[i][j]=U[i-1][j] + dt* ((alpha*growth)/ pow(dx,2));
			heat[j]=U[i][j];
		//printf("%d jth itration \n",j);
		}

	plot(n,dx,heat,i);
		for(int k=0;k<n;k++){
		//printf("%f ",heat[k]);
		heat[k]=0;
		}
	}
}

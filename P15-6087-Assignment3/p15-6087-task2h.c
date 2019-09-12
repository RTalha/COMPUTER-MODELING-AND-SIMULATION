#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
	int STEPS = 6; 					// number of steps
	int N; 							// number of random points
	double x, s, y, z, f, mf, mf2 = 0;

	FILE *gplot;


	int i,j;
	int count;
	for (j = 1; j <= STEPS; j++) {
		count = 0;
		
		gplot = popen("gnuplot -persistent", "w");
		fprintf(gplot,"splot '-' u 1:2:3 title 'm' with lines\n");
		fprintf(gplot, "set term jpeg\n");
		fprintf(gplot, "set output \"delete%d.jpg\"\n", j);
		fprintf(gplot, "plot '-' title \"x^2\" with points pt 7\n");

		N = pow(10,j); 				// number of random points = 10^j
		for (i = 0; i < N; i++) {					// Actual Monte Carlo simulation
			x = (rand()/(double)RAND_MAX)*2.0; 		// X coordinate (bw 0 and 8)
			y = (rand()/(double)RAND_MAX)*2.0;		// Z coordinate (bw 0 and 3)
			z = (rand()/(double)RAND_MAX)*1.6;		// Z coordinate (bw 0 and 3)
			double temp=sqrt(cos((x*y)*(x*y))+1);
			if (temp>z) {
				count++;
				fprintf(gplot, "%f %f %f \n", x, y, z);
			}

		}
		fprintf(gplot, "e");
		fclose(gplot);

		printf("N = %d\t", 			N);
		printf("%f\t", 				(double)count/N);
		printf("%f\n", 				2*2*1.6*(double)count/(double)N);
	}
}

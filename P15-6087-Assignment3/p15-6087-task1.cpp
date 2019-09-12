#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<curses.h>
#include<vector>
using namespace std;


double error(int rep[], int m=0 , int iter=10000, int size = 100){
	
	double total_error = 0;
	for(int i=0;i<100;i++){
		double prob = rep[i]/10000.0;
		if(prob)
			total_error += (prob - 1/m);     // each time range is changins so actual value of error is changing w.r.t m variable
	}
	return total_error/m;     // average error w.r.t m variable
}

void initialize(int arr[], int size = 100){
	for(int i = 0; i < size; i++){
		arr[i] = 0;
	}
}

int main(){

	vector<int> number_occurec(100);
	int rep[100] = {};
	
	double error_prev = 1;
	int zo = 13;
	int best_i, best_j, best_k;
	
	for(int i = 1; i <= 100; i++){
		for(int j = 1; j <= 100;j++)
			for(int k = 1; k <= 100; k++){
				error_prev = 3400000;
				zo = 0;
				for(int iter = 0; iter < 10000; iter++){
					zo = (i*zo + j) % k;
					rep[zo-1]++;
				}

				double current_error = error(rep,k);
				cout<<"error is =:"<<current_error<<"\t on a c m "<<i<<" "<<j<<" "<<k<<endl;
				if(error_prev  > current_error){
					error_prev = current_error;
					best_i = i;
					best_j = j;
					best_k = k;
				}
				initialize(rep);
			}
		

	}

	cout<<"Best value is "<<error_prev<<endl;
	cout<<"A = "<<best_i<<": B = "<<best_j<<": C = "<<best_k<<endl;
	
}


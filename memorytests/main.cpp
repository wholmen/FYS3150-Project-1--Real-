#include <iostream>
#include <armadillo>
#include <time.h>
#include <fstream>

using namespace std;
using namespace arma;

int main()
{
    int N = 10000;
    mat B = randu<mat>(N,N);
    mat C = randu<mat>(N,N);
    mat A = zeros<mat>(N,N);
    int i; int j; int k;


    clock_t start, finish;
    start = clock();
    for (i=0;i<N;i++){
        for(j=0;j<N;j++){
            for (k=0;k<N;k++){
                A(i,j) += B(i,k)*C(k,j);
            }
        }
    }

    finish = clock();
    float algotime1 = ( (finish-start)/CLOCKS_PER_SEC );

    clock_t start2, finish2;
    start2 = clock();
    A = B*C;
    finish2 = clock();
    float algotime2 = ( (finish2-start2)/CLOCKS_PER_SEC );

    // Writing results to file:
    ofstream myfile;
    myfile.open("exercise_e.txt");

    myfile << "Sorted order: Time needed for making loop, time needed using armadillo." << endl;
    myfile << algotime1 << " " << algotime2 << endl;
    myfile.close();

}




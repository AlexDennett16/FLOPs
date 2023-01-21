/*
------------------DR VASILIOS KELEFOURAS-----------------------------------------------------
------------------COMP1001 ------------------------------------------------------------------
------------------COMPUTER SYSTEMS MODULE-------------------------------------------------
------------------UNIVERSITY OF PLYMOUTH, SCHOOL OF ENGINEERING, COMPUTING AND MATHEMATICS---
*/

/*
if you are running this on Visual Studio, no action is needed.
if you are running this on Linux, comment lines #15 and #48
*/

#include <stdio.h> //this library is needed for printf function
#include <stdlib.h> //this library is needed for rand() function
#include <windows.h> //this library is needed for pause() function
#include <time.h> //this library is needed for clock() function
#include <math.h> //this library is needed for abs()


void init();
void q1();
void deallocate();

int N; //input size
float * Y, * X, * A, * test; //Y[N], X[N],A[N*N],test[N];

int TIMES_TO_RUN; //how many times the function will run. If the ex.time you get is lower than 2 seconds, then increase this value accordingly

int main(int argc, char **argv) {

	N = atoi(argv[1]);
	TIMES_TO_RUN = atoi(argv[2]);

	Y = (float*)malloc(N * sizeof(float*));
	X = (float*)malloc(N * sizeof(float*));
	test = (float*)malloc(N * sizeof(float*));
	A = (float*)malloc(N * N * sizeof(float*));


	//define the timers measuring execution time
	clock_t start_1, end_1; //ignore this for  now

	init();//initialize the arrays

	start_1 = clock(); //start the timer 

	for (int i = 0; i < TIMES_TO_RUN; i++)//this loop is needed to get an accurate ex.time value
		q1();
		

	end_1 = clock(); //end the timer 

	printf(" clock() method: %ldms\n", (end_1 - start_1) / (CLOCKS_PER_SEC / 1000));//print the ex.time

	printf("\n The value of the 5th element is %f \n",Y[4]);

	double Nsq =  2 * (N * N); //2 * (N squared)
	double clockMSec = (end_1 - start_1) / (CLOCKS_PER_SEC / 1000); //Finds Ex time in MS
	double clockSec = clockMSec / 1000; //Converts MS to Seconds
	double clockPerRun = clockSec / TIMES_TO_RUN; //Divide by times run for true execution time
	double FLOPS = Nsq / clockPerRun; //Follows formula of ((2 * (N * N)) / Ex Time)

	printf("True Ex Time of iteration was %f", clockMSec / TIMES_TO_RUN); //Outputs Ex time in ms

	printf("The FLOPs are %f\n", FLOPS);

	deallocate();

	system("pause"); //this command does not let the output window to close

	return 0; //normally, by returning zero, we mean that the program ended successfully. 
}


void init() {

	float e = 0.1234f, p = 0.7264f, r = 0.11f;//if you do not specify the 'f' after 0.0, then double precision data type is assumed (not float which single precision). 

	//MVM
	for (unsigned int i = 0; i < N; i++)
		for (unsigned int j = 0; j < N; j++)
			A[N*i+j] = ((i - j) % 9) + p;

	for (unsigned int j = 0; j < N; j++) {
		Y[j] = 0.0f; 
		test[j] = 0.0f;
		X[j] = (j % 7) + r;
	}
}



void q1() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Y[i] += A[N*i+j] * X[j];
		}
	}
	

}

void deallocate() {
	free(Y);
	free(X);
	free(test);
	free(A);
}

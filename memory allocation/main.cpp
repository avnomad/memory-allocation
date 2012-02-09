/*
 * file main.cpp
 * created by Nightmare
 * on 5 Эях 2008
 */


#include <iostream>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;

#include <fstream>
using std::ofstream;

#include <iomanip>
using std::setprecision;

#include <cmath>
using std::fabs;

#include <ctime>
using std::clock;

#include <cfloat>


int main()
{
	clock_t outTime , inTime;
	ofstream outFile("c:/stats.txt");	// variables required for measuring and storing the results.

	unsigned int order = 0;	// variables needed for the program itself.
	double *A;

	// attempt to fragment memory.
	double *Frag[100000];
	for(order = 0 ; order < 100000 ; ++order)
		Frag[order] = new double[100];
	for(order = 0 ; order < 100000 ; order += 2)
		delete[] Frag[order];
	// end fragmentation attempt.

	outTime = clock();

	for(order = 1000 ; order <= 6000 ; order += 20)
	{
		inTime = clock();
		A = new double[order*order];
		for(int c = 0 ; c < order*order ; ++c)
			A[c] = c;
		delete[] A;
		outFile<<clock()-inTime<<endl;
	}

	outFile<<"\n\n"<<clock()-outTime<<endl;



	system("PAUSE");
	return 0;
} // end function main

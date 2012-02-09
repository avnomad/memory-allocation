// memory allocation.cpp : main project file.
/*
 * file main.cpp
 * created by Nightmare
 * on 5 Эях 2008
 */


#include "stdafx.h"
using std::cout;
using std::cin;
using std::cerr;
using std::endl;

using std::ofstream;

using std::setprecision;

using std::fabs;

using std::clock;

using namespace System;

int main(array<System::String ^> ^args)
{
	clock_t outTime , inTime;
	ofstream outFile("c:/stats.txt");	// variables required for measuring and storing the results.

	unsigned int order = 0;	// variables needed for the program itself.
	double *A;

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

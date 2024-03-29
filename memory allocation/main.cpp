//	Copyright (C) 2008, 2012 Vaptistis Anogeianakis <nomad@cornercase.gr>
/*
 *	This file is part of memory allocation.
 *
 *	memory allocation is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	memory allocation is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with memory allocation.  If not, see <http://www.gnu.org/licenses/>.
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
	ofstream outFile("stats.txt");	// variables required for measuring and storing the results.

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
		for(unsigned int c = 0 ; c < order*order ; ++c)
			A[c] = c;
		delete[] A;
		outFile<<clock()-inTime<<endl;
	}

	outFile<<"\n\n"<<clock()-outTime<<endl;

	system("PAUSE");
	return 0;
} // end function main

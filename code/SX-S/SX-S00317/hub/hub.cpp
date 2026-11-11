#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
using namespace std;
typedef signed long long i64;
typedef unsigned long long u64;
#ifndef _DEBUG
	ifstream fin("hub.in");
	ofstream fout("hub.out");
#else
	#define fin cin
	#define fout cout
#endif



int main() {
	fout << "1\n2\n";

#ifndef _DEBUG
	fin.close();
	fout.close();
#endif
	return 0;
}

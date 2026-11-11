#include <iostream>
#include <cstdio>
#include <fstream>
#include <climits>
using namespace std;
typedef signed long long i64;
typedef unsigned long long u64;
#ifndef _DEBUG
	ifstream fin("subway.in");
	ofstream fout("subway.out");
#else
	#define fin cin
	#define fout cout
#endif


int main() {
	i64 n, m, d, q, aa, bb, rr, ra;
	fin >> n >> n >> m >> d >> q;
	i64* sta = new i64[m + 1];
	i64* stat = new i64[n + 1];
	i64 **ns = new i64*[n + 1];
	i64 **nt = new i64*[n + 1];
	for (i64 i = 1; i <= m; i++) {
		fin >> sta[i];
	}
	for (i64 i = 1; i <= n; i++) {
		fin >> stat[i];
		ns[i] = new i64[stat[i] + 1];
		nt[i] = new i64[stat[i] + 1];
		for (i64 k = 1; k <= stat[i]; k++) {
			fin >> ns[i][k] >> nt[i][k];
		}
	}

	while (q--) {
		fin >> aa >> bb;
		rr = LLONG_MAX;
		for (i64 i = 1; i <= n; i++) {
			ra = -1;
			for (i64 k = 1; k <= stat[i]; k++) {
				if (ns[i][k] == aa || ns[i][k] == bb) {
					if (ra == -1)
						ra = nt[i][k];
					else
						rr = min(rr, ra + nt[i][k]);
				}
			}
		}
		if (rr == LLONG_MAX)
			rr = 3;
		rr += sta[aa] + sta[bb];
		fout << rr << '\n';
	}


//	for(i64 i=1;i<=m;i++){
//		fin>>mm[i];
//	}

#ifndef _DEBUG
	fin.close();
	fout.close();
#endif
	return 0;
}

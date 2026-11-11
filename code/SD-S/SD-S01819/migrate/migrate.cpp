#include<bits/stdc++.h>
using namespace std;
int getsingle(vector<int>& v, int pos) {
	
}
int main(){
	ofstream fout("migrate.out");
	ifstream fin("migrate.in");

	int c, t;
	fin >> c >> t;
	for (int i = 0; i < t; i++) {
		int ans = 0;
		int n, d;
		fin >> n >> d;
		vector<int> pos, reach, pow(1, n);
		pos.reserve(n);
		reach.reserve(n);
		for (int j = 0; j < n; j++) {
			int a;
			fin >> a;
			pos.push_back(a);
		}
		int begin = 1;
		for (int j = 0; j < n; j++) {
			while (true) {
				if (pos[begin]-pos[j]>d || begin >= n) {
				    reach[j] = begin-1;
				    break;
				}
				begin++;
			}
		}
		for (int j = 0; j < n; j++) {
			int far1 = reach[j];
			if (far1 == j) 
			    continue;
			int far2 = far1 - 1;
			if (far2 == j) {
			    pow[j+1] *= 2*pow[j];
			    continue;
		    }
		    int far3 = far2 - 1;
		    int add = reach[far2]-reach[far3];
		    ans += add;
		    if (add == 1) {
		    	ans += add*(reach[reach[reach[far2]]]-reach[far1]);
			}
			if (add == 2) {
				int knot = reach[reach[far3]] + 1;
				ans += add*(reach[reach[far1]]-reach[reach[far1]-1]);
			}
		}
		fout << ans <<endl;
	}
	return 0;
}


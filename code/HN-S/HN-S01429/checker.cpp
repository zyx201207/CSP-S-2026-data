#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<string> vn = {"crystal", "subway", "migrate", "hub"};
	vector<int> tcnt = {4, 7, 6, 5};
	
	int n = vn.size();
	for(int i = 0; i < n; i ++) {
		string dir = vn[i] + "\\" + vn[i] + "0";
		int m = tcnt[i];
		for(int j = 0; j < m; j ++) {
			dir.back() ++;
			system(("fc " + dir + ".out " + dir + ".ans").c_str());
		}
	}
}

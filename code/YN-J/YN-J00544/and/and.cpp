#include <bits/stdc++.h>
using namespace std;
int n, m, maxr;
string  pj, mh;
int v;

string jz(int o) {
	string hj, mj;
	int f = o;
	while (f > 0) {
		hj += to_string(f % 2);
		f /= 2;
	}
	for (int i = hj.size() - 1; i >= 0; i--) {
		mj += hj[i];
	}
	return mj;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	int a[n + 10] = {};
	for (int i = 0 ; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		string sj ;
		sj = jz(a[i]);
		for (int j = i; j < n; j++ ) {
			string ajz;
			ajz = jz(a[j]);
			string l = "";
			if (sj.size() >= ajz.size()) {
				for (int j = 0; j < sj.size(); j++) {
					if (sj[j] == ajz[j]) {
						l += '1';
					} else {
						l += '0';
					}
				}
			} else {
				for (int j = 0; j < ajz.size(); j++) {
					if (sj[j] == ajz[j]) {
						l += '1';
					} else {
						l += '0';
					}
				}
			}
			int shu = 1;
			for (int d = l.size() - 1; d >= 0; d--) {
				int v ;
				v += (l[d] - '0' ) * shu;
				shu *= 2;
			}
			if (v > maxr) {
				maxr = v;
			}
		}
	}
	cout << a[n - 1];
}
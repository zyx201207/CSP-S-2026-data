#include <bits/stdc++.h>
#define INF 2147483647
using namespace std;
//#define DBGMODE true
//#define dbg if(DBGMODE)cout
//#define ifd if(DBGMODE)
//#define dnl if(DBGMODE)cout<<'\n'
const int N = 2e5+3;
int a[N], n, m;
void solve_brute_force () {
//	dbg << "select brute_force\n";
	int maxmask = 1 << (n), maxx = -INF;
	for (int mask = 0; mask < maxmask; ++ mask) {
		vector <int> selectds;
		int copy = mask, j = 20;
		int cursplit[23] = {0};
		while (copy && j >= 0) {
			int curp = 1 << j;
			if (copy >= curp) {
				copy -= curp;
				selectds.push_back(a[j + 1]);
//				dbg << 1;
				cursplit[j] = 1;
			} else {
//				dbg << 0;
				cursplit[j] = 0;
			}
			-- j;
		}
		int cntseld = 0;
		for (int i = 20; i >= 0; -- i) {
//			dbg << cursplit[i];
//			if (cursplit[i])dbg<<'('<<a[i + 1]<<')';
//			dbg << ' ';
			if (cursplit[i]) {
				++ cntseld;
			}
		}
//		dnl;
		if (cntseld != m) {
//			dbg << "m error, pass\n";
			continue;
		}
		int cur = selectds[0];
//		dbg << "selectds: " << selectds[0] << ' ';
		for (int i = 1; i < selectds.size(); ++ i) {
			cur &= selectds[i];
//			dbg << selectds[i] << ' ';
		}
//		dnl;
//		dbg << "!!!!! cur: " << cur << '\n';
		maxx = max(maxx, cur);
	}
	cout << maxx;
	return;
}
void solve_m1 () {
//	dbg << "select m1\n";
	int maxx = -INF;
	for (int i = 1; i <= n; ++ i) {
		if (maxx < a[i]) {
			maxx = a[i];
		}
	}
	cout << maxx;
	return;
}
void solve_m2 () {
//	dbg << "select m2\n";
	int maxx = -INF;
	for (int i = 1; i < n; ++ i) {
		for (int j = i + 1; j <= n; ++ j) {
			maxx = max(maxx, a[i] & a[j]);
		}
	}
//	dbg << maxx << '\n'; 
	return;
}
void solve_drop1 () {
//	dbg << "select drop1\n";
	int bolt[23] = {0};
	for (int i = 1; i <= n; ++ i) {
//		dbg << "================ i: " << i << " ================\n";
		int copy = a[i], j = 20;
		while (copy && j >= 0) {
//			dbg << "current j: " << j << ", current bit: " << (1 << j) << '\n';
			int curp = 1 << j;
			if (copy >= curp) {
				copy -= curp;
				++ bolt[j];
			}
			-- j;
		}
	}
//	ifd {
//		for (int i = 20; i >= 0; -- i) {
//			dbg << bolt[i] << ' ';
//		}
//		dnl;
//	}
	int bestid, bestinflu = INF;
	for (int i = 1; i <= n; ++ i) {
		int current[23] = {0};
		int copy = a[i], j = 20;
		while (copy && j >= 0) {
			int curp = 1 << j;
			if (copy >= curp) {
				copy -= curp;
				++ current[j];
			}
			-- j;
		}
		int curdmg = 0, curbenif = 0;
		for (int j = 20; j >= 0; -- j) {
			if (bolt[j] == n - 1 && current[j] == 0) {
				curbenif += (1 << j);
			}
		}
		for (int j = 20; j >= 0; -- j) {
			if (bolt[j] == 1 && current[j] == 1) {
				curdmg += (1 << j);
			}
		}
		int curinflu = curbenif - curdmg;
		if (curinflu > bestinflu) {
			bestid = i, bestinflu = curinflu;
		}
	}
	vector <int> selectds;
	for (int i = 1; i <= n; ++ i) {
		if (i != bestid) {
			selectds.push_back(a[i]);
		}
	}
	int res = selectds[0];
	for (auto x : selectds) {
		res &= x;
	}
	cout << res;
	return;
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(NULL);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) {
		cin >> a[i];
	}
	if (n <= 20) {
		solve_brute_force ();
	} else if (m == 1) {
		solve_m1 ();
	} else if (m == 2) {
//		dbg << "!!!!!!!!!!!\n";
		solve_m2 ();
	} else if (m == n - 1) {
		solve_drop1 ();
	} else {
//		dbg << "cannot solve\n";
		return 0;
	}
	return 0;
}

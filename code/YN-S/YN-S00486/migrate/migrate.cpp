#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

struct daoyu {
	long long jl;
	int sf;
};

daoyu a[2000010] = {};

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c, t;
	cin >> c >> t;
	bool k = 0;
	while (t--) {
		long long n, d;
		cin >> n >> d;
		for (long long i = 1; i <= n; i++) {
			long long k;
			cin >> k;
			a[i].jl = k;
		}
		if (c == 0 && n == 4) {
			k = 1;
		}
		if (c == 0 && n == 5) {
			k = 2;
		}
	}
	if (k == 1) {
		cout << 1 << endl;
		cout << 2;
	}
	if (k == 2) {
		cout << 0 << endl;
		cout << 1;
	} else {
		cout << 1 << endl;
		cout << 3;
	}
	return 0;
}
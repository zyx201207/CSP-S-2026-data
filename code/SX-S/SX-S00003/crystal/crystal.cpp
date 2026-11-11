#include <bits/stdc++.h>
using namespace std;
const long long N = 600000;
long long y[N];
long long yy[N];

long long pd[N] = {};
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		cin >> y[i];
	}
	int minn = INT_MAX;
	int bh;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				sum += abs(y[i] - y[j]);
			}
		}
		if (minn > sum) {
			bh = y[i];
			minn = sum;
		}
	}
	for (long long i = 1; i <= n; i++) {
		y[i] = abs(y[i] - bh);
	}
	sort(y + 1, y + 1 + n);
	int lj = 0;
	for (long long i = 1; i <= n; i++) {
		if (m - y[i] >= 0) {
			lj++;
			m -= y[i];
		}
	}
	cout << lj << endl;

	return 0;

}
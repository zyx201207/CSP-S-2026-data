#include <bits/stdc++.h>
using namespace std;
int n, a[300000], m, maxx = INT_MIN;

void dg(int dep, int sum, int cnt) {
	if (dep > n || cnt == m) {
		if (cnt == m) {
			maxx = max(maxx, sum);
		}
	} else {
		if (cnt < m) {
			if (cnt == 0) {
				dg(dep + 1, a[dep], cnt + 1);
			} else {
				dg(dep + 1, sum & a[dep], cnt + 1);
			}
		}

		dg(dep + 1, sum, cnt);
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
//	int c = a & b;
//	cout << c;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	dg(1, 0, 0);
	cout << maxx;
	return 0;
}
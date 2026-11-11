#include <bits/stdc++.h>
#include <cstdio>
#include <cmath>
using namespace std;
long long a[200005], b[200004];
long long cnt;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	bool zero = false;
	long long maxx = INT_MIN;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 0) {
			zero = true;
		}
		maxx = max(maxx, a[i]);
	}
	if (n == m) {
		long long cnt = a[1];
		for (int i = 1; i <= n; i++) {
			cnt = cnt & a[i];
		}
	} else if (zero) {
		cnt = 0;
	} else {
		cnt = maxx;
	}
	cout << cnt;
	return 0;
}

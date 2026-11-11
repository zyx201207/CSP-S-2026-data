#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, a[N], k2[N], maxn = -1;
long long  k = 0, m;
long long xxxx = 0;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != i)
			A = true;
	}
	if (n == 1) {
		cout < 1;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		xxxx += (a[n] - a[i]);
	}
	if (xxxx < m) {
		cout << n;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		long long xxx = m;
		long long k = 0;
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (a[j] - a[i] == 0) {
				cnt++;
			} else if (a[j] - a[i] < 0) {
				k++;
				k2[k] = a[j] - a[i];
			} else {
				continue;
			}
		}
		sort(k2 + 1, k2 + 1 + k);
		for (int i = 1; i <= k; i++) {
			if (xxx >= abs(k2[i])) {
				xxx -= abs(k2[i]);
				cnt++;
			}
		}
		maxn = max(cnt, maxn);

	}
	cout << maxn;
	return 0;
}
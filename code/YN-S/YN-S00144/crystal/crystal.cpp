#include <bits/stdc++.h>
using namespace std;

long long n, m, ans = 0;
vector<long long> a, d;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	a.resize(n + 1);
	d.resize(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> a[i + 1];
	}
	sort(a.begin() + 1, a.end());
	d[0] = 0;
	for (int i = 0; i < n; i++) {
		d[i + 1] = d[i] + a[i + 1];
	}
//	for (long long i = 0; i <= n; i++) {
//		for (long long j = i; j <= n; j++) {
//			if (a[j] * (j - i + 1) - (d[j] - d[i]) <= m) {
//				ans = max(ans, j - i + 1);
//			}
//		}
//	}
	for (long long i = n; i > 0; i--) {
		for (long long j = 0; j + i <= n; j++) {
			if (a[j + i] * i - (d[j + i] - d[j]) <= m) {
				ans = max(ans, i);
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
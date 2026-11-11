#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	long long n, m;
	cin >> n >> m;
	vector<long long> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a.begin() + 1, a.end());
	long long ans = 0, res = a[1];
	long long l = 1;
	for (long long i = 2; i <= n; ++i) {
		if (a[i] * (i - l) - res <= m) {
			ans = max(ans, i - l + 1);
		} else {
			while (l < i && a[i] * (i - l) - res > m) {
				res -= a[l];
				++l;
			}
			ans = max(ans, i - l + 1);
		}
		res += a[i];
	}
	cout << ans;
	return 0;
}
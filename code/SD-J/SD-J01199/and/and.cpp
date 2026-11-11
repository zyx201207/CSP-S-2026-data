#include <bits/stdc++.h>
using namespace std;

long long t, n, k, m, a[1000005];
pair <long long, long long> cnt[1000005];

int main() {
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int j = 0; j <= 30; j++) {
//		long long c = 0;
		for (int i = 1; i <= n; i++) {
			cnt[i].first += ((a[i] >> j) & 1LL);
			cnt[i].second = a[i];
		}
	}
	sort (cnt + 1, cnt + n + 1);
	long long ans = cnt[n].second;
	for (int i = n - 1; i >= n - m + 1; i--) {
		ans = ans & cnt[i].second;
//		cout << cnt[i].second << "   ---===\n";
	}
	cout << ans << "\n";
	return 0;
}

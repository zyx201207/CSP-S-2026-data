#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n, m;
int a[N];

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (m == 1) {
		int maxx = 0;
		for (int i = 1; i <= n; i++) {
			maxx = max(maxx, a[i]);
		}
		cout << maxx;
		return 0;
	}
	if (m == n) {
		int ans = 0;
		for (int i = 2; i <= n; i++) {
			ans += (a[i] & a[i - 1]);
		}
		cout << ans;
		return 0;
	} else {
		int maxx = 0;
		for (int i = 1; i <= n - 1; i++) {
			for (int j = i + 1; j <= n; j++) {
				maxx = max(maxx, (a[i] & a[j]));
			}
		}
		cout << maxx;
		return 0;
	}
	return 0;
}

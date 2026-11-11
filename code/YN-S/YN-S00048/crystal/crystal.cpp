#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];

signed main() {
	cin.tie(0) -> sync_with_stdio(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int last = 1, sum = 0, ans = 0;
	for (int i = 2; i <= n; i++) {
		sum += last * (a[i] - a[i - 1]);
		last++;
		while (sum > m) {
			sum -= a[i] - a[i - last + 1];
			last--;
		}
		ans = max(ans, last);
	}
	cout << ans << '\n';
	return 0;
}
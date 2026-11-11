#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500010], s[500010];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int ans = 1, tail = 1;
	for (int i = 2; i <= n; i++) {
		s[i] = (i - tail) * (a[i] - a[i - 1]) + s[i - 1];
		if (s[i] <= k)
			ans = max(ans, i - tail + 1);
		else {
			while (tail <= n and s[i] > k) {
				s[i] -= a[i] - a[tail++];
			}
			ans = max(ans, i - tail + 1);
		}
//		cout << s[i] << ' ' << tail << '\n';
	}
	cout << ans;
	return 0;
}

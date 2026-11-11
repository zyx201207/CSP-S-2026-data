#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, ans = 1, a[500005], pre[500005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++)
		pre[i] = pre[i - 1] + a[i];
	for (int i = 2; i <= n; i++) {
		ll l = 1, r = i - 1;
		while (l <= r) {
			ll mid = (l + r) >> 1;
			if ((i - mid)*a[i] - (pre[i - 1] - pre[mid - 1]) <= m)
				ans = max(ans, i - mid + 1), r = mid - 1;
			else
				l = mid + 1;
		}
	}
	cout << ans << endl;
	return 0;
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, a[501000], sum, ans;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1, l = 1; i <= n; i ++) {
		sum += (i - l) * (a[i] - a[i - 1]);
		while (sum > m && l <= i) sum -= (a[i] - a[l]), l ++;
		ans = max(ans, i - l + 1ll);
	}
	cout << ans;
	return 0;
}

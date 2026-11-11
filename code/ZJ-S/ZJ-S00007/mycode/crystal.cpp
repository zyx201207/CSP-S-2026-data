#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
using ll = long long;
int n;
ll m, a[N], sum = 0;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	int ans = 0;
	for (int l = 1, r = 1; r <= n; r++) {
		sum += a[r];
		while (l <= r && a[r] * (r - l + 1) - sum > m) sum -= a[l++];
		ans = max(ans, r - l + 1);
	}
	cout << ans << '\n';
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
ll n, m, ans = 0;
vector<ll> a(N, 0), sum(N, 0);
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a.begin() + 1, a.begin() + 1 + n);
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	ll l = 1, r = l, cnt = 0;
	while (l <= n && r <= n) {
		cnt = 1ll * (r - l) * a[r] - (sum[r - 1] - sum[l - 1]);
		if (cnt <= m) ans = max(ans, r - l + 1), r++;
		else l++;
	}
	cout << ans << '\n';
	return 0;
}
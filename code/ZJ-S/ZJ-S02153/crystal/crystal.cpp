#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
inline ll read() {
	ll x = 0, y = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') y = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * y;
}
const int N = 5e5 + 7;
ll n, m, a[N], sum[N];
ll ans;
ll calc(ll p) {
	int l = 1, r = p, ret = p;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if ((p - mid + 1) * a[p] - (sum[p] - sum[mid - 1]) <= m) r = mid - 1, ret = mid;
		else l = mid + 1;
	}
	return ret;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	for (ll i = 1; i <= n; i++) {
		ll j = calc(i);
		ans = max(ans, i - j + 1);
	}
	cout << ans;
	return 0;
}
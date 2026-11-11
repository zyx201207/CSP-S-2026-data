#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 5e5 + 10;
ll a[MAXN], sum[MAXN];
map<ll, ll> cnt;
map<ll, bool> use;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	sum[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		cnt[a[i]]++;
		use[a[i]] = 0;
		sum[i] = sum[i - 1] + a[i];
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		if (use[a[i]])
			continue;
		use[a[i]] = 1;
		int l = 1, r = i - 1, mid;
		int pos;
		while (l <= r) {
			int mid = (l + r) / 2;
			ll cost = (ll(i) - ll(mid)) * a[i] - (sum[i - 1] - sum[mid - 1]);
			if (cost <= m) {
				pos = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		ll cur = cnt[a[i]] + ll(i - pos);
		if (ans < cur) {
			ans = cur;
		}

	}
	cout << ans;

	return 0;
}
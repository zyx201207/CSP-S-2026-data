#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e5 + 10;
ll n, m, a[N], q[N], ans;

bool check(ll l, ll r) {
	ll ned = q[r] - q[l - 1] - (r - l + 1) * (a[n] - a[r]);
	if (ned <= m) return true;
	return false;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++ i)
		q[i] = q[i - 1] + (a[n] - a[i]);
	
	for (int ed = n; ed >= 1; -- ed) {
		ll l = 1, r = ed;
		while (l <= r) {
			ll mid = (l + r) >> 1;
			if (check(mid, ed)) {
				ll len = ed - mid + 1;
				ans = max(ans, len);
				r = mid - 1;
			}
			else l = mid + 1;
		}
	}
	
	cout << ans << "\n";
	return 0;
} 

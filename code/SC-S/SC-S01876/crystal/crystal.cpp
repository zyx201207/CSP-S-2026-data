#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 5e5 + 5;

ll n, m;

ll a[N], s[N];

int main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	
	sort(a + 1, a + n + 1);
	
	for (int i = 1; i <= n; i ++) s[i] = s[i - 1] + a[i];
	
	ll ans = 1;
	for (ll i = 1; i <= n; i ++) {
		ll need = i * a[i];
		
		if (s[i] + m >= need) {
			ans = max(ans, i);
			continue;
		}
		
		int l = 1, r = i, id = -1;
		while (l <= r) {
			int mid = (l + r) / 2;
			
			ll tmp = s[i] - s[mid - 1];
			need = (i - mid + 1) * a[i];
			if (tmp + m >= need) {
				id = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		
		if (id != -1) ans = max(ans, i - id + 1);
	}
	
	cout << ans << '\n';
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e5 + 5;

ll n, k, m;

int main () {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int c, T; cin >> c >> T;
	while (T --) {
		cin >> n >> k;
		m = (n - 1) / 2;
		
		ll ed = m + 1;
		
		if (k >= ed - 1) {
			if (k < n) cout << 1 << '\n';
			else if (k == n) cout << 0 << '\n';
		}
		
		ll tmp = (ed - k) / 4;
		ll tot = tmp;
		
		ll ans = 0;
		ans = max(ans, tmp + 1);
		
		ll hf = k / 2, left = k - hf;
		tot += hf;
		
		tot += tmp;
		tot += tmp;
		tot += left;
		
		ans = max(ans, ed - tot);
		
		cout << ans << '\n';
	}
	
	return 0;
}
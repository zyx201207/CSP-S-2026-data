#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int c, T;
int n; ll d;
ll a[2000010], b[2000010];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);

	cin >> c >> T;
	while (T--) {
		cin >> n >> d;
		for (int i = 1; i <= n; ++i) cin >> a[i];
		a[n + 1] = a[n] + d + 1;
		
		ll ans = 0;
		for (int i = 1; i <= n; ++i) {
			bool is_ = false, is_1 = false;
			int l = i, r = upper_bound(a + 1 + i, a + 2 + n, a[i] + d) - a - 1;
			while (true) {
				if (l == r) break;
				if (r == n) break;
				
				// l ~ r -> r ~ 
				int R = upper_bound(a + 1 + r, a + 2 + n, a[r] + d) - a - 1;
				if (r == R) break;
				
				bool ss = false;
				if (is_) {
					ans += R - r;
					int id = upper_bound(a + 1 + r, a + 2 + n, a[r - 1] + d) - a - 1;
					ans -= id - r;
					ss = true;
					if (id == R) break;
				} else {
					int id = upper_bound(a + 1 + r, a + 2 + n, a[r - 1] + d) - a - 1;
					if (id == R && is_1) break;
					if (!is_1) {
						ans += id - r;
						if (id >= R - 1) ss = true;
	
						if (id == R) is_ = true;
						if (r - 2 >= l) {
							id = upper_bound(a + 1 + r, a + 2 + n, a[r - 2] + d) - a - 1;
	//						cout << "_" << r << ' ' << id << ' ' << ans << "\n";
							ans -= id - r;
							
							if (id == R) break;
						}
					} else {
						if (id >= R - 1) ss = true;
					}
				}
				
				l = r, r = R;
				is_1 = ss;
			}
//			cout << i << ' ' << ans << "\n";
		}
		
		cout << ans << "\n";
	}

	return 0;
}

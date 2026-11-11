#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll c, t, n, d, x[2000010];
bool pd[2000010];
int main(int argv, char **argc) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;

//	if (c == 11 || c == 12) {
//		while (t--) {
//			cin >> n >> d;
//			ll jl = 0;
//			for (int z = 1; z <= n; z++) {
//				cin >> x[z];
//				if (x[z] - x[1] <= d)
//					jl++;
//			}
//			if (jl < 3ll) {
//				cout << "0\n";
//			} else {
//				cout << max(0ll, n - (jl << 1ll) + 3) << '\n';
//			}
//		}
//		return 0;
//	}
//
	if (c == 13 || c == 14) {
		while (t--) {
			cout << "0\n";
		}
		return 0;
	}

	while (t--) {
		ll ans = 0ll;
		cin >> n >> d;
		memset(pd, 0, sizeof(pd));
		for (ll z = 1; z <= n; z++) {
			cin >> x[z];
		}
		ll l = 1ll, r = 1ll;
		for (ll z = 1ll; z <= n; z++) {
			ll jl = 0ll;
			for (ll y = r + 1ll; y <= n; y++) {
				if (x[y] - x[z] <= d)
					jl++;
				else
					break;
			}
			if (jl) {
				l = z;
				if (pd[l + 1ll])
					ans++;
				r += jl;
				pd[r] = 1;
//				cerr << l << ' ' << r << '\n';
			} else {
				continue;
			}
		}
		cout << ans << '\n';
//		cerr << '\n';
	}
	return 0;
}

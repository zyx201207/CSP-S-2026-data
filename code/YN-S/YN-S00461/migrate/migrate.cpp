#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[2000005];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int n, t;
	cin >> n >> t;
	for (int i = 1; i <= t; i++) {
		int x, jl;
		cin >> x >> jl;
		for (int j = 1; j <= jl; j++) {
			cin >> a[j];
		}
		int sum = a[2] - a[1];
		int ans = 0;
		for (int j = 1; j <= x; j++) {
			for (int k = 1; k <= x; k++) {
				if ((k - j)*sum > jl && (k - j)*sum <= jl + jl - 1) {
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
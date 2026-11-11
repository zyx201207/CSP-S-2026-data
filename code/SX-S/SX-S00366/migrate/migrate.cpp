#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll wy, T;
ll n, d;
ll x[2000010];
ll e[2000010][2000010];
ll ans;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> wy >> T;
	while (T--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		for (int i = 1; i <= n - 1; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (x[j] - x[i] <= d) {
					e[i][j] = 1;
				}
			}
		}
		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (e[i][k] && e[k][j] || e[i][j]) {
						ans++;
					}
				}
			}
		}
		cout << ans;
	}
	return 0;
}
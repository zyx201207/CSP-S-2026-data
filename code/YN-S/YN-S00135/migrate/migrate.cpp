#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;
ll n, m, a[N], c, T, dp[N];

struct edge {
	ll v, w;
};
vector <ll> e[N];

void dfs(ll x) {

}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (a[j] - a[i] >= m) {
					e[i].push_back(j);
					//fa[j] = fa[i];
				}
			}
		}
		for (int k = 1; k <= n; k++) {

		}
		for (int i = 1; i <= n; i++) {
			memset(dp, sizeof(dp), 0);
			dp[i] = 1;
			for (int j = i + 1; j <= n; j++) {
				if (a[j] - a[i] >= m) {
					dp[j] = 1 + dp[i];
				} else {
					break;
				}
			}
			for (int j = i - 1; j <= n; j++) {
				if (a[i] - a[j] >= m) {
					dp[j] = 1 + dp[i];
				} else {
					break;
				}
			}
		}
		cout << n << endl;
	}

	return 0;
}
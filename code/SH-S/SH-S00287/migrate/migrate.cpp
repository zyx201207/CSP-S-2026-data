#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e6+6;
ll c, t, n, d;
ll a[maxn], f[maxn], dis[maxn];
vector<ll> to[maxn];
void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	ll ans = 0;
	for (int u = 1; u <= n; u++) {
		memset(f, 0, sizeof f);
		memset(dis, 0x3f, sizeof dis);
		f[u] = 0; dis[u] = 0;
		for (int v = u; v <= n; v++) {
			for (int x = v+1; x <= n; x++) {
				if (a[x] - a[v] <= d) {
					if (dis[x] > dis[v]+1) {
						dis[x] = dis[v]+1;
						f[x] = 1;
					} else if (dis[x] == dis[v]+1) {
						f[x]++;
					}
				} else break;
			}
		}
		for (int v = u+1; v <= n; v++) {
			ans += f[v] == 2;
		}
	}
	cout << ans << '\n';
 }
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> c >> t;
	while (t--) {
		solve();
	}
	return 0;
}

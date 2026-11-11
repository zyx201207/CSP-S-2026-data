#include <iostream>
#include <climits>
#define ll long long
using namespace std;
int c, t, n;
ll d;
ll x[2000050];
ll minn[2000050], cnt[2000050];
void dfs(int id, ll dis) {
	if (minn[id] == dis) ++cnt[id];
	if (minn[id] > dis) minn[id] = dis, cnt[id] = 1;
	if (id == n) return;
	for (int i = id + 1; i <= n; ++i) {
		if (x[id] + d >= x[i]) dfs(i, dis + 1);
		else break;
	}
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; ++i)
			cin >> x[i];
		ll ans = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j)
				minn[j] = LLONG_MAX, cnt[j] = 0;
			dfs(i, 0);
			for (int j = i + 1; j <= n; ++j)
				ans += (cnt[j] == 2);
		}
		cout << ans << '\n';
	}
	return 0;
}

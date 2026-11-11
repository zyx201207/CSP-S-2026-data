#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll C, n, m, d, Q, ans = INT_MAX, t_k[500005], t_t[50005][505];
vector<ll>p_id[500005], i_station[505];
bool vis[505];

void DFS(ll xl, ll res, ll fa, ll goal) {
	for (auto tmp : i_station[xl]) {
		if (tmp == fa)
			continue;
		if (tmp == goal) {
			ans = min(ans, res + t_t[tmp][xl] + t_k[tmp]);
			continue;
		}
		for (auto tmp2 : p_id[tmp]) {
			if (vis[tmp2])
				continue;
			vis[tmp2] = 1, DFS(tmp2, res + t_t[tmp][xl] + t_t[tmp][tmp2], tmp, goal), vis[tmp2] = 0;
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> C >> n >> m >> d >> Q;
	for (int i = 1; i <= m; i++)
		cin >> t_k[i];
	for (int i = 1; i <= n; i++) {
		ll k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			ll id;
			cin >> id >> t_t[id][i];
			i_station[i].push_back(id), p_id[id].push_back(i);
		}
	}
	while (Q--) {
		ll x, y;
		cin >> x >> y;
		for (auto tmp : p_id[x])
			vis[tmp] = 1, DFS(tmp, t_k[x] + t_t[x][tmp], x, y), vis[tmp] = 0;
		cout << ans << endl;
		ans = INT_MAX;
	}
	return 0;
}
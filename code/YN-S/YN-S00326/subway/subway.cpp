#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, s, bh, endd, x, cnt, a[500005];
long long dis[2000005];
bool vis[2000005];

struct edge {
	int v, w;
};
vector<edge>e[2000005];
queue<int>qu;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> a[i];
	cnt += m * 2;
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		cnt++;
		for (int j = 1; j <= k; j++) {
			cin >> bh >> x;
			e[bh + m].push_back({cnt, x});
			e[cnt].push_back({bh + m, x});
		}
	}
	while (q--) {
		cin >> s >> endd;
		while (!qu.empty())
			qu.pop();
		memset(vis, 0, sizeof vis);
		memset(dis, 0x7f, sizeof dis);
		qu.push(s + m);
		vis[s + m] = 1;
		dis[s + m] = 0;
		while (!qu.empty()) {
			int u = qu.front();
			qu.pop();
			vis[u] = 0;
			for (auto it : e[u]) {
				int v = it.v, w = it.w;
				if (dis[u] + w < dis[v]) {
					dis[v] = dis[u] + w;
					if (!vis[v]) {
						qu.push(v);
						vis[v] = 1;
					}
				}
			}
		}
		cout << dis[endd + m] + a[s] + a[endd] << '\n';
	}
	return 0;
}
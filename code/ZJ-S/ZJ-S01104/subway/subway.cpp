#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=500+5, MAXK=5e5+5;
int c, n, m, d, Q, K, st, ed, w[MAXN], a[MAXK], t[MAXK];
ll dis[MAXN][MAXN], vis[MAXN];
priority_queue<pair<ll,ll>, vector<pair<ll,ll> >, greater<pair<ll,ll> > > q;
vector<ll> f[MAXN], e[MAXN];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> c >> n >> m >> d >> Q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> K;
		for (int j = 1; j <= K; j++) {
			cin >> a[j] >> t[j];
			for (int k = 1; k < j; k++) {
				f[a[k]].push_back(a[j]);e[a[k]].push_back(t[k] + t[j]);
				f[a[j]].push_back(a[k]);e[a[j]].push_back(t[k] + t[j]);
			}
		}
	}
	memset(dis, 127, sizeof(dis));
	for (int i = 1; i <= m; i++) {
		memset(vis, 0, sizeof(vis));
		q.push(make_pair(0, i));
		dis[i][i] = 0;
		while (!q.empty()) {
			int x = q.top().second;
			q.pop();
//			if (x < i) continue;
			if (vis[x]) continue;
			vis[x] = 1;
			for (int j = 0; j < f[x].size(); j++) {
				int sx = f[x][j], sb = dis[i][x] + e[x][j];
				if (sb < dis[i][sx]) {
					dis[i][sx] = sb;
					q.push(make_pair(sb, sx));
				}
			}
		}
	}
	while (Q--) {
		cin >> st >> ed;
		cout << w[st] + w[ed] + dis[st][ed] << "\n";
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 1010, M = 5e5 + 10, INF = 0x3f3f3f3f;
#define int long long
typedef pair<int, int> PII;
#define fi first
#define se second
int id, n, m, d, q, w[M];
int tmpa[N], tmpt[N], dist[N][N], g[N][N];
int pos[M][25], cnt[M];
PII post[M][25];
bool f[N], fd[N];
vector<PII> gv[N];
inline void chkmin(int &a, int b) {
	if(a > b) a = b;
}
inline void dij(int s) {
	priority_queue<PII, vector<PII>, greater<PII>> q;
	q.push({0, s});
	dist[s][s] = 0;
	f[s] = 1;
	memset(fd, 0, sizeof fd);
	while(!q.empty()) {
		int u = q.top().se;
		q.pop();
		if(fd[u]) continue;
		fd[u] = 1;
		for(PII i : gv[u]) {
			int v = i.fi, w = i.se;
			if(dist[s][u] + w < dist[s][v]) {
				dist[s][v] = dist[s][u] + w;
				q.push({dist[s][v], v});	
			}
		}
	}
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
	cin >> id >> n >> m >> d >> q;
	for(int i = 1; i <= m; ++i) cin >> w[i];
	if(1 <= id && id <= 11) {
		memset(dist, 0x3f, sizeof dist),
		memset(g, 0x3f, sizeof g);
		for(int i = 1, k; i <= n; ++i) {
			cin >> k;
			for(int j = 1; j <= k; ++j) 
				cin >> tmpa[j] >> tmpt[j];
			for(int u = 1; u <= k; ++u)
				for(int v = u + 1; v <= k; ++v)
					chkmin(g[tmpa[u]][tmpa[v]], tmpt[u] + tmpt[v]);
		}
		for(int i = 1; i <= m; ++i)
			for(int j = i + 1; j <= m; ++j)
				if(g[i][j] != INF)
					gv[i].push_back({j, g[i][j]}), gv[j].push_back({i, g[i][j]});
		for(int i = 1, x, y; i <= q; ++i) {
			cin >> x >> y;
			if(f[x]) cout << dist[x][y] + w[x] + w[y] << '\n';
			else if(f[y]) cout << dist[y][x] + w[x] + w[y] << '\n';
			else {
				dij(x);
				cout << dist[x][y] + w[x] + w[y] << '\n';
			}
		}
	} else if(id >= 12 && id <= 19) {
		memset(dist, 0x3f, sizeof dist),
		memset(g, 0x3f, sizeof g);
		int T;
		for(int i = 1, k; i <= n; ++i) {
			cin >> k;
			for(int j = 1, a; j <= k; ++j) {
				cin >> a >> T;
				pos[a][++cnt[a]] = i;
			}
		}
		T <<= 1;
		for(int i = 1; i <= m; ++i)
			if(cnt[i]) {
				for(int j = 1; j <= cnt[i]; ++j)
					for(int k = j + 1; k <= cnt[i]; ++k)
						dist[pos[i][j]][pos[i][k]] = dist[pos[i][k]][pos[i][j]] = 1;
			}
		for(int i = 1; i <= n; ++i) dist[i][i] = 0;
		for(int k = 1; k <= n; ++k)
			for(int i = 1; i <= n; ++i)
				for(int j = 1; j <= n; ++j)
					chkmin(dist[i][j], dist[i][k] + dist[k][j]);
		for(int i = 1, x, y; i <= q; ++i) {
			cin >> x >> y;
			int ans = INF;
			bool flag = 1;
			for(int i = 1; i <= cnt[x] && flag; ++i)
				for(int j = 1; j <= cnt[y]; ++j)
					if(pos[x][i] == pos[y][j]) {
						cout << w[x] + w[y] + T << '\n';
						flag = 0;
						break;
					} else chkmin(ans, dist[pos[x][i]][pos[y][j]]);
			if(flag)
				cout << (ans + 1) * T + w[x] + w[y] << '\n';
		}
	} else if(id == 21 || id == 20) {
		int minn[3]; minn[1] = minn[2] = INF; 
		for(int i = 1, k; i <= n; ++i) {
			cin >> k;
			for(int i = 1, a, tt; i <= k; ++i) {
				cin >> a >> tt;
				post[a][++cnt[a]] = {i, tt};
			}
		}
		for(int i = 1; i <= m; ++i)
			if(cnt[i] >= 2)
				chkmin(minn[post[i][1].fi],post[i][1].se),
				chkmin(minn[post[i][2].fi], post[i][2].se);
		for(int i = 1, x, y; i <= q; ++i) {
			cin >> x >> y;
			int ans1 = INF, ans2 = INF;
			for(int j = 1; j <= cnt[x]; ++j)
				for(int k = 1; k <= cnt[y]; ++k)
					if(post[x][j].fi == post[y][k].fi)
						chkmin(ans1, post[x][j].se + post[y][k].se);
					else 
						ans2 = minn[1] + minn[2];
			cout << min(ans2 + post[x][1].se + post[y][1].se, ans1) + w[x] + w[y] << '\n';
		}
	}
	return 0;
}
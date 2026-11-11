#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e2 + 5;

int f[N][N][N][3][2], siz[N], g[N][N][3][2];
int n, k; 
void dfs(int u, int fa, vector<vector<int> > &G) {
	f[u][0][1][0][0] = 0, f[u][1][0][1][1] = 0; siz[u] = 1;
	for(auto v : G[u]) {
		if(v == fa) continue;
		dfs(v, u, G);
		memset(g, 0x3f, sizeof(g));
		for(int i = 0; i <= siz[u] && i <= k; i++)
			for(int j = 0; j <= siz[v] && i + j <= k; j++)
				for(int d1 = 0; d1 <= siz[u]; d1++)
					for(int d2 = 0; d2 <= siz[v]; d2++)
						for(int c1 = 0; c1 < 3; c1++)
							for(int c2 = 0; c2 < 3; c2++)
								for(int k1 = 0; k1 < 2; k1++)
									for(int k2 = 0; k2 < 2; k2++) 
										if(c1 + c2 - (k1 && k2) <= 2){
											g[i + j][!k1 ? max(d1, d2 + 1) : 0][c1 + c2 - (k1 && k2)][k1] = min(
												max({f[u][i][d1][c1][k1], f[v][j][d2][c2][k2], d1 + d2, d1, d2}), 
											g[i + j][!k1 ? max(d1, d2 + 1) : 0][c1 + c2 - (k1 && k2)][k1]);
										}
		siz[u] += siz[v];
		for(int i = 0; i <= siz[u] && i <= k; i++)
			for(int d = 0; d <= siz[u]; d++)
				for(int c = 0; c < 3; c++)
					for(int kk = 0; kk < 2; kk++)
						f[u][i][d][c][kk] = g[i][d][c][kk];
	}
}
const int M = 1e3 + 5;
int f1[M][3][M][3][2], g1[3][M][3][2];
void dfs2(int u, int fa, vector<vector<int> > &G) {
	f1[u][0][1][0][0] = 0, f1[u][1][0][1][1] = 0; siz[u] = 1;
	for(auto v : G[u]) {
		if(v == fa) continue;
		dfs2(v, u, G);
		memset(g1, 0x3f, sizeof(g1));
		for(int i = 0; i <= siz[u] && i <= k; i++)
			for(int j = 0; j <= siz[v] && i + j <= k; j++)
				for(int d1 = 0; d1 <= siz[u]; d1++)
					for(int d2 = 0; d2 <= siz[v]; d2++)
						for(int c1 = 0; c1 < 3; c1++)
							for(int c2 = 0; c2 < 3; c2++)
								for(int k1 = 0; k1 < 2; k1++)
									for(int k2 = 0; k2 < 2; k2++) 
										if(c1 + c2 - (k1 && k2) <= 2){
											g1[i + j][!k1 ? max(d1, d2 + 1) : 0][c1 + c2 - (k1 && k2)][k1] = min(
												max({f1[u][i][d1][c1][k1], f1[v][j][d2][c2][k2], d1 + d2, d1, d2}), 
											g1[i + j][!k1 ? max(d1, d2 + 1) : 0][c1 + c2 - (k1 && k2)][k1]);
										}
		siz[u] += siz[v];
		for(int i = 0; i <= siz[u] && i <= k; i++)
			for(int d = 0; d <= siz[u]; d++)
				for(int c = 0; c < 3; c++)
					for(int kk = 0; kk < 2; kk++)
						f1[u][i][d][c][kk] = g1[i][d][c][kk];
	}
}

void solve(int id) {
	cin >> n >> k;
	vector<vector<int> > G(n + 1);
	for(int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		G[u].push_back(v), G[v].push_back(u);
	}
	if(id <= 3) {
		int ans = 0x3f3f3f3f3f3f3f3f;
		for(int i = 0; i < (1 << n); i++) {
			if(__builtin_popcount(i) != k) continue;
			vector<int> vis(n + 1);
			for(int j = 1; j <= n; j++)
				if(i & (1 << j - 1)) vis[j] = 1;
			vector<int> V(n + 1);
			auto dfs = [&](auto &&self, int u, int fa) -> void {
				V[u] = 1;
				for(auto v : G[u]) {
					if(v == fa) continue;
					if(V[v]) continue; if(!vis[v]) continue;
					self(self, v, u);
				}
			};
			int cnt = 0;
			for(int i = 1; i <= n; i++)
				if(vis[i] && !V[i]) cnt++, dfs(dfs, i, 0);
			if(cnt > 2) continue;
			queue<int> q; vector<int> dis(n + 1, 0x3f3f3f3f3f3f3f3f);
			for(int i = 1; i <= n; i++)
				if(vis[i]) dis[i] = 0, q.push(i);
			while(!q.empty()) {
				int u = q.front(); q.pop();
				for(auto v : G[u])
					if(vis[v]) continue;
					else vis[v] = 1, dis[v] = dis[u] + 1, q.push(v);
			}
			ans = min(ans, *max_element(dis.begin() + 1, dis.end()));
		} cout << ans << '\n';
		return;
	} else if(id <= 6) {
		memset(f, 0x3f, sizeof(f));
		dfs(1, 0, G);
		int ans = 0x3f3f3f3f3f3f3f3f;
		for(int i = 0; i <= k; i++)
			for(int d = 0; d <= n; d++)
				for(int c = 0; c < 3; c++)
					for(int kk = 0; kk < 2; kk++)
						ans = min(ans, max(d, f[1][i][d][c][kk]));
		cout << ans << '\n';
	} else if(id == 7) {
		memset(f1, 0x3f, sizeof(f1));
		dfs2(1, 0, G);
		int ans = 0x3f3f3f3f3f3f3f3f;
		for(int i = 0; i <= k; i++)
			for(int d = 0; d <= n; d++)
				for(int c = 0; c < 3; c++)
					for(int kk = 0; kk < 2; kk++)
						ans = min(ans, max(d, f1[1][i][d][c][kk]));
		cout << ans << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int id, t = 1;
	cin >> id >> t;
	while(t--) {
		solve(id);
	}
	return 0;
}
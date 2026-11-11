#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int c, n, m, d, q;
int w[N], k[N], a[505][20005], t[505][20005], f[505][505], tt[20005][505];
vector<int> belong[N];
struct node{
	int to, nxt, w;
}e[N];
int cnt = 0, h[N];
void add(int u, int v, int w) {
	e[++cnt] = {v, h[u], w};
	h[u] = cnt;
}
int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int dis[505];
bool vis[505];
typedef pair<int, int> P;
void dijk(int st) {
	memset(dis, 0x3f, sizeof dis);
	memset(vis, 0, sizeof vis);
	priority_queue<P, vector<P>, greater<P> > q;
	dis[st] = 0;
	q.push({0, st});
	while(!q.empty()) {
		P t = q.top();
		q.pop();
		if(vis[t.second]) continue;
		vis[t.second] = 1;
		for(int i = h[t.second]; i; i = e[i].nxt) {
			int j = e[i].to;
			if(dis[t.second] + e[i].w < dis[j]) {
				dis[j] = dis[t.second] + e[i].w;
				q.push({dis[j], j});
			}
		}
	}
	for(int i = 1; i <= n; i++) f[st][i] = dis[i];
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) w[i] = read();
	for(int i = 1; i <= n; i++) {
		k[i] = read();
		for(int j = 1; j <= k[i]; j++) {
			a[i][j] = read();
			t[i][j] = read();//从第aij号站厅走到第i条线路的站台
			tt[a[i][j]][i] = t[i][j];
			belong[a[i][j]].push_back(i);
		}
	}
	for(int i = 1; i <= m; i++) {
		for(int j = 0; j < (int)belong[i].size() - 1; j++) {
			for(int k = j + 1; k < (int)belong[i].size(); k++) {
				add(belong[i][j], belong[i][k], tt[i][belong[i][j]] + tt[i][belong[i][k]]);
				add(belong[i][k], belong[i][j], tt[i][belong[i][j]] + tt[i][belong[i][k]]);
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		dijk(i);
	}
	for(int i = 1; i <= q; i++) {
		int xr, yr, ans = 0x7f7f7f7f7f7f7f7f;
		xr = read(), yr = read();
		for(int j : belong[xr]) {
			for(int k : belong[yr]) {
				int s = tt[xr][j] + tt[yr][k] + f[j][k] + w[xr] + w[yr];
				ans = min(ans, s);
			}
		}
		cout << ans;
		puts("");
	}
	return 0;
}

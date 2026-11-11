#include <bits/stdc++.h>
using namespace std;

const int M = 5e4 + 101;
const int N = 515;

int c, n, m, d, q;
int w[M];
int mp[N][N];
int a[N], t[N];
int ans;

int head[N], cnt;
struct node {
	int to;
	int nex;
	int val;
}e[N * 2];
void add(int x, int y, int z) {
	e[++cnt] = (node){y, head[x]};
	head[x] = cnt;
}

int vis[N];

inline void dfs(int u, int pos, int step) {
	for (int i = head[u]; i; i = e[i].nex) {
		int v = e[i].to;
		if (vis[v]) continue;
		if (v == pos) {
			ans = min(ans, step);
			return ;
		}
		vis[v] = 1;
		dfs(v, pos, step + e[i].val);
		vis[v] = 0;
	}
}

int main() {
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	memset(mp, -1, sizeof mp);
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) cin >> a[j] >> t[j];
		for (int j = 1; j < k; j++) {
			for (int u = j + 1; u <= k; u++) {
				int x = a[j], y = a[u];
				if (mp[x][y] == -1) mp[x][y] = mp[y][x] = t[j] + t[k];
				else mp[x][y] = mp[y][x] = min(t[j] + t[k], mp[x][y]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			cout << mp[i][j] << endl;
			if (mp[i][j] == -1) continue;
			add(i, j, mp[i][j]);
			add(j, i, mp[j][i]);
		}
	}
	
	while (q--) {
		ans = 1e9;
		int x, y;
		cin >> x >> y;
		vis[x] = 1;
		dfs(x, y, 0);
		vis[x] = 0;
		cout << ans << endl;
	}
	
	
	return 0;
}


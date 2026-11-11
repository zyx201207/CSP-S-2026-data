#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 510, maxk = 5e5 + 10, maxq = 1e5 + 10;
int C, n, m, d, q, x, y;
int w[maxk], k[maxn], p[maxn][maxn], dis[maxn][maxn], ans = 0;
bool vis[maxn];

vector <int> b[maxk], c[maxk], a[maxn], t[maxn], l[maxk];

void bfs(int stx){
	queue <int> q;
	q.push(stx);
	memset(vis, 0, sizeof(vis));
	vis[stx] = 1;
	
	while (!q.empty()){
		int u = q.front();
		q.pop();
		for (int v = 1; v <= n; v++){
			if (p[u][v] == -1) continue;
			if (vis[v]){
				if (dis[stx][u] + p[u][v] < dis[stx][v]){
					dis[stx][v] = dis[stx][u] + p[u][v];
					q.push(v);
				}
			}
			else{
				dis[stx][v] = dis[stx][u] + p[u][v];
				q.push(v);
				vis[v] = 1;
			}
		}
	}
}

signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> C >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	//cout << "aaaaaaaaa" << endl;
	for (int i = 1; i <= n; i++){
		cin >> k[i];
		a[i].push_back(0);
		t[i].push_back(0);
		for (int j = 1, u, v; j <= k[i]; j++){
			cin >> u >> v;
			a[i].push_back(u);
			t[i].push_back(v);
			b[u].push_back(i);
			l[u].push_back(v);
			c[u].push_back(v);
		}
	}
	//cout << "aaaaaaaaaaaa" << endl;
	
	memset(p, -1, sizeof(p));
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= k[i]; j++){
			int mint;
			for (int ii = 0; ii < b[a[i][j]].size(); ii++){
				int v = b[a[i][j]][ii];
				if (v == i) continue;
				if (p[i][v] == -1){
					mint = t[i][j] + c[a[i][j]][ii];
					p[i][v] = mint;	
				}
				else{
					if (t[i][j] + c[a[i][j]][ii] < mint){
						mint = t[i][j] + c[a[i][j]][ii];
						p[i][v] = mint;
					}
				}
			}
		}
	}
	
	memset(dis, -1, sizeof(dis));
	for (int i = 1; i <= n; i++){
		dis[i][i] = 0;
		bfs(i);
	}
	
	
	//output tle
	int cnt = 0;
	for (int T = 1; T <= q; T++){
		cin >> x >> y;
		ans = LONG_LONG_MAX;
		for (int i = 0; i < b[x].size(); i++){
			int u = b[x][i];
			for (int j = 0; j < b[y].size(); j++){
				int v = b[y][j];
				if (dis[u][v] + l[x][i] + l[y][j] < ans){
					ans = dis[u][v] + l[x][i] + l[y][j];
				}
				//cout << u << " " << v << " " << dis[u][v] << endl;
			}
		}
		ans += w[x] + w[y];
		/*string res = to_string(ans);
		for (int i = 0; i < res.length(); i++) cout << res[i];
		cout << endl;*/
		cout << ans << endl;
	}
	
	return 0;
}

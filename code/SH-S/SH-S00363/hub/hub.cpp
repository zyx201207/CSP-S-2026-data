#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 1e5 + 10;
int C, T, n, k, dis[maxn], d[maxn], ans;
bool s[maxn], vis[maxn];

vector <int> g[maxn];

void bfs(int stx){
	queue <int> q;
	q.push(stx);
	vis[stx] = 1;
	
	while (!q.empty()){
		int u = q.front();
		q.pop();
		
		for (int v : g[u]){
			if (s[v] && !vis[v]){
				q.push(v);
				vis[v] = 1;
			}
		}
	}
}

void bfs2(int stx){
	queue <int> q;
	q.push(stx);
	
	while (!q.empty()){
		int u = q.front();
		q.pop();
		
		for (int v : g[u]){
			if (dis[v] == -1){
				dis[v] = dis[u] + 1;
				q.push(v);
			}
			else{
				if (dis[v] > dis[u] + 1){
					dis[v] = dis[u] + 1;
					q.push(v);
				}
			}
		}
	}
}

void dfs(int u, int cnt){
	if (cnt == 0){
		//for (int i = 1; i <= n; i++) if (s[i]) cout << i << ' ';
		//cout << endl;
		
		int lcnt = 0;
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= n; i++){
			if (!vis[i] && s[i]){
				bfs(i);	
				lcnt++;
			}
		}
		if (lcnt > 2) return;
		
		//for (int i = 1; i <= n; i++) if (s[i]) cout << i << ' ';
		//cout << endl;
		
		
		for (int i = 1; i <= n; i++){
			if (s[i]) d[i] = 0;
			else{
				d[i] = LONG_LONG_MAX;
				memset(dis, -1, sizeof(dis));
				bfs2(i);	
				for (int j = 1; j <= n; j++){
					if (s[j]){
						d[i] = min(d[i], dis[j]);
						//cout << dis[j] << ' ';	
					}
				}
			}
		}
		
		int res = 0;
		for (int i = 1; i <= n; i++){
			res += d[i];
			//cout << d[i] << ' ';
		}
		//cout << res << endl;
		ans = min(ans, res);
		return;
	}
	
	for (int i = u + 1; i <= n; i++){
		if (!s[i]){
			s[i] = 1;
			dfs(i, cnt - 1);
			s[i] = 0;
		}
	}
}

void solve(){
	ans = LONG_LONG_MAX;
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++) g[i].clear();
	for (int i = 1, u, v; i <= n - 1; i++){
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	dfs(0, k);
	
	cout << ans << endl;
	return;
}

signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> C >> T;
	while (T--) solve();
	return 0;
}

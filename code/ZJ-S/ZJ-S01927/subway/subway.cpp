#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int x, y, ans;
int c, n, m, d, q, w[305], a[55][305], t[55][305], L[305][305];
vector<pii> l[305];
vector<int> g[305];
bool vis[305];

void dfs(int u, int now, int cost){
	if (u == y){
		cost += t[now][L[u][now]];
		ans = min(ans, cost);
	}
	else{
		for (int i = 0; i < g[u].size(); i++){
			int v = g[u][i];
			if (!vis[v]){
				vis[v] = 1;
				for (int j = 0; j < l[v].size(); j++){
					int f = l[v][j].first;
					if (f != now){
						if (u == x) continue;
						dfs(v, f, cost + t[now][L[u][now]] + t[f][L[u][f]]);
						vis[v] = 0;
					}
					else{
						dfs(v, f, cost);
						vis[v] = 0;
					}
				}
			}
			
		}
	}    	
}

int main(){
	ios::sync_with_stdio(0);
	
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	//
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++){
		cin >> w[i];
	}              
	for (int i = 1; i <= n; i++){
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++){
			cin >> a[i][j] >> t[i][j];
			l[a[i][j]].push_back({i, j});
			L[a[i][j]][i] = j;
			if (j > 1){
				g[a[i][j-1]].push_back(a[i][j]);
				g[a[i][j]].push_back(a[i][j-1]);
			}
		}
	}
	
	
	
	//
	while (q--){
		memset(vis, 0, sizeof(vis));
		cin >> x >> y;
		ans = INT_MAX;
		for (int i = 0; i < l[x].size(); i++){
			int f = l[x][i].first, s = l[x][i].second;
			vis[x] = 1;
			dfs(x, f, w[x] + w[y] + t[f][s]);
		}
		cout << ans << '\n';
	}
	
	//
	
	return 0;
}
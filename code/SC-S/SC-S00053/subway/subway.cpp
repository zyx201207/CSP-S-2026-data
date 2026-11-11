#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = 505, maxm = 20005;
int c, n, m, d, q;
ll w[maxm], t[maxn][maxm], dis[maxm][maxn];
bool vis[maxm][maxn];
struct edge{
	int to, line;
};
vector<edge> g[maxm];
vector<pair<int, ll> > query[maxm];
ll res[100005];
struct sta{
	int u, line;
	ll val;
	bool operator<(const sta &x) const{
		return val > x.val;
	}
};

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; ++ i) cin >> w[i];
	for(int i = 1; i <= n; ++ i){
		int k;
		cin >> k;
		int p;
		cin >> p;
		cin >> t[i][p];
		-- k;
		while(k --){
			int x;
			cin >> x;
			cin >> t[i][x];
			g[p].push_back((edge){x, i});
			g[x].push_back((edge){p, i});
			p = x;
		}
	}
	for(int i = 1; i <= q; ++ i){
		int x, y;
		cin >> x >> y;
		query[x].push_back(make_pair(y, i));
	}
	if(12 <= c && c <= 15){
		for(int x = 1; x <= m; ++ x){
			if(query[x].empty()) continue;
			for(int i = 1; i <= m; ++ i){
				for(int j = 1; j <= n; ++ j) dis[i][j] = (ll)1e17, vis[i][j] = 0;
			}
			queue<edge> qu;
			for(int i = 0; i < g[x].size(); ++ i){
				qu.push((edge){x, g[x][i].line});
				dis[x][g[x][i].line] = w[x] + t[g[x][i].line][x];
			}
			while(!qu.empty()){
				int u = qu.front().to, l = qu.front().line;
				qu.pop();
				vis[u][l] = 1;
				for(int i = 0; i < g[u].size(); ++ i){
					int v = g[u][i].to, k = g[u][i].line;
					ll w;
					if(l == k) w = 0;
					else w = t[l][u] + t[k][u];
					if(dis[v][k] > dis[u][l] + w){
						dis[v][k] = dis[u][l] + w;
						if(!vis[v][k]) qu.push((edge){v, k});
					}
				}
			}
			for(int it = 0; it < query[x].size(); ++ it){
				int y = query[x][it].first;
				ll ans = (ll)1e17;
				for(int i = 0; i < g[y].size(); ++ i){
					ans = min(ans, dis[y][g[y][i].line] + w[y] + t[g[y][i].line][y]);
				}
				res[query[x][it].second] = ans;
			}
		}
	}
	else{
		for(int x = 1; x <= m; ++ x){
			if(query[x].empty()) continue;
			for(int i = 1; i <= m; ++ i){
				for(int j = 1; j <= n; ++ j) dis[i][j] = (ll)1e17, vis[i][j] = 0;
			}
			priority_queue<sta> qu;
			for(int i = 0; i < g[x].size(); ++ i){
				qu.push((sta){x, g[x][i].line, w[x] + t[g[x][i].line][x]});
				dis[x][g[x][i].line] = w[x] + t[g[x][i].line][x];
			}
			while(!qu.empty()){
				int u = qu.top().u, l = qu.top().line;
				qu.pop();
				if(vis[u][l]) continue;
				vis[u][l] = 1;
				for(int i = 0; i < g[u].size(); ++ i){
					int v = g[u][i].to, k = g[u][i].line;
					ll w;
					if(l == k) w = 0;
					else w = t[l][u] + t[k][u];
					if(dis[v][k] > dis[u][l] + w){
						dis[v][k] = dis[u][l] + w;
						qu.push((sta){v, k, dis[v][k]});
					}
				}
			}
			for(int it = 0; it < query[x].size(); ++ it){
				int y = query[x][it].first;
				ll ans = (ll)1e17;
				for(int i = 0; i < g[y].size(); ++ i){
					ans = min(ans, dis[y][g[y][i].line] + w[y] + t[g[y][i].line][y]);
				}
				res[query[x][it].second] = ans;
			}
		}
	}
	for(int i = 1; i <= q; ++ i) cout << res[i] << "\n";
	
	return 0;
}
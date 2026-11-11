#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl '\n'

const int N = 5e5 + 10;
const int inf = 1e9;

int cid,n,k;
int dis[N],fa[N],vis[N];
int b[25][25];
vector <int> g[N];

int popc (int x){ return __builtin_popcount(x); }
int find (int u){ return fa[u] = (u == fa[u] ? u : find(fa[u])); }
void merge (int u,int v){ fa[find(u)] = find(v); }
void solve(){
	cin >> n >> k;
	for (int i = 1 ; i <= n ; i++) g[i].clear();
	for (int i = 1 ; i < n ; i++){
		int u,v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if (n <= 10){
		for (int i = 1 ; i <= n ; i++)
			for (int j = 1 ; j <= n ; j++) b[i][j] = 0;
		for (int i = 1 ; i <= n ; i++)
			for (auto j : g[i]) b[i][j] = b[j][i] = 1;
		int ans = inf;
		for (int mask = 0 ; mask < (1 << n) ; mask++){
			if (popc(mask) != k) continue;
			queue <int> q;
			for (int i = 1 ; i <= n ; i++) dis[i] = inf,vis[i] = 0,fa[i] = i;
			for (int i = 0 ; i < n ; i++)
				if ((mask >> i) & 1) q.push(i + 1),dis[i + 1] = 0,vis[i + 1] = 1;
			for (int i = 1 ; i <= n ; i++)
				for (int j = i + 1 ; j <= n ; j++)
					if (b[i][j] && vis[i] && vis[j]) merge(i,j);
			int cnt = 0;
			for (int i = 1 ; i <= n ; i++) cnt += (vis[i] && (fa[i] == i));
			if (cnt > 2) continue;
			while (!q.empty()){
				int u = q.front(); q.pop();
				//cout << "!!! " << u << endl;
				for (auto v : g[u]){
					if (dis[v] == inf){
						dis[v] = dis[u] + 1;
						q.push(v);
					}
				}
			}
			//for (int i = 1 ; i <= n ; i++) cout << dis[i] << ' ';
			//cout << endl;
			int mx = 0;
			for (int i = 1 ; i <= n ; i++) mx = max(mx,dis[i]);
			//cout << "!!! " << mask << ' ' << mx << endl;
			//for (int i = 1 ; i <= n ; i++) if (vis[i]) cout << i << ' ';
			//cout << endl;
			ans = min(ans,mx);
		}
		cout << ans << endl;
		return;
	}
	int ans = inf;
	for (int x = 1 ; x <= n ; x++){
		for (int y = x + 1 ; y <= n ; y++){
			queue <int> q;
			for (int i = 1 ; i <= n ; i++) dis[i] = inf;
			q.push(x); q.push(y); dis[x] = dis[y] = 0;
			while (!q.empty()){
				int u = q.front(); q.pop();
				//cout << "!!! " << u << endl;
				for (auto v : g[u]){
					if (dis[v] == inf){
						dis[v] = dis[u] + 1;
						q.push(v);
					}
				}
			}
			int mx = 0;
			for (int i = 1 ; i <= n ; i++) mx = max(mx,dis[i]);
			ans = min(ans,mx);
		}
	}
	cout << ans << endl;
}
signed main(){
	//freopen("hub3.in","r",stdin);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T = 1; cin >> cid >> T;
	while (T--) solve();
	return 0;
}
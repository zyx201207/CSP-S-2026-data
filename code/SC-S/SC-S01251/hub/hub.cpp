#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int N = 1e6+5;
int c, t, n, k, a[1005][1005], dis[1005][1005], vis[N], f[N];
vector<int>g[N];
int find(int x){
	if (x == f[x]) return f[x];
	return f[x] = find(f[x]);
}
void merge(int x,int y){
	int fx = find(x), fy = find(y);
	if (fx == fy) return ;
	f[fx] = fy;
}
void dijk(int s){
	memset(vis,0,sizeof(vis));
	dis[s][s] = 0;
	priority_queue<pii,vector<pii>,greater<pii> >q;
	q.push({0,s});
	while(!q.empty()){
		int u = q.top().second;
		q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto v: g[u]){
			if (dis[s][u]+1 < dis[s][v]){
				dis[s][v] = dis[s][u]+1;
				q.push({dis[s][v],v});
			}
		}
	}
}
void solve(){
	cin >> n >> k;
	for (int i = 0;i <= n;i++) g[i].clear();
	memset(a,0,sizeof(a));
	memset(dis,0x3f,sizeof(dis));
	for (int i = 1;i < n;i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		a[u][v] = a[v][u] = 1;
	}
	for (int i = 1;i <= n;i++) dijk(i);
	if (k == 2){
		int ans = 1e9;
		for (int i = 1;i <= n;i++)
			for (int j = i+1;j <= n;j++){
				int mx = 0;
				for (int k = 1;k <= n;k++)
					mx = max(mx,min(dis[i][k],dis[j][k]));
				ans = min(ans,mx);
			}
		cout << ans << '\n';
	}
	else{
		if (n/k-1 == 0) cout << 1 << '\n';
		else cout << n/k-1 << '\n';
	}
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--) solve();
	return 0;
}
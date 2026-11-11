#include<bits/stdc++.h>
using namespace std;
const int M = 5e5 + 5,D = 25,inf = 1e9;
int c,n,m,d,q,t[M][D],k,a[M],x,y,ans,ka;
bool vis[M];
struct node{int v,l,t;};
vector<node> g[M];
void add(int u,int v,int l){
	g[u].push_back({v,l,0});
	g[v].push_back({u,l,0});
}
void dfs(int u,int l,int cnt){
	ka++;
	if(ka > 1e8)return;
	vis[u] = true;
	if(u == y){
		ans = min(ans,cnt + t[u][l] + t[u][0]);
		return;
	}
	for(int i = 0;i < int(g[u].size());i++){
		int v = g[u][i].v;
		if(!vis[v]){
			if(l != g[u][i].l)dfs(v,g[u][i].l,cnt + t[u][l] + t[u][g[u][i].l]);
			else dfs(v,g[u][i].l,cnt);
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)cin >> t[i][0];
	for(int i = 1;i <= n;i++){
		cin >> k >> a[1];
		cin >> t[a[1]][i];
		for(int j = 2;j <= k;j++){
			cin >> a[j];
			cin >> t[a[j]][i];
			add(a[j - 1],a[j],i);
		}
	}
	while(q--){
		cin >> x >> y;
		memset(vis,false,sizeof(vis));
		ans = inf;
		dfs(x,0,0);
		cout << ans << endl;
	}
	return 0;
}

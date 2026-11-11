#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 507, K = 2e4+7;
struct node {
	int vis, val;
	bool operator < (const node &x)const{
		return val<x.val;
	}
};
int c, n, m, d, q;
vector<node> g[N*K];
int a[N][K], t[N][K];
int w[N], dis[N*K],vis[N*K];
priority_queue<node> qu;
void dij(int s, int t) {
	dis[s]=0;
	for(node x:g[s]){
		qu.push(x);
	}
	while(!qu.empty()){
		node T=qu.top();
		qu.pop();
		int u=T.vis,w=-T.val;
		vis[u]=1;
		cout<<u<<' '<<w<<'\n';
		for(node x:g[u]){
			int v=x.vis;
			if(dis[v]>w+dis[u]){ 
				dis[v]=min(dis[v],w+dis[u]);
				if(vis[v]==0){
					qu.push({v,dis[v]});
				}
			}
			for(int i=1;i<=n*m;i++){
				cout<<dis[i]<<' ';
			}
			cout<<'\n';
		}
	}
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a[i][j] >> t[i][j];
			if (j != 1) {
				g[i*m + a[i][j - 1]].push_back({i*m + a[i][j], 0});
				g[i*m + a[i][j]].push_back({i*m + a[i][j - 1], 0});
			}
			g[a[i][j]].push_back({i*m+a[i][j],-t[i][j]});
			g[i*m+a[i][j]].push_back({a[i][j],-t[i][j]});
		}
	}
	while (q--) {
		int l, r;
		memset(dis,0x3f,sizeof dis);
		cin >> l >> r;
		dij(l, r);
		for(int i=1;i<=n*m;i++){
			cout<<dis[i]<<' ';
		}
		cout<<dis[r]+w[l]+w[r]<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
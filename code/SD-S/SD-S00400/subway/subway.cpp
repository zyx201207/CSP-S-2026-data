#include <bits/stdc++.h>

#define PII pair <int,int>
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define all(u) (u).begin(),(u).end()
#define MOD 998244353
#define INF 0x3f3f3f3f3f3f3f3f
#define int long long
#define ll long long
#define N 500003
#define M 503
using namespace std;
//N µãÊý M ±ßÊý£¡ 
int dis[N + M];
bool vis[N + M];
int _c,n,m,d,T;
int a[N + M];
vector <PII> g[N + M];
void dij(int s) {
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	priority_queue <PII,vector <PII>,greater <PII> > q;
	dis[s] = 0;
	q.push({dis[s],s});
	while(q.size()) {
		int d = q.top().fi,u = q.top().se;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(auto t : g[u]) {
			int v = t.fi,w = t.se;
			if(dis[v] > d + w) {
				dis[v] = d + w;
				q.push({dis[v],v});
			}
		}
	}
}
void add(int u,int v,int w) {
	g[u].push_back({v,w});
	g[v].push_back({u,w});
}
signed main() {
	freopen("subway.in","r",stdin);
//	freopen("subway4.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>_c>>m>>n>>d>>T;
	for(int i = 1;i <= n;i ++) cin>>a[i];
	for(int i = 1,l;i <= m;i ++) {
		cin>>l;
		for(int u,v;l --;) {
			cin>>u>>v;
			add(i + n,u,v);
		}
	}
//	for(int i = 1;i <= m;i ++) {
//		dij(i,i + n);
//		for(int j = 1;j <= n + m;j ++) cout<<dis[j]<<" ";cout<<"\n";
//	}
//	dij(1);
	for(int u,v;T --;) {
		cin>>u>>v;
		dij(u);
		cout<<dis[v] + a[u] + a[v]<<"\n";
	}
	return 0;
}


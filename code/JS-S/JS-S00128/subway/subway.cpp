#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(a,b,c) for(int a=(b);a<=(c);++a)
#define per(a,b,c) for(int a=(b);a>=(c);--a)
const int N=505,M=5e5+5;
const ll INF=1e18;
int c,n,m,d,q;
int w[M];
#define pi pair<int,int>
vector <pi> li[M];
ll g[N][N];
ll f[N][N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	rep(i,1,m) cin>>w[i];
	rep(i,1,n){
		int k;
		cin>>k;
		for(int v,w;k--;){
			cin>>v>>w;
			li[v].push_back({i,w});
		}
	}
	rep(u,1,n) rep(v,1,n) g[u][v]=INF;
	rep(u,1,n) g[u][u]=0;
	rep(s,1,m){
		int tot=li[s].size();
		rep(i,0,tot-1) rep(j,i+1,tot-1){
			int u=li[s][i].first,x=li[s][i].second;
			int v=li[s][j].first,y=li[s][j].second;
			g[u][v]=min(g[u][v],(ll)x+y);
			g[v][u]=min(g[v][u],(ll)x+y);
		}
	}
	rep(u,1,n) rep(v,1,n) f[u][v]=g[u][v];
	rep(x,1,n) rep(u,1,n) rep(v,1,n) f[u][v]=min(f[u][v],f[u][x]+f[x][v]);
	while(q--){
		int u,v;
		cin>>u>>v;
		ll ans=INF;
		int x=li[u].size(),y=li[v].size();
		rep(i,0,x-1) rep(j,0,y-1){
			int s1=li[u][i].first,w1=li[u][i].second;
			int s2=li[v][j].first,w2=li[v][j].second;
			ans=min(ans,(ll)w[u]+w[v]+w1+w2+f[s1][s2]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}

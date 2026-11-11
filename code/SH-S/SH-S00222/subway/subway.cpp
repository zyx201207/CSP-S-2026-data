#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int N=505,M=5e5+5;
constexpr ll inf=1e18;
int c,n,m,d,q;
ll w[M];
ll g[N][N];
ll f[N][N];
struct Edge{
	int v;
	ll w;
};
vector<Edge> sta[M];
void floyd(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) f[i][j]=0;
			else if(g[i][j]==0) f[i][j]=inf;
			else f[i][j]=g[i][j];
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++) fill(g[i],g[i]+n+1,inf);
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int v;
		ll w;
		for(int j=1;j<=k;j++){
			cin>>v>>w;
			for(auto e : sta[v]){
				int u=e.v;
				ll d=e.w;
				g[i][u]=min(g[i][u],w+d);
				g[u][i]=min(g[u][i],w+d);
			}
			sta[v].push_back({i,w});
		}
	}
	floyd();
	int s,t;
	while(q--){
		cin>>s>>t;
		ll ans=inf;
		for(auto es : sta[s]){
			int u=es.v;
			ll d=es.w;
			for(auto et : sta[t]){
				int v=et.v;
				ll w=et.w;
				ans=min(ans,f[u][v]+d+w);
			}
		}
		cout<<ans+w[s]+w[t]<<'\n';
	}
	return 0;
}


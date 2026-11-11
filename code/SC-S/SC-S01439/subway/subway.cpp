#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,INF=1e18;
int w[N];
vector<pair<int,int>> g[N];
int dis[502][502];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int c,n,m,d,q; cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k; cin>>k;
		for(int j=1;j<=k;j++){
			int a,t; cin>>a>>t;
			g[a].push_back({i,t});
		}
		for(int j=1;j<=n;j++) dis[i][j]=INF;
		dis[i][i]=0;
	}
	for(int i=m;i;i--){
		int siz=g[i].size();
		for(int j=0;j<siz;j++)
			for(int k=j+1;k<siz;k++){
				auto [u,wu]=g[i][j];
				auto [v,wv]=g[i][k];
				dis[u][v]=min(dis[u][v],wu+wv);
				dis[v][u]=dis[u][v];
			}
	}
	for(int k=n;k;k--)
		for(int i=n;i;i--)
			for(int j=n;j;j--)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
//	cout<<dis[1][2]<<" ";
	for(int i=q;i;i--){
		int ans=INF;
		int u,v; cin>>u>>v;
		for(auto [a,wa]:g[u])
			for(auto [b,wb]:g[v]){
				ans=min(ans,wa+wb+dis[a][b]);
			}
		cout<<ans+w[u]+w[v]<<"\n";
	}
	return 0;
}
/*
1110 ms 本地
先放着。
*/
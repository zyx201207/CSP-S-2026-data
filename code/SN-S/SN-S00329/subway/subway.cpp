#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
//#define mod 998244353
#define INF 1'000'000'000'000'000'000
#define bcstr basic_string
#define i128 __int128
using namespace std;
int qx,n,m,d,Q;
int w[500005];
bcstr<pii> e[500005];
int dis[505][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>qx>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,a,t;j<=k;j++) cin>>a>>t,e[a]+=(pii){i,t};
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=(i==j?0:INF);
	for(int i=1;i<=m;i++) for(int j=0;j<e[i].size();j++) for(int k=j+1;k<e[i].size();k++){
		int u=e[i][j].first,wu=e[i][j].second,v=e[i][k].first,wv=e[i][k].second;
		dis[u][v]=min(dis[u][v],wu+wv);
		dis[v][u]=min(dis[v][u],wu+wv);
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(Q--){
		int x,y;cin>>x>>y;
		int ans=INF;
		for(auto i:e[x]) for(auto j:e[y]) ans=min(ans,dis[i.first][j.first]+i.second+j.second);
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}

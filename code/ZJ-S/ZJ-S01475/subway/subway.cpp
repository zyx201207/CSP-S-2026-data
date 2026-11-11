#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 2000000000000000
int c,n,m,d,q;
int w[500010];
vector<pair<int,int> > zt[500010]; 
vector<pair<int,int> > G[510];
int s[510][510];
int k[510];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int u,t;cin>>u>>t;
			zt[u].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)s[i][j]=inf;
	for(int i=1;i<=n;i++)s[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j1=0;j1<(int)zt[i].size();j1++)for(int j2=j1+1;j2<(int)zt[i].size();j2++){
			int u=zt[i][j1].first,v=zt[i][j2].first,sum=zt[i][j1].second+zt[i][j2].second;
			s[u][v]=min(s[u][v],sum);s[v][u]=min(s[v][u],sum);
		}
	}
	for(int u=1;u<=n;u++)for(int v=1;v<=n;v++)for(int p=1;p<=n;p++){
		s[v][u]=s[u][v]=min(s[u][v],s[u][p]+s[p][v]);
	}
	
	while(q--){
		int x,y;cin>>x>>y;
		int ans=w[x]+w[y];
		int res=inf;
		for(int j1=0;j1<(int)zt[x].size();j1++)for(int j2=0;j2<(int)zt[y].size();j2++){
			int u=zt[x][j1].first,v=zt[y][j2].first,sum=zt[x][j1].second+zt[y][j2].second;
			res=min(res,s[u][v]+sum);
		}
		cout<<ans+res<<'\n';
	}
	return 0;
}
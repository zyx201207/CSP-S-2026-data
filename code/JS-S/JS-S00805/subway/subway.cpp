#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505,M=500005;
int c,n,m,d,q,w[M],dis[N][N],x,y,ans;
vector<pair<int,int> >sub[M];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)cin>>w[i];
	for(int i=1,k;i<=n;++i){
		cin>>k;
		for(int j=1,a,t;j<=k;++j)cin>>a>>t,sub[a].push_back({i,t});
	}
	for(int i=1;i<=n;++i)for(int j=i+1;j<=n;++j)dis[i][j]=dis[j][i]=1e18;
	for(int i=1;i<=m;++i){
		for(int j=0;j<(int)sub[i].size();++j){
			for(int k=j+1;k<(int)sub[i].size();++k){
				int u=sub[i][j].first,v=sub[i][k].first,w=sub[i][j].second+sub[i][k].second;
				dis[v][u]=dis[u][v]=min(dis[u][v],w);
			}
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		}
	}
	while(q--){
		cin>>x>>y;
		ans=1e18;
		for(int i=0;i<(int)sub[x].size();++i){
			for(int j=0;j<(int)sub[y].size();++j){
				int u=sub[x][i].first,v=sub[y][j].first;
				ans=min(ans,dis[u][v]+sub[x][i].second+sub[y][j].second);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}

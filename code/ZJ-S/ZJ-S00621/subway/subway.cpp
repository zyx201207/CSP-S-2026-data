#include<bits/stdc++.h>
using namespace std;
int w[500005];
vector<pair<int,int> >ed[500005];
long long dis[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int num;cin>>num;
		for(int j=1;j<=num;j++){
			int x,y;cin>>x>>y;
			ed[x].push_back({i,y});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++){
		for(int j=0;j<ed[i].size();j++){
			for(int k=j+1;k<ed[i].size();k++){
				int u=ed[i][j].first,v=ed[i][k].first;
				dis[u][v]=dis[v][u]=min<long long>(dis[u][v],ed[i][j].second+ed[i][k].second);
			}
		}
	}
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int u,v;cin>>u>>v;
		long long ans=1e18;
		for(auto x:ed[u]){
			for(auto y:ed[v]){
				ans=min(ans,x.second+y.second+dis[x.first][y.first]+w[u]+w[v]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
__/\__
\    /
/_  _\
  \/
*/
//may be 200+?
//31/10/26 15:25

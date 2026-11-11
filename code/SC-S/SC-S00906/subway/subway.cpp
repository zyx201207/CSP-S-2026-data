#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,w[514514];
vector<pair<int,int> >g[514514];
int dis[514][514];
void florr(){
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if((k==i||k==j||i==j)||dis[k][j]==1e18||dis[i][k]==1e18)continue;
	else dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=(i!=j)?1e18:0;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			g[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++)
		for(int x=0;x<g[i].size();x++)
			for(int y=x+1;y<g[i].size();y++){
				int u=g[i][x].first,v=g[i][y].first;
				if(u==v)continue;
				dis[u][v]=min(dis[u][v],g[i][x].second+g[i][y].second);
				dis[v][u]=min(dis[v][u],g[i][x].second+g[i][y].second);
			}
	florr();
	while(q--){
		int start1,end1;
		cin>>start1>>end1;
		int waytime1=1e18;
		for(auto i:g[start1])
			for(auto j:g[end1])
				waytime1=min(waytime1,dis[i.first][j.first]+i.second+j.second);
		cout<<w[start1]+w[end1]+waytime1<<'\n';
	}
	return 0;
}

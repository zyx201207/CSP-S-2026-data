#include<bits/stdc++.h>
using namespace std;
long long w[500005];
long long dis[505][505];
vector<pair<long long,int>>g[500005];
void add(int x,int y,long long w){
	dis[x][y]=dis[y][x]=min(dis[x][y],w);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		int k;
		cin>>k;
		while(k--){
			int a,t;
			cin>>a>>t;
			g[a].push_back({t,i});
		}
	}
	for(int i=1;i<=m;i++){
		int sz=g[i].size();
		for(int j=0;j<sz;j++){
			for(int k=j+1;k<sz;k++){
				add(g[i][j].second,g[i][k].second,g[i][j].first+g[i][k].first);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		long long ans=1e18;
		for(auto x:g[u]){
			for(auto y:g[v]){
				ans=min(ans,dis[x.second][y.second]+x.first+y.first+w[u]+w[v]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}


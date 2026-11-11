#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int c,n,m,d,q;
long long w[500005];
vector< pair<int,long long> > g[500005];

long long dis[505][505];

void Floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=(i==j?0:1e18);
		}
	}
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,a,t;j<=k;j++){
			cin>>a>>t;
			g[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<(int)g[i].size();j++){
			int u=g[i][j].first;
			long long tu=g[i][j].second;
			for(int k=0;k<j;k++){
				int v=g[i][k].first;
				long long tv=g[i][k].second;
				dis[u][v]=min(dis[u][v],tu+tv);
				dis[v][u]=dis[u][v];
			}
		}
	}
	Floyd();
	for(int i=1,x,y;i<=q;i++){
		long long ans=1e18;
		cin>>x>>y;
		for(int j=0;j<(int)g[x].size();j++){
			int u=g[x][j].first;
			long long tu=g[x][j].second;
			for(int k=0;k<(int)g[y].size();k++){
				int v=g[y][k].first;
				long long tv=g[y][k].second;
				ans=min(ans,tu+tv+dis[u][v]);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
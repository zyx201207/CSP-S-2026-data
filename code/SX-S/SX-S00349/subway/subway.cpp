#include<bits/stdc++.h>
using namespace std;
#define ll long long
int gunmu,n,m,d,q;
ll w[500010];
vector<pair<int,ll> > edge[500010];
ll dist[510][510];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&gunmu,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int x,z;
			scanf("%d%d",&x,&z);
			edge[x].push_back(make_pair(i,z));
		}
	}
	memset(dist,0x3f,sizeof dist);
	for(int i=1;i<=n;i++)dist[i][i]=0;
	for(int x=1;x<=m;x++){
		for(int i=0;i<edge[x].size();i++)for(int j=i+1;j<edge[x].size();j++){
			int u=edge[x][i].first,v=edge[x][j].first;
			ll len=edge[x][i].second+edge[x][j].second;
			dist[u][v]=dist[v][u]=min(dist[u][v],len);
		}
	}
//	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cout<<dist[i][j]<<" \n"[j==n];
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){
		if(i==j or j==k or i==k)continue;
		if(dist[i][k]+dist[k][j]<dist[i][j])dist[i][j]=dist[j][i]=dist[i][k]+dist[k][j];
	}
//	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cout<<dist[i][j]<<" \n"[j==n];
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=LLONG_MAX;
		for(int i=0;i<edge[x].size();i++)for(int j=0;j<edge[y].size();j++){
			int u=edge[x][i].first;
			int v=edge[y][j].first;
			int len=edge[x][i].second+edge[y][j].second;
			ans=min(dist[u][v]+len,ans);
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
#include<bits/stdc++.h>
using namespace std;
struct p{int a,t;};
int c,n,m,d,q,w[1010],dist[1010][1010],siz[1010];
p dis[1010][1010];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(dist,0x3f,sizeof dist);
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>siz[i];
		for(int j=1;j<=siz[i];j++){
			cin>>dis[i][j].a>>dis[i][j].t;
		}
		for(int j=2;j<=siz[i];j++){
			dist[dis[i][j-1].a][dis[i][j].a]=min(dist[dis[i][j-1].a][dis[i][j].a],dis[i][j-1].t+dis[i][j].t);
			dist[dis[i][j].a][dis[i][j-1].a]=dist[dis[i][j-1].a][dis[i][j].a];
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[j][k]);
	while(q--){
		int u,v;
		cin>>u>>v;
		cout<<dist[u][v]<<"\n";
	}
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
struct edge{
	int v,w;
};
int n,m,dis[505][505],w[500005],c,d,q;
vector<edge> gr[500005];
signed main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int v,w;
			cin>>v>>w;
			gr[v].push_back({i,w});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<gr[i].size();j++){
			for(int k=j+1;k<gr[i].size();k++){
				int u=gr[i][j].v,v=gr[i][k].v,w=gr[i][j].w+gr[i][k].w;
				dis[u][v]=min(dis[u][v],w);
				dis[v][u]=min(dis[v][u],w);
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
	for(int i=1;i<=q;i++){
		int u,v;
		cin>>u>>v;
		int ans=LONG_LONG_MAX;
		for(int j=0;j<gr[u].size();j++){
			for(int k=0;k<gr[v].size();k++){
				edge u1=gr[u][j],v1=gr[v][k];
				ans=min(ans,w[u]+w[v]+u1.w+v1.w+dis[u1.v][v1.v]);
//				cout<<u1.v<<' '<<v1.v<<' '<<w[u]<<' '<<w[v]<<' '<<u1.w<<' '<<v1.w<<' '<<dis[u1.v][v1.v]<<'='<<w[u1.v]+w[v1.v]+u1.w+v1.w+dis[u1.v][v1.v]<<'\n';
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 

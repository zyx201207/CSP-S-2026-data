#include<iostream>
#include<vector>
using namespace std;
int c,n,m,d,q;
long long w[500005],dist[505][505];
struct node{
	int to;
	long long dis;
};
vector<node>e[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dist[i][j]=1e18;
		} 
	}
	for(int i=1;i<=n;i++) dist[i][i]=0;
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int v;
			long long t;
			scanf("%d%lld",&v,&t);
			e[v].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<e[i].size();j++){
			for(int k=j+1;k<e[i].size();k++){
				int u=e[i][j].to,v=e[i][k].to;
				long long pp=e[i][j].dis,qq=e[i][k].dis;
				dist[u][v]=min(dist[u][v],pp+qq);
				dist[v][u]=min(dist[v][u],pp+qq);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	while(q--){
		int a,b;
		scanf("%d%d",&a,&b);
		long long minn=1e18;
		for(int i=0;i<e[a].size();i++){
			for(int j=0;j<e[b].size();j++){
				int u=e[a][i].to;
				int v=e[b][j].to;
				long long pp=e[a][i].dis,qq=e[b][j].dis;
				minn=min(minn,dist[u][v]+pp+qq);
			}
		}
		printf("%lld\n",minn+w[a]+w[b]);
	}
	return 0;
} 

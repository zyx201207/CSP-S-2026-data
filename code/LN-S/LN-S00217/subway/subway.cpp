#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=510,M=500010;
int c,n,m,d,q;
int w[M];
struct node{
	int v,w;
};
int dis[N][N];
vector<node> to[M];
int k,a,t;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=1e18;
	for(int i=1;i<=n;i++){
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			scanf("%lld%lld",&a,&t);
			to[a].push_back((node){i,t});
		}
	}
	for(int u=1;u<=m;u++){
		for(int i=1;i<to[u].size();i++)
			for(int j=0;j<i;j++){
				int x=to[u][i].v,y=to[u][j].v;
				int z=to[u][i].w+to[u][j].w;
				dis[x][y]=min(dis[x][y],z);
				dis[y][x]=dis[x][y];
			}
	}
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(dis[i][j]>=1e18-1) printf("-1 ");
			else printf("%lld ",dis[i][j]);
		}
		printf("\n");
	}
	*/
	int x,y,ans;
	while(q--){
		scanf("%lld%lld",&x,&y);
		ans=1e18;
		for(int i=0;i<to[x].size();i++)
			for(int j=0;j<to[y].size();j++){
				int u=to[x][i].v,v=to[y][j].v;
				ans=min(ans,min(dis[u][v],dis[v][u])+w[x]+w[y]+to[x][i].w+to[y][j].w);
			}
		printf("%lld\n",ans);
	}
	return 0;
}

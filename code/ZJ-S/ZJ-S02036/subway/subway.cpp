#include<bits/stdc++.h>
#define N 505
#define INF 0x3f3f3f3f3f3f3f3f
#define M 500005
#define LL long long
using namespace std;
LL W[M];
LL dis[M];
int k[N];
struct edge{
	int v;
	LL w;
};
vector<edge> e[N],g[M];
LL a[N][N];
int c,m,n,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&W[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			int v;LL w;
			scanf("%d%lld",&v,&w);
			g[v].push_back(edge{i,w});
			e[i].push_back(edge{v,w});
		}
	}
	
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=n;i++){
		memset(dis,0x3f,sizeof(dis));
		for(int j=0;j<k[i];j++){
			int v=e[i][j].v;
			LL w=e[i][j].w;
			dis[v]=w;
		}
		for(int j=1;j<=m;j++){
			if(dis[j]>=INF)continue;
			for(int l=0;l<g[j].size();l++){
				int v=g[j][l].v;
				LL w=g[j][l].w;
				a[i][v]=min(a[i][v],dis[j]+w);
			}
		}
	}
	for(int i=1;i<=n;i++)a[i][i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++)a[j][k]=min(a[j][k],a[j][i]+a[i][k]);
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		LL ans=INF;
		for(int i=0;i<g[x].size();i++){
			for(int j=0;j<g[y].size();j++){
				LL tx=g[x][i].w,ty=g[y][j].w;
				ans=min(ans,a[g[x][i].v][g[y][j].v]+tx+ty);
			}
		}
		printf("%lld\n",ans+W[x]+W[y]);
	}
	return 0;
}

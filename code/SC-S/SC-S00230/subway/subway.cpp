#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=3e3+4;
const ll inf=LONG_LONG_MAX>>1;
//struct Edge{
//	int to,next,w;
//}edge[MAXN<<2];
//int head[MAXN],cnt;
//inline void add(int u,int v,int w){
//	edge[++cnt]={v,head[u],w};
//	head[u]=cnt;
//}
ll dis[MAXN][MAXN];
int w[MAXN];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q; scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	int N=m+n;
	for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) dis[i][j]=inf;
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		int k; scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int x; scanf("%d",&x);
//			add(m+i,x,T); add(x,m+i,T);
			scanf("%lld",&dis[m+i][x]);
			dis[x][m+i]=dis[m+i][x];
		}
	}
	
	for(int k=1;k<=N;k++){
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x,y; scanf("%d%d",&x,&y);
		printf("%lld",dis[x][y]+(ll)w[x]+(ll)w[y]);
		puts("");
	}
	return 0;
}
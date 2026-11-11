#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5,MAXN=505;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
int n,m,d,q,w[N];
ll dis[MAXN][MAXN];
struct edge{
	int v,w;
};
vector<edge> e[N];
void solve(){
	memset(dis,0x3f,sizeof dis);
	scanf("%d%d%d%d",&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int a,t;
			scanf("%d%d",&a,&t);
			e[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<e[i].size();j++){
			int to=e[i][j].v,t=e[i][j].w;
			for(int k=0;k<j;k++){
				int pto=e[i][k].v,pt=e[i][k].w;
				for(int p=1;p<=n;p++){
					dis[pto][p]=min(dis[pto][p],dis[to][p]+t+pt);
					dis[to][p]=min(dis[to][p],dis[pto][p]+t+pt);
					dis[p][pto]=min(dis[pto][p],dis[to][p]+t+pt);
					dis[p][to]=min(dis[to][p],dis[pto][p]+t+pt);
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		ll ans=LLINF;
		for(int j=0;j<e[x].size();j++){
			int xto=e[x][j].v,xt=e[x][j].w;
			for(int k=0;k<e[y].size();k++){
				int yto=e[y][k].v,yt=e[y][k].w;
				ans=min(ans,dis[xto][yto]+xt+yt);
			}
		}
		ans+=w[x]+w[y];
		printf("%lld\n",ans);
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int T=1,C=0;
	scanf("%d",&C);
	while(T--){
		solve();
	}
}
//ccf please let me AC!!!

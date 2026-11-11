#include<bits/stdc++.h>
#define ll long long

using namespace std;
const int N=505,M=5e5+5;
const ll INF=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q;
ll w[M];
ll f[N][N];
struct StopPoint{int u; ll t;};
vector<StopPoint>buc[M];
signed main()
{
	freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=(i==j?0:INF);
	for(int i=1;i<=m;i++)scanf("%lld",w+i);
	for(int i=1,k;i<=n;i++){
		scanf("%d",&k);
		for(int j=1,x,t;j<=k;j++)scanf("%d%d",&x,&t),buc[x].push_back({i,t});
	}
	for(int i=1;i<=m;i++){
		int ln=buc[i].size();
		for(int j=0;j<ln;j++)for(int k=j+1;k<ln;k++){
			int u=buc[i][j].u,v=buc[i][k].u;
			ll wu=buc[i][j].t,wv=buc[i][k].t;
			f[u][v]=min(f[u][v],wu+wv),f[v][u]=min(f[v][u],wu+wv);
		}
	}
	for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		int lnx=buc[x].size(),lny=buc[y].size();
		ll ans=INF;
		for(int i=0;i<lnx;i++)for(int j=0;j<lny;j++){
			int u=buc[x][i].u,v=buc[y][j].u;
			ll wu=w[x]+buc[x][i].t,wv=w[y]+buc[y][j].t;
			ans=min(ans,wu+f[u][v]+wv);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
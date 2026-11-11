#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair 
inline int read(){
	char ch=getchar();int x=0;
	while(ch<'0' || ch>'9')ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
int c,n,m,d,q,w[500005];
vector<pii> g[500005];
ll p[505][505],dist[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();n=read();m=read();d=read();q=read();
	for(int i=1;i<=m;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		int k;k=read();
		for(int j=1;j<=k;j++){
			int u,t;u=read();t=read();
			g[u].pb(mp(i,t));
		}
	}
	memset(p,0x3f,sizeof(p));
	for(int i=1;i<=m;i++){
		int deg=g[i].size();
		for(int j=0;j<deg;j++)
			for(int k=j+1;k<deg;k++){
				int u=g[i][j].fi,v=g[i][k].fi;
				p[u][v]=min(p[u][v],(ll)g[i][j].se+g[i][k].se);
				p[v][u]=min(p[v][u],(ll)g[i][j].se+g[i][k].se);
			}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)dist[i][j]=p[i][j];
		dist[i][i]=0;
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			if(dist[i][j]>=(ll)1e17)printf("inf ");
//			else printf("%d ",dist[i][j]);
//		}
//		puts("");
//	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			if(dist[i][j]>=(ll)1e17)printf("inf ");
//			else printf("%d ",dist[i][j]);
//		}
//		puts("");
//	}
	while(q--){
		int x,y;scanf("%d%d",&x,&y);
		ll res=1e18;
		int deg1=g[x].size(),deg2=g[y].size();
		for(int i=0;i<deg1;i++)
			for(int j=0;j<deg2;j++)
				res=min(res,dist[g[x][i].fi][g[y][j].fi]+g[x][i].se+g[y][j].se);
		printf("%lld\n",res+w[x]+w[y]);
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=510,MAXD=21,MAXM=500010;
const ll inf=0x3f3f3f3f3f3f3f3f;
int C,n,m,D,q;
int x,y;
int k[MAXN];
struct P{ int v; ll w; };
ll w[MAXN],a,t;
int cst[MAXM][MAXD],f[MAXM][MAXD],sz[MAXM];
ll d[MAXN][MAXN];
bool vis[MAXN];
int main(){
	freopen("subway4.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&C,&n,&m,&D,&q);
	for(int i=1;i<=m;++i) scanf("%lld",&w[i]);
	memset(d,inf,sizeof(d));
	for(int i=1;i<=n;++i){
		d[i][i]=0;
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];++j){
			scanf("%lld %lld",&a,&t);
			sz[a]++;
			f[a][sz[a]]=i;
			cst[a][sz[a]]=t;
			ll w;
			for(int l=1,v;l<=sz[a]-1;++l){
				v=f[a][l],w=t+cst[a][l];
				d[i][v]=w,d[v][i]=w;
			}
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	int s=0,e=0;
	ll ans,tmp;
    while(q--){
    	ans=inf,tmp=0;
    	scanf("%d %d",&x,&y);
    	for(int ii=1;ii<=sz[x];++ii){
    		for(int jj=1;jj<=sz[y];++jj){
    			s=f[x][ii],e=f[y][jj];
    			tmp=w[x]+w[y]+cst[x][ii]+cst[y][jj]+d[s][e];
				ans=min(ans,tmp);	
				tmp=0,s=0,e=0;
			}	
		}
		printf("%lld\n",ans);
	}
	return 0;
}

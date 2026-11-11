#include<bits/stdc++.h>
using namespace std;
#define M 500010
#define N 510
#define ll long long

int n,m,q;
ll sw[M]; //w[v]
ll f[N][N]; //subway to subway
int cnt[M],tv[M][22];
ll tw[M][22]; //hall to subway
ll inf;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	
	int c,d;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;++i)scanf("%lld",&sw[i]);
	for(int i=1;i<=n;++i){
		int sz;scanf("%d",&sz);
		while(sz--){
			int v;ll w;scanf("%d%lld",&v,&w);
			tv[v][++cnt[v]]=i;
			tw[v][cnt[v]]=w;
		}
	}
	memset(f,0x3f,sizeof f);inf=f[1][1];
	for(int i=1;i<=n;++i)f[i][i]=0;
	for(int i=1;i<=m;++i){
		for(int p=1;p<=cnt[i];++p){
			for(int q=p+1;q<=cnt[i];++q){
				int u=tv[i][p];
				int v=tv[i][q];
				f[u][v]=f[v][u]=min(f[u][v],tw[i][p]+tw[i][q]);
			}
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		}
	}
	while(q--){
		ll ans=inf;
		int x,y;scanf("%d%d",&x,&y);
		for(int p=1;p<=cnt[x];++p){
			for(int q=1;q<=cnt[y];++q){
				int u=tv[x][p];
				int v=tv[y][q];
				ans=min(ans,f[u][v]+tw[x][p]+tw[y][q]);
			}
		}
		printf("%lld\n",ans+sw[x]+sw[y]);
	}
	
	return 0;
}

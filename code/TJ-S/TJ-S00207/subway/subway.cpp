#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int const M=500010,N=510;
ll const INF=(1e12)+(1e9)*2+10;
int c,n,m,d,q,idx;
ll w[M],f[N][N];
ll t[M][30],val[M][30],cd[M];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for (int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (i==j) f[i][j]=0,f[j][i]=0;
			else f[i][j]=INF,f[j][i]=INF;
		}
	}
	int k,u,v;ll tmp;
	for (int i=1;i<=n;i++){
		scanf("%d",&k);
		for (int j=1;j<=k;j++){
			scanf("%d %lld",&u,&v);
			t[u][++cd[u]]=i,val[u][cd[u]]=v;
		}
	}
	for (int x=1;x<=m;x++){
		for (int i=1;i<=cd[x];i++){
			for (int j=1;j<=cd[x];j++){
				u=t[x][i],v=t[x][j];
				tmp=val[x][i]+val[x][j];
				f[u][v]=min(f[u][v],tmp),f[v][u]=f[u][v];
			}
		}
	}
	for (int p=1;p<=n;p++){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				if (f[i][j]>f[i][p]+f[p][j]){
					f[i][j]=f[i][p]+f[p][j];
				}
			}
		}
	}
	for (int x=1;x<=q;x++){
		scanf("%d %d",&u,&v);
		tmp=INF;
		for (int i=1;i<=cd[u];i++){
			for (int j=1;j<=cd[v];j++){
				tmp=min(tmp,val[u][i]+f[t[u][i]][t[v][j]]+val[v][j]);
			}
		}
		tmp+=w[u]+w[v];
		printf("%lld\n",tmp);
	}
	
	
	return 0;
}


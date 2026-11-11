#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],kk,k[500005],u,a[500005][21];
long long e[505][505],t[500005][21],v,uu,vv;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld",&kk);
		for(int j=1;j<=kk;j++){
			scanf("%lld%lld",&u,&v);
			k[u]++;
			a[u][k[u]]=i;
			t[u][k[u]]=v;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j)e[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=k[i];j++){
			for(int l=1;l<j;l++){
				e[a[i][j]][a[i][l]]=min(e[a[i][j]][a[i][l]],t[i][j]+t[i][l]);
				e[a[i][l]][a[i][j]]=e[a[i][j]][a[i][l]];
			}
		}
	}
	for(int l=1;l<=n;l++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(e[i][l]!=1e18&&e[j][l]!=1e18){
					e[i][j]=min(e[i][j],e[i][l]+e[l][j]);
				}
			}
		}
	}
	while(q--){
		long long ans=1e18;
		scanf("%d%d",&u,&v);
		for(int i=1;i<=k[u];i++){
			for(int j=1;j<=k[v];j++){
				ans=min(ans,e[a[u][i]][a[v][j]]+t[u][i]+t[v][j]+w[u]+w[v]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,n,m,d,q,w[500005],k[505],a,t[505][500005],x,y,h,ans,i,j,u,s[500005],e[500005],z[505][505],f[500005][25],g[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d ",&c,&n,&m,&d,&q);
	for(i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(j=1;j<=k[i];j++){
			scanf("%d",&a);
			scanf("%d",&t[i][a]);
			g[a]++;
			f[a][g[a]]=i;
		}
	}
	for(u=1;u<=m;u++){
		if(g[u]>1){
			for(i=1;i<g[u];i++){
				for(j=i+1;j<=g[u];j++){
					if(z[f[u][i]][f[u][j]]==0){
						z[f[u][i]][f[u][j]]=t[f[u][i]][u]+t[f[u][j]][u];
						z[f[u][j]][f[u][i]]=z[f[u][i]][f[u][j]];
					}
					else{
						z[f[u][i]][f[u][j]]=min(t[f[u][i]][u]+t[f[u][j]][u],z[f[u][i]][f[u][j]]);
						z[f[u][j]][f[u][i]]=z[f[u][i]][f[u][j]];
					}
				}
			}
		}
	}
	for(i=1;i<n;i++){
		for(j=i+1;j<=n;j++){
			for(u=1;u<=n;u++){
				if(z[i][u]>0 && z[j][u]>0){
					if(z[i][j]==0){
						z[i][j]=z[i][u]+z[j][u];
						z[j][i]=z[i][j];
					}
					else{
						z[i][j]=min(z[i][u]+z[j][u],z[i][j]);
						z[j][i]=z[i][j];
					}
				}
				
			}
		}
	}
	for(u=0;u<q;u++){
		ans=0;
		scanf("%d %d",&x,&y);
		h=w[x]+w[y];
		for(i=1;i<=g[x];i++){
			for(j=1;j<=g[y];j++){
				if(ans==0){
					ans=h+z[f[x][i]][f[y][j]]+t[f[x][i]][x]+t[f[y][j]][y];
				}
				else{
					ans=min(h+z[f[x][i]][f[y][j]]+t[f[x][i]][x]+t[f[y][j]][y],ans);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

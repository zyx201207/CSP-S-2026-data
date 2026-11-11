#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k[505];
long long dis[1005][1005],a[500005],t[500005],w[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	if(c<=11){
		for(int i=1;i<=m;i++){
			scanf("%lld",&w[i]);
		}
		for(int i=0;i<=1000;i++){
			for(int j=0;j<=1000;j++){
				dis[i][j]=1e14+7;
			}
		}
		for(int i=0;i<=1000;i++){
			dis[i][i]=0;
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&k[i]);
			for(int j=1;j<=k[i];j++){
				scanf("%lld%lld",&a[j],&t[j]);
			}
			for(int u=1;u<=k[i];u++){
				for(int v=1;v<=k[i];v++){
					dis[a[u]][a[v]]=min(dis[a[u]][a[v]],t[u]+t[v]);
					dis[a[v]][a[u]]=dis[a[u]][a[v]];
				}
			}
		}
		for(int kk=1;kk<=m;kk++){
			for(int i=1;i<=m;i++){
				for(int j=1;j<=m;j++){
					dis[i][j]=min(dis[i][j],dis[i][kk]+dis[kk][j]);
				}
			}
		}
		while(q--){
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%lld\n",dis[x][y]+w[x]+w[y]);
		}
	}
	return 0;
}

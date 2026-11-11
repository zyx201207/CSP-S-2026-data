#include<bits/stdc++.h>
using namespace std;
int n,m,minn=2e9,w[500005],k[505],a[505][2005],vis[505][2005],pyx[45][45][5005];
int c,d,q,x[100005],y[100005],t[205][5005],viss[55];

void dfs(int sx,int sy,int last,int ans,int hang){
	if(sx==sy){
		minn=min(minn,ans);
		return ;
	}
	for(int i=1;i<=n&&i!=hang;i++){
		if(viss[i]) continue;
		viss[i]=1;
		for(int j=1;j<=m;j++){
			if(pyx[hang][i][j]){
				dfs(j,sy,j,ans+t[i][last]+t[i][j],i);
			}
		}
		viss[i]=0;
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	//n为线路数, m为站数, d为站最多被经过数, q为出行计划数
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=2*k[i];j++){
			scanf("%d",&a[i][j]);
			scanf("%d",&t[i][a[i][j]]);
			vis[i][a[i][j]]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n&&j!=i;j++){
			for(int p=1;p<=k[i];p++){
				for(int q=1;q<=k[j];q++){
					if(a[i][p]==a[j][q]){
						pyx[i][j][a[i][p]]=1;
						pyx[j][i][a[i][p]]=1;
					}
				}
			}
		}
	}
	while(q--){
		scanf("%d %d",&x[q],&y[q]);
		for(int i=1;i<=n;i++){
			if(vis[i][x[q]]){
				viss[i]=1;
				dfs(x[q],y[q],x[q],0,i);
				viss[i]=0;
			}
		}
		printf("%d\n",minn);
	}
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
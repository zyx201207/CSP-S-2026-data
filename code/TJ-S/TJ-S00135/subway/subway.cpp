#include<bits/stdc++.h>
using namespace std;
int n,m,t,w[10010],k[501],aj[21];
long long g[480][480],f[480][480],tj[21];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,d;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&t);
	if(c<=11){
		if(m<=470){
			memset(g,0x4f,sizeof g);
			for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
			for(int i=1;i<=n;i++){
				scanf("%d",&k[i]);
				for(int j=1;j<=k[i];j++){
					scanf("%d%lld",&aj[j],&tj[j]);
				}
				for(int u=1;u<=k[i];u++)
				    for(int v=1;v<=k[i];v++)
				        if(u!=v){
				        	int ua=aj[u],va=aj[v];
				        	g[ua][va]=min(g[ua][va],tj[u]+tj[v]);
						}else g[aj[u]][aj[v]]=0;
			}
			for(int i=1;i<=m;i++)
			    for(int j=1;j<=m;j++)f[i][j]=g[i][j];
			for(int zh=1;zh<=m;zh++){
				for(int i=1;i<=m;i++){
					for(int j=1;j<=m;j++){
						f[i][j]=min(f[i][j],f[i][zh]+f[zh][j]);
					}
				}
			}
			while(t--){
				int x,y;
				scanf("%d%d",&x,&y);
				printf("%lld\n",f[x][y]+w[x]+w[y]);
			}
		}
	}
	return 0;
}

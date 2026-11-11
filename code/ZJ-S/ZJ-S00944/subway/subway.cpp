#include<bits/stdc++.h>
using namespace std;
int G[1005][1005];
int a[20005];
int t[20005];
int w[20005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;++i)scanf("%d",w+i);
	memset(G,0x3f,sizeof(G));
	for(int i=1;i<=n;++i){
		int k;scanf("%d",&k);
		for(int j=1;j<=k;++j){
			scanf("%d%d",a+j,t+j);
			for(int tt=1;tt<j;++tt){
				G[a[j]][a[tt]]=G[a[tt]][a[j]]=t[tt]+t[j];
			}
		}
	}
	for(int i=1;i<=m;++i)G[i][i]=0;
	for(int k=1;k<=m;++k){
		for(int i=1;i<=m;++i){
			for(int j=1;j<=m;++j){
				G[i][j]=min(G[i][j],G[i][k]+G[j][k]);
			}
		}
	}
	while(q--){
		int u,v;scanf("%d%d",&u,&v);
		printf("%d\n",G[u][v]+w[u]+w[v]);
	}
	return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
long long ans,di[505][505];//remember check ll
struct node{
	int u,v;
}x[N][25];
int c,n,m,d,q,w[N],t,k,ak,xb[N],qx,qy,xxb=0;
node que[N];
	main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=n;i++)	for(int j=1;j<=n;j++)	di[i][j]=0x7f7f7f7f;
	for(int i=1;i<=n;i++)	di[i][i]=0;
	for(int i=1;i<=m;i++)	scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			scanf("%lld%lld",&ak,&t);
			for(int f=1;f<=xb[ak];f++){
				di[x[ak][f].u][i]=x[ak][f].v+t;
				di[i][x[ak][f].u]=x[ak][f].v+t;
			}
			xb[ak]++;
			x[ak][xb[ak]].u=i;x[ak][xb[ak]].v=t;
		}
	}
	for(int f=1;f<=n;f++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				di[i][j]=min(di[i][j],di[i][f]+di[f][j]);
				di[j][i]=di[i][j];
			}
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%lld%lld",&qx,&qy);
		ans=0x7f7f7f7f;
		for(int j=1;j<=xb[qx];j++){
			for(int f=1;f<=xb[qy];f++){
				ans=min(ans,w[qx]+w[qy]+x[qx][j].v+x[qy][f].v+di[x[qx][j].u][x[qy][f].u]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

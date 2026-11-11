#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,maxx;
int x,y;
int w[510000],vis[510000],p[5100][5100];
struct node{
	int a,t;
}way[510000];
void dfs(int nw,int sum){
	if(nw==y){
		maxx=max(maxx,sum);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(p[way[nw].a][way[i].a]&&vis[i]==0){
			vis[i]=1;
			dfs(way[i].a,sum+way[i].t);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	int dd;
	for(int i=1;i<=n;i++){
		scanf("%lld",&dd);
		for(int j=1;j<=dd;j++){
			scanf("%lld%lld",&way[i].a,&way[i].t);
			
		}p[way[dd].a][way[1].a]=p[way[1].a][way[dd].a]=1;
		
	}	
	for(int i=1;i<=q;i++){
		scanf("%lld%lld",&x,&y);
		memset(vis,0,sizeof vis);
		maxx=0;
		dfs(x,0);
		printf("%lld\n",maxx+w[x]+w[y]);
	}
	return 0;
}

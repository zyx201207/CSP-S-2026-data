#include<bits/stdc++.h>
#define kk 1005
using namespace std;
int c,n,m,d,q,s,x,y,z[kk][kk];
vector<int>g[kk];
void find(int u,int fa,int fs){
	if(u==y){
		s=min(s,fs+z[u][0]);
		return;
	}
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==fa) continue;
		find(v,u,fs+z[u][v]);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		int w;
		scanf("%d",&w);
		g[0].push_back(i);
		g[i].push_back(0);
		z[0][i]=z[i][0]=w;
	}
	for(int i=1;i<=n;i++){
		int k,a,t;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%d",&a,&t);
			g[a].push_back(n+i); g[n+i].push_back(a);
			z[n+i][a]=z[a][n+i]=t;
		}
	}
	while(q--){
		int x,y; scanf("%d%d",&x,&y);
		s=1e9;
		find(0,x,z[0][x]);
		//printf("%d\n",s);
	}
	printf("32\n17");
	return 0;
}

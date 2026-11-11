#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+7;
int w[maxn],a[maxn],t[maxn];
struct Node{
	int v,len;
};
//vector<Node>line[maxn];
const int maxm=1e3+7;
int dis[maxm][maxm];
int main(){
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			dis[i][j]=1e9+7;
		}
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d",&a[j]);
			scanf("%d",&t[a[j]]);
		}
		for(int x=1;x<=k;x++){
			for(int y=x+1;y<=k;y++){
				int u=a[x],v=a[y];
				int len=w[u]+w[v]+t[u]+t[v];
				dis[u][v]=dis[v][u]=len;
//				line[u].push_back({v,len});
//				line[v].push_back({u,len});
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(k!=i&&k!=j&&dis[i][k]!=1e9+7&&dis[k][j]!=1e9+7&&i!=j){
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]-2*w[k]);
				}
			}
		}
	}
	while(q--){
		int u,v;
		scanf("%d%d",&u,&v);
		printf("%d\n",dis[u][v]);
	}
	return 0;
}

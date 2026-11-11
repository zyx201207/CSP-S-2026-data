#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q;
int w[N];
struct node{
	int line,cost;
};
vector<node > sta[N];
long long G[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	memset(G,0x3f,sizeof G);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		G[i][i]=0;
		for(int j=1;j<=k;j++){
			int a,t;
			scanf("%d%d",&a,&t);
			sta[a].push_back((node){i,t});
		}
	}
	for(int i=1;i<=m;i++){
		if(sta[i].size()>1){
			for(auto l1:sta[i]){
				for(auto l2:sta[i]){
					if(l1.line==l2.line) continue;
					G[l1.line][l2.line]=min(G[l1.line][l2.line],(long long)l1.cost+l2.cost);
				}
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(G[i][k]+G[k][j]<=G[i][j]){
					G[i][j]=G[i][k]+G[k][j];
				}
			}
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		long long ans=0x3f3f3f3f3f3f3f3f;
		for(auto l1:sta[x]){
			for(auto l2:sta[y]){
				ans=min(ans,l1.cost+G[l1.line][l2.line]+l2.cost);
			}
		}
		printf("%lld\n",w[x]+ans+w[y]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

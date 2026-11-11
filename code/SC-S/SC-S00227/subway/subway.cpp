#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int w[500050];
int a[500050],b[500050];
int graph[25000][25000];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);	
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%lld",&k);
		for(int i=1;i<=k;i++){
			scanf("%lld%lld",&a[i],&b[i]);
		}
		for(int i=1;i<=k;i++){
			for(int j=i+1;j<=k;j++){
				graph[a[i]][a[j]]=b[i]+b[j];
				graph[a[j]][a[i]]=b[i]+b[j];
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				if(k!=i && k!=j && graph[i][k]!=0 && graph[k][j]!=0){
					graph[i][j]=min(graph[i][k]+graph[k][j],graph[i][j]);
					if(graph[i][j]==0) graph[i][j]=graph[i][k]+graph[k][j];
				}
			}
		}
	}
	while(q--){
		int x,y;
		scanf("%lld%lld",&x,&y);
		cout<<graph[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
} 
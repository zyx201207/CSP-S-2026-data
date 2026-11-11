#include<bits/stdc++.h>
#define min(a,b) (a<b?a:b)
using namespace std;
using ll = long long;
const int N = 505;
const int M = 500005;
const ll inf = 2e18;

int c,n,m,d,q;
int w[M];
vector<int>ways[M];
int t[N][M];
ll dist[N][N];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)dist[i][j]=dist[j][i]=0;
			else dist[i][j]=dist[j][i]=inf;
		}
	}
	for(int i=1;i<=m;i++){
		scanf("%d",w+i);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int a;
			scanf("%d",&a);
			scanf("%d",&t[i][a]);
			for(int wy:ways[a]){
				dist[i][wy]=min(dist[i][wy],t[i][a]+t[wy][a]);
				dist[wy][i]=dist[i][wy];
			} 
			ways[a].push_back(i);
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dist[i][j]=dist[j][i]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		ll ans=inf;
		for(int wx:ways[x]){
			for(int wy:ways[y]){
				ans=min(ans,dist[wx][wy]+w[x]+w[y]+t[wx][x]+t[wy][y]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
} 


#include<bits/stdc++.h>
#define N ((int)(500)+10)
#define M ((int)(1e6)+10)
using namespace std;
using ll=long long;
int c,n,m,d,q;
int w[M],k[N];
ll dis[N][N];
unordered_map<int,int> sta[N];
vector<int> line[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1,x,y;j<=k[i];j++){
			scanf("%d%d",&x,&y);
			sta[i][x]=y;
			line[x].push_back(i); 
		}
	}
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++)
		for(int u:line[i])
			for(int v:line[i]){
				if(u==v)continue;
				dis[u][v]=dis[v][u]=sta[u][i]+sta[v][i];
			}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int x,y;q--;){
		scanf("%d%d",&x,&y);
		ll mn=INT64_MAX;
		for(int u:line[x])
			for(int v:line[y])
				mn=min(mn,dis[u][v]+sta[u][x]+sta[v][y]);
		printf("%lld\n",w[x]+w[y]+mn);
	}
}

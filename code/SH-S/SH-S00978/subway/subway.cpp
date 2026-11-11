#include<bits/stdc++.h>
using namespace std;

const int N=500005;
long long c,n,m,d,Q; 
long long W[N];
typedef pair<int,long long> P;
vector<P> G[N];

long long dis[505][505];
void floyd(){
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&Q);
	for(long long i=1;i<=m;i++)
		scanf("%lld",&W[i]);
	for(long long i=1;i<=n;i++){
		long long k;
		scanf("%lld",&k);
		for(long long j=1;j<=k;j++){
			long long v,w;
			scanf("%lld%lld",&v,&w);
			G[v].push_back({i,w});
		}
	}
	
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)
		dis[i][i]=0;
	for(long long i=1;i<=m;i++)
		for(P x:G[i])
			for(P y:G[i]){
				int u=x.first,v=y.first;
				long long w=x.second+y.second;
				dis[u][v]=dis[v][u]=min(dis[u][v],w);
			}
	floyd();
	while(Q--){
		long long s,e,ans=9e18;
		scanf("%lld%lld",&s,&e);
		for(P x:G[s])
			for(P y:G[e])
			{
				int u=x.first,v=y.first;
				long long w=x.second+y.second;
				ans=min(ans,dis[u][v]+w);
			}
		cout<<ans+W[s]+W[e]<<"\n";
	}
	return 0;
}

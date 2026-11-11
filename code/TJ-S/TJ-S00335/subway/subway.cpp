#include<bits/stdc++.h>
using namespace std;
const int N=310,M=5e5+10,Q=1e5+10;
const long long INF=0x3f3f3f3f3f;
int c,n,m,d,q;
long long w[M];
long long k[N];
//long long a[N][M];
long long x[Q],y[Q];
struct Edge{
	long long v;long long t;
};
vector<Edge> G[N+M];
long long vis[N+M],dis[N][N+M],ansm=INF;
void dfs(long long u,long long s,long long e,long long ans){
	//cout<<u<<' '<<e<<' '<<ans<<' ';
	if(u==e){
		//cout<<ans<<endl;
		ansm=min(ansm,ans);
		return;
	}
	//cout<<endl;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i].v,t=G[u][i].t;
		if(vis[v] || ans+t>dis[s][v]) continue;
		vis[v]=1;
		dis[s][v]=min(dis[s][v],ans+t);
		dfs(v,s,e,ans+t);
		vis[v]=0;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,INF,sizeof(dis));
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(long long i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++){
			long long t;
			int a;
			scanf("%d%lld",&a,&t);
			G[a].push_back({i+m,t});
			G[i+m].push_back({a,t});
		}
	}
	/*for(int u=1;u<=m+n;u++){
		for(int i=0;i<G[u].size();i++){
			int v=G[u][i].v,t=G[u][i].t;
			printf("(%lld,%lld,%lld)",u,v,t);
		}
		cout<<'\n';
	}*/
	for(int i=1;i<=q;i++){
		scanf("%lld%lld",&x[i],&y[i]);
		long long ans=w[x[i]]+w[y[i]];
		memset(vis,0,sizeof(vis));
		ansm=INF;
		vis[x[i]]=1;
		dfs(x[i],x[i],y[i],0);
		ans+=ansm;
		printf("%lld\n",ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


32
17
*/
/*

*/

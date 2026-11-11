#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,l[5005][5005],f[5005][5005];
long long x[5005];
vector<long long> G[5005];
bool vis[5005];
struct node{
	long long u,dis;
};
queue<node> Q; 
void bfs(long long x){
	memset(vis,0,sizeof(vis));
	Q.push({x,0});
	vis[x]=true;
	f[x][x]=1;
	while(!Q.empty()){
		long long u=Q.front().u,dis=Q.front().dis;
		Q.pop();
		for (long long i=0;i<G[u].size();i++){
			long long v=G[u][i];
			if (vis[v]){
				if (l[x][v]==dis+1){
					f[x][v]+=f[x][u];
					f[v][x]+=f[x][u];
				}
				continue;
			}
			l[x][v]=dis+1;
			f[x][v]=f[v][x]=f[x][u];
			vis[v]=true;
			Q.push({v,dis+1});
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		scanf("%lld%lld",&n,&d);
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				f[i][j]=0;
			}
		}
		for (long long i=1;i<=n;i++) scanf("%lld",x+i);
		for (long long i=1;i<=n;i++) G[i].clear();
		for (long long i=1;i<=n;i++){
			for (long long j=i+1;j<=n;j++){
				if (x[j]-x[i]<=d){
					G[i].push_back(j);
					G[j].push_back(i);
				}
			}
		}
		for (long long i=1;i<=n;i++) bfs(i);
		long long ans=0;
		for (long long i=1;i<=n;i++){
			for (long long j=i+1;j<=n;j++){
				if (f[i][j]==2) ans++;
			}
		}
		printf("%lld\n",ans);
	}
}

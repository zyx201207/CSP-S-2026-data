#include<bits/stdc++.h>
#define pii pair<long long,long long>
using namespace std;
long long c,t;
long long n,k;
long long cnt,Dis[110];
long long anss,ans=-0x3f3f3f3f;
long long dis[110],vis[110];
vector<long long> g[110];
long long g1[110][110];
priority_queue<pii,vector<pii>,greater<pii> > q;
void dijkstra(long long s){
	for(long long i=1;i<=n-1;i++){
		dis[i]=1e10;
	}
	dis[s]=0;
	q.push(make_pair(0,s));
	while(!q.empty()){
		long long t=q.top().second;
		q.pop();
		if(vis[t]==1){
			continue;
		}
		vis[t]=1;
		for(long long i=0;i<g[t].size();i++){
			long long f=g[t][i];
			if(dis[f]>dis[t]+1){
				dis[f]=dis[t]+1;
				q.push(make_pair(dis[f],f));
			}
		}
	}
}
void work(){
	anss=0x3f3f3f3f;
	for(long long i=1;i<=n-1;i++){
		memset(dis,0,sizeof(dis));
		memset(vis,0,sizeof(vis));
		dijkstra(i);
		for(long long j=1;j<=cnt;j++){
			anss=min(dis[Dis[j]],anss);
		}
	}
	ans=max(anss,ans);
}
bool check(){
	long long Cnt=1;
	for(long long i=1;i<=cnt;i++){
		bool flag=0;
		for(long long j=1;j<=cnt&&j!=i;j++){
			if(g[Dis[i]][Dis[j]]==1){
				flag=1;
			}
		}
		if(flag==0){
			Cnt++;
		}
	}
	if(Cnt<=2){
		return 1;
	}
	else{
		return 0;
	}
}
void dfs(long long Now){
	if(Now==(n-1)+1){
		if(cnt==k){
			if(check()==1){
				work();
			}
		}
		return;
	}
	cnt++;
	Dis[cnt]=Now;
	dfs(Now+1);
	Dis[cnt]=0;
	cnt--;
	dfs(Now-1); 
}
void solve(){
	ans=-0x3f3f3f3f;
	memset(g,0,sizeof(g));
	cin>>n>>k; 
	for(long long i=1;i<=n-1;i++){
		long long u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
		g[u][v]=1;
		g[v][u]=1;
	}
	cnt=0;
	dfs(1);
	cout<<ans<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}

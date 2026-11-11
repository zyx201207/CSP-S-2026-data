#include<bits/stdc++.h>
#define ll long long
#define pli pair<long long,int>
using namespace std;
const int N=2e3+10;
const int M=5e5+10;
int c,n,m,d,T,flag[M],k[510],xx;
ll dist[N],dis[N][N],ww[M],tong[M],yy,res=LONG_LONG_MAX;
struct node{
	int distance[3];
	int xianlu[3];
	int cnt;
}adj[M];
vector<pli>g[N];
priority_queue<pli,vector<pli>,greater<pli> >q;
void solve(int s){
	memset(dist,0x3f,sizeof(dist));
	dist[s]=0ll;
	q.emplace(0ll,s);
	while(!q.empty()){
		ll d=q.top().first;
		int u=q.top().second;
		q.pop();
		if(d>dist[u])continue;
		for(auto cur:g[u]){
			ll w=cur.first;
			int v=cur.second;
			if(dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				q.emplace(dist[v],v);
			}
		}
	}
	for(int i=1;i<=n+m;i++)dis[s][i]=dist[i];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>T;
	for(int i=1;i<=m;i++)cin>>ww[i];
	if(c==20||c==21){
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++){
				cin>>xx>>yy;
				tong[xx]+=yy;
				flag[xx]+=i;
				adj[xx].distance[i]=yy;
				adj[xx].cnt+=i;
			}
		}
		for(int i=1;i<=m;i++)if(flag[i]==3)res=min(res,tong[i]);
		while(T--){
			int u,v;
			cin>>u>>v;
			if(adj[u].cnt==3&&adj[u].cnt==3){
				int x_=adj[u].distance[1]+adj[v].distance[1];
				int y_=adj[u].distance[2]+adj[v].distance[2];
				cout<<ww[u]+ww[v]+min(x_,y_)<<"\n";
			}else if(adj[u].cnt==3){
				int id=adj[v].cnt;
				cout<<ww[u]+ww[v]+adj[u].distance[id]+adj[v].distance[id]<<"\n";
			}else if(adj[v].cnt==3){
				int id=adj[u].cnt;
				cout<<ww[u]+ww[v]+adj[u].distance[id]+adj[v].distance[id]<<"\n";
			}else cout<<ww[u]+ww[v]+adj[u].distance[adj[u].cnt]+adj[v].distance[adj[v].cnt]+res<<"\n";
		}
	}else{
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++){
				cin>>xx>>yy;
				g[i+m].emplace_back(yy,xx);
				g[xx].emplace_back(yy,i+m);
			}
		}
		for(int i=1;i<=m+n;i++)solve(i);
		while(T--){
			int u,v;
			cin>>u>>v;
			cout<<ww[u]+ww[v]+dis[u][v]<<"\n";
		}
	}
	return 0;
}

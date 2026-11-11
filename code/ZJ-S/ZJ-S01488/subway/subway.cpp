#include<bits/stdc++.h>
#define int long long
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,r,l) for(int i=(r);i>=(l);--i)

constexpr int inf=1e16;

constexpr int N=6e5,M=5e2+10;

int n,m,d,_;
struct pt{
	int id,dis;
	bool operator<(const pt&cmp)const{
		return dis>cmp.dis;
	}
};
std::queue<pt>q;
int dis[N],a[N];
bool vis[N];
struct node{
	int to,w;
};
int dist[M][M];
std::vector<node>G[N];
void dij(int s){
	rep(i,1,n+m)vis[i]=0,dis[i]=inf;
	while(!q.empty())q.pop();
	dis[s]=0,q.emplace((pt){s,dis[s]});
	int cnt=0;
	while(!q.empty()){
		int u=q.front().id;q.pop();
		if(vis[u])continue;vis[u]=1;
		if(n+1<=u&&u<=n+m){
			++cnt;
			if(cnt==m)break;
		}
		rep(i,0,(int)G[u].size()-1){
			int v=G[u][i].to,w=G[u][i].w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				q.emplace((pt){v,dis[v]});
			}
		}
	}
	rep(i,n+1,n+m)
		dist[s-n][i-n]=dist[i-n][s-n]=dis[i];
}
std::queue<int>p;
void bfs(int s){
	rep(i,1,n+m)dis[i]=inf;
	while(!p.empty())p.pop();
	dis[s]=0,p.emplace(s);
	int cnt=0,T=0;
	while(!p.empty()){
		int u=p.front();p.pop();
		if(n+1<=u&&u<=n+m){
			++cnt;
			if(cnt==m)break;
		}
		rep(i,0,(int)G[u].size()-1){
			int v=G[u][i].to;
			T=G[u][i].w;
			if(dis[u]+1<dis[v]){
				dis[v]=dis[u]+1;
				p.emplace(v);
			}
		}
	}
	rep(i,n+1,n+m)
		dist[s-n][i-n]=dist[i-n][s-n]=dis[i]*T;
}

signed main(){
	freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
	std::ios::sync_with_stdio(false),std::cin.tie(nullptr),std::cout.tie(nullptr);

	int ty;
	std::cin>>ty>>n>>m>>d>>_;
	rep(i,1,m)std::cin>>a[i];
	rep(i,1,n){
		int k;std::cin>>k;
		while(k-->0){
			int id,w;std::cin>>id>>w;
			G[i+m].emplace_back((node){id,w});
			G[id].emplace_back((node){i+m,w});
		}
	}
	if(12<=ty&&ty<=19){
		rep(i,m+1,m+n)bfs(i);
	}
	else rep(i,m+1,m+n)dij(i);
	while(_-->0){
		int u,v;std::cin>>u>>v;
		int ans=inf;
		rep(i,0,(int)G[u].size()-1)
			rep(j,0,(int)G[v].size()-1){
				int x=G[u][i].to-n,y=G[v][j].to-n;
				ans=min(ans,dist[x][y]+G[u][i].w+G[v][j].w);
			}
		ans+=a[u]+a[v];
		std::cout<<ans<<"\n";
	}

	return 0;
}

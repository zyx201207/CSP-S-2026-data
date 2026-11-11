#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=5e5+10,N=510;
const ll inf=1e18;
struct node{
	ll v,w;
	bool operator>(const node& b)const{
		return w>b.w;
	}
};
ll c,n,m,d,Q;
ll W[M],dis[N][N];
bool vis[N][N];
vector<node> g[N],g1[M];
priority_queue<node,vector<node>,greater<node>> q;
void dijkstra(int x){
	for(int i=1;i<=n;i++)dis[x][i]=inf;
	dis[x][x]=0;
	q.push({x,0});
	while(!q.empty()){
		ll u=q.top().v,w=q.top().w;
		q.pop();
		if(vis[x][u])continue;
		vis[x][u]=1;
		for(auto v:g[u]){
			if(dis[x][u]+v.w<dis[x][v.v]){
				dis[x][v.v]=dis[x][u]+v.w;
				q.push({v.v,dis[x][v.v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)cin>>W[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			for(auto u:g1[a]){
				g[i].push_back({u.v,u.w+t});
				g[u.v].push_back({i,u.w+t});
			}
			g1[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++)dijkstra(i);
	while(Q--){
		ll u,v,ans=inf;
		cin>>u>>v;
		for(auto i:g1[u])for(auto j:g1[v])ans=min(ans,dis[i.v][j.v]+i.w+j.w);
		ans+=W[u]+W[v];
		cout<<ans<<'\n';
	}
	return 0;
}
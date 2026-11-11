#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=5e5+10,N=510,O=2e6+10;
struct node{
	int v;
	ll w;
	bool operator<(const node x)const{
		return w>x.w;
	}
};
int c,n,m,d,q;
ll w[M];
int k[N];
vector<node>g[O];
bool vis[O];
ll dis[N];
void dij(int s){
	priority_queue<node>q;
	for(int i=1;i<=m+m*d+n+10;++i){
		vis[i]=0;
		dis[i]=0x3f3f3f3f;
	}
	dis[s]=0;
	q.push({s,0});
	while(q.size()){
		int u=q.top().v;
		q.pop();
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		for(auto o:g[u]){
			int v=o.v,w=o.w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({v,dis[v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i){
		cin>>k[i];
		int lst=0;
		for(int j=1,u,t;j<=k[i];++j){
			cin>>u>>t;
			g[m+(u-1)*n+i].push_back({u,t});
			g[u].push_back({m+(u-1)*n+i,t});
			if(j>1){
				g[m+(lst-1)*n+i].push_back({m+(u-1)*n+i,0});
				g[m+(u-1)*n+i].push_back({m+(lst-1)*n+i,0});
			}
			lst=u;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		dij(x);
		cout<<dis[y]+w[x]+w[y]<<'\n';
	}
	return 0;
}
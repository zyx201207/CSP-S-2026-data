#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+5;
struct node{
	int di,u,st;
	bool operator <(const node w)const{
		return di>w.di;
	}
};
int c,n,m,d,Q,tot;
vector<pair<int,int>>g[N];
priority_queue<node>q;
int dis[N][N],vis[N][N];
void dijk(){
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=m;++i){
		dis[i*2][i*2]=0;
		q.push({0,i*2,i*2});
	}
	while(q.size()){
		int u=q.top().u,st=q.top().st;
		q.pop();
		if(vis[st][u])continue;
		vis[st][u]=1;
		for(auto t:g[u]){
			int v=t.first,w=t.second;
			if(dis[st][v]>dis[st][u]+w){
				dis[st][v]=dis[st][u]+w;
				q.push({dis[st][v],v,st});
			}
		}
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;++i){
		int w;cin>>w;
		g[i*2-1].push_back({i*2,w});
		g[i*2].push_back({i*2-1,w});
	}
	tot=2*m;
	for(int i=1;i<=n;++i){
		int k;cin>>k;
		int L=0;
		for(int j=1;j<=k;++j){
			int p=++tot;
			int a,t;cin>>a>>t;
			g[p].push_back({2*a-1,t});
			g[2*a-1].push_back({p,t});
			if(L){
				g[L].push_back({p,0});
				g[p].push_back({L,0});
			}
			L=p;
		}
	}
	dijk();
	for(int i=1;i<=Q;++i){
		int x,y;cin>>x>>y;
		cout<<dis[2*x][2*y]<<"\n";
	}
	return 0;
}

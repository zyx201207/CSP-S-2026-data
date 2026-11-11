#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
vector<int> k(505);
vector<pair<int,int> > g[1000005];//v,w

signed main(){
	ios::sync_with_stdio(0);cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		int w;
		cin>>w;
		g[i].push_back({m+i,w});
		g[m+i].push_back({i,w});
	}
	int cnt=2*m;
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int j=1;j<=k[i];++j){
			int a,t;
			cin>>a>>t;
			g[a].push_back({++cnt,t});
			g[cnt].push_back({a,t});
			if(j>1){
				g[cnt].push_back({cnt-1,0});
				g[cnt-1].push_back({cnt,0});
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		vector<bool> vis(1000005);
		priority_queue<pair<int,int> ,vector<pair<int,int> > ,greater<pair<int,int> > > pq;//dis,u
		vector<int> dis(1000005,0x3f3f3f3f3f3f);
		pq.push({0,m+x});
		dis[m+x]=0;
		while(pq.size()){
			auto t=pq.top();pq.pop();
			int u=t.second;
			if(!vis[u]){
				vis[u]=1;
				for(const auto &x:g[t.second]){
					int v=x.first;int w=x.second;
					if(dis[v]>dis[u]+w){
						dis[v]=dis[u]+w;
						pq.push({dis[v],v});
					}
				}
			}
				
		}
		cout<<dis[m+y]<<'\n';
	}
	return 0;
}

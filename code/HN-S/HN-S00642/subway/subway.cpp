#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+510;
int dis[N];
struct P{
	int v,w;
};
vector<P>g[N];
int t[N];
bool vis[N];
void dijkstra(int s){
	memset(dis,0x3f,sizeof dis);
	dis[s]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	pq.push({0,s});
	while(pq.size()){
		pair<int,int>now=pq.top();
		pq.pop();
		int u=now.second;
		int d=now.first;
		for(const auto& vv:g[u]){
			int v=vv.v;
			int w=vv.w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				pq.push({dis[v],v});
			}
		}
	}
	return;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>t[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		vector<pair<int,int>>nodes(k+2);
		for(int j=1;j<=k;j++){
			int v,w;
			cin>>v>>w;
			nodes[j]={v,w};
		}
		for(int j=1;j<=k;j++){
//			cout<<m+i<<' '<<nodes[j].first<<'\n';
			g[nodes[j].first].push_back({m+i,(nodes[j].second)});
			g[m+i].push_back({nodes[j].first,(nodes[j].second)});
		}
	}
//	dfs(1,0,0);

	for(int i=1;i<=q;i++){
		int l,r;
		cin>>l>>r;
		dijkstra(l);
		cout<<dis[r]+t[l]+t[r]<<'\n';
	}
	return 0;
}


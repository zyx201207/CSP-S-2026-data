#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;
const int N = 500 + 5,M = 5e5 + 5;
const ll INF = 1e18;
int c,n,m,d,q,w[M],k[N];
//暴力：1~m表示站厅，建立虚点跑dij 
//std:可能krus+lca? 
vector<pair<int,ll>> g[M+N]; 
ll dis[M+N];
bool vis[M+N];
void solve(int st,int ed){
	ll ans=w[st]+w[ed];
	for(int i=1;i<=m+n;i++){
		dis[i]=INF;
		vis[i]=false;
	}
	priority_queue<pli,vector<pli>,greater<pli>> pq;
	dis[st]=0;
	pq.emplace(0,st);
	while(!pq.empty()){
		auto top=pq.top();
		pq.pop();
		int u=top.second;
		if(vis[u]) continue;
		vis[u]=true;
		for(auto &e:g[u]){
			int v=e.first;ll wei=e.second;
			if(dis[v]>dis[u]+wei) {
				dis[v]=dis[u]+wei;
				pq.emplace(dis[v],v);
			}
		}
	}
	ans+=dis[ed];
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	} 
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int u,v;ll wei;
			v=m+i;
			cin>>u>>wei;
			g[u].emplace_back(v,wei);
			g[v].emplace_back(u,wei);
		}
	}
	while(q--){
		int st,ed;
		cin>>st>>ed;
		solve(st,ed);
	}
	return 0;
}


#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define fi first
#define se second
using namespace std;
const int maxn=5e5+10;
int c,n,m,d,q;
int w[maxn];
vector<pair<int,int>> e[maxn];
struct qnode{
	int u,w;
	bool operator<(const qnode& other)const{
		return w>other.w;
	}
};
int id,dis[maxn];
bool vis[maxn];
void dij(int s){
	fill(dis+1,dis+id+1,1e18);
	fill(vis+1,vis+id+1,0);
	priority_queue<qnode> pq;
	dis[s]=0; pq.push({s,0});
	while(!pq.empty()){
		qnode qn=pq.top(); pq.pop();
		vis[qn.u]=1;
		for(auto to:e[qn.u]){
			int v=to.fi,w=to.se;
			if(dis[v]>dis[qn.u]+w){
				dis[v]=dis[qn.u]+w;
				if(!vis[v]) pq.push({v,dis[v]});
			}
		}
	}
}
vector<pair<int,int>> Q[maxn];
int ans[maxn];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q; id=m;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k; cin>>k; id++;
		for(int j=1;j<=k;j++){
			int v,w; cin>>v>>w;
			e[id].push_back({v,w}); e[v].push_back({id,w});
		}
	}
	for(int i=1;i<=q;i++){
		int s,t;
		cin>>s>>t;
		if(s>t) swap(s,t);
		Q[s].push_back({t,i});
	}
	for(int i=1;i<=m;i++){
		if(Q[i].empty()) continue;
		dij(i);
		for(auto v:Q[i]) ans[v.se]=dis[v.fi]+w[i]+w[v.fi];
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<endl; 
	return 0;
}
/*
旁边坐了个大力敲击键盘的，释怀了。 

最短路加优化？晓不得啊！ 

15：31 56pts 
15：44 卡了一下常，就先这样吧 
15：56 一个优化：离线，然后起点/终点相同的放一起做，56->60 
17：36 发现 UnionRE AK 了 
18：16 写了个 01bfs 结果把电脑卡四级了，重启了电脑 
*/
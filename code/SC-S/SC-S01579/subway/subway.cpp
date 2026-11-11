#include<bits/stdc++.h>
#define int long long 
#define PII pair<int,int> 
using namespace std;
const int N = 1e5 + 10, M = 2e4+10,mod=1e9+7,inf = 1e18;
mt19937 rnd(time(0)); 
int c,n,m,d,q;//试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数
int idx,w[N],k[N];
vector<PII> g[N];
int dist[N],vis[N];
void dij(int s){
	for(int i=1;i<=idx;i++) dist[i]=inf,vis[i]=0;
	priority_queue<PII,vector<PII>,greater<PII>> qe;
	qe.push({dist[s]=0,s});
	while(qe.size()){
		auto var=qe.top().second; qe.pop();
		if(vis[var]) continue;
		vis[var]=1;
		for(auto x:g[var]){
			int e=x.first,ww=x.second;
			if(dist[e]>dist[var]+ww){
				dist[e]=dist[var]+ww;
				qe.push({dist[e],e});
			}
		} 
	}
}
signed main(){
	cin.tie(0)->sync_with_stdio(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){//m站厅 
	    cin>>w[i];
	}
    idx=m;
    for(int i=1;i<=n;i++){
    	cin>>k[i];
    	idx++;
    	for(int j=1;j<=k[i];j++){
    		int x,ti; cin>>x>>ti;//站厅，该站台时间 
    		g[idx].push_back({x,ti});
			g[x].push_back({idx,ti}); 
		}
	}
	while(q--){
		int u,v; cin>>u>>v;
		dij(u);
		cout<<dist[v]+w[u]+w[v]<<"\n";
	}
//	cout<<"\n";
//	for(int i=1;i<=idx;i++){
//		for(auto x:g[i]) cout<<i<<" "<<x.first<<" "<<x.second<<"\n";\
//	} 
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

35
16

*/
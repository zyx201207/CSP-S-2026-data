#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int N=5e6+10,inf=0x3f3f3f3f;
int c,n,m,d,q,w[N],dis[N],ans[N],vis[N],idx[510][510],tot,kk[N];
vector< pair<int,int> > e[N];
vector< pair<int,int> > Q[N];
void Dijkstra(int s){
	for(int i=1;i<=max(tot,m);i++)dis[i]=inf,vis[i]=0;
	priority_queue<pair<int,int> > pq;
	pq.push({0,s});
	dis[s]=0;
	while(!pq.empty()){
		auto p=pq.top();pq.pop();
		int u=p.second,du=p.first;
		if(-du>dis[u]) continue;
		vis[u]=1;
		for(auto ed:e[u]){
			int v=ed.first,w=ed.second;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				if(!vis[v]) pq.push({-dis[v],v});
			}
		}
	}
} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	if(7<=c&&c<=11){
		for(int i=1;i<=n;i++) {
			int k,xw,xi,yw,yi;
			cin>>k>>xi>>xw;
			if(k==1) break;
			cin>>yi>>yw;
			e[xi].push_back({yi,xw+yw});
			e[yi].push_back({xi,xw+yw});
		}
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			Q[x].push_back({y,i});
		}
		for(int i=1;i<=m;i++)if(Q[i].size()){
			Dijkstra(i);
			for(auto qu:Q[i]) ans[qu.second]=dis[qu.first]+w[i]+w[qu.first];
		}
		for(int i=1;i<=q;i++) cout<<ans[i]<<"\n";
		return 0;
	}
	tot=m;
	for(int i=1;i<=n;i++){
		int k,lsti,lstw;
		cin>>k>>lsti>>lstw;
		if(k==1) continue;
		idx[lsti][++kk[lsti]]=++tot;
		e[lsti].emplace_back(tot,lstw);
		e[tot].emplace_back(lsti,lstw);
		lsti=tot;
		--k;
		while(k--){
			int a,t;
			cin>>a>>t;
			idx[a][++kk[a]]=++tot;
			e[lsti].emplace_back(tot,0);
			e[tot].emplace_back(lsti,0);
			e[a].emplace_back(tot,t);
			e[tot].emplace_back(a,t);
			lsti=tot;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		Q[x].push_back({y,i});
	}
	for(int i=1;i<=m;i++)if(Q[i].size()){
			Dijkstra(i);
			for(auto qu:Q[i]) ans[qu.second]=dis[qu.first]+w[i]+w[qu.first];
		}
	for(int i=1;i<=q;i++) cout<<ans[i]<<"\n";
	
	return 0;
}

#include <bits/stdc++.h>
#define ll long long
using namespace std;
//不会写qwq
//部分分
//先在每个站台建一个点
//再去做dij
//冰冰冰 
int w[500010];
int k[500010];
ll dis[500010];
vector<pair<int,ll> > g[500010];
struct node{
	ll x,d;
	bool operator <(const node&ne) const{
		return d>ne.d;
	}
};
priority_queue<node> pq;
void dij(int s){
	pq.push({s,0});
	dis[s]=0;
	while(pq.size()){
		node s=pq.top();
		pq.pop();
		int u=s.x,d=s.d;
		if(dis[u]!=d){
			continue;
		}
		for(auto it:g[u]){
			int v=it.first,w=it.second;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				pq.push({v,dis[v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int tot=m;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int u,t;
			cin>>u>>t;
			tot++;
			g[u].push_back({tot,t});
			g[tot].push_back({u,t});
		}
		for(int j=tot-k[i]+1;j<=tot-1;j++){
			g[j].push_back({j+1,0});
			g[j+1].push_back({j,0});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		for(int i=1;i<=tot;i++){
			dis[i]=1e18;
		}
		dij(x);
		cout<<dis[y]+w[x]+w[y]<<endl;
	}//?pts 
	return 0; 
} 
//好心人能不能送我400ptsqwq 

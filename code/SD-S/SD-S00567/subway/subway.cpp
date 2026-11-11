#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
vector<pair<ll,ll> > e[2005];
ll dis[2005][2005],w[500005],c,n,m,q,d;
bool vis[2005][2005];
struct node{
	ll dis,pos;
	bool operator <(const node& x) const{
		return x.dis<dis;
	}
};
void dijk(int s){
	dis[s][s]=0;
	vis[s][s]=1;
	priority_queue<node> q;
	q.push({0,s});
	while(!q.empty()){
		node tmp=q.top();
		q.pop();
		int u=tmp.pos;
		for(auto v:e[u]){
			if(dis[s][v.first]>dis[s][u]+v.second){
				dis[s][v.first]=dis[s][u]+v.second;
				q.push({dis[s][v.first],v.first});
				if(!vis[s][v.first]){
					vis[s][v.first]=1;
				}
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=2000;i++){
		for(int j=1;j<=2000;j++){
			dis[i][j]=0x3f3f3f3f3f3f3f3f;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k,y,w;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>y>>w;
			e[y].push_back({i+m,w});
			e[i+m].push_back({y,w});
		}
	}
	ll u,v;
	while(q--){
		cin>>u>>v;
		if(u>v){
			swap(u,v);
		}
		if(!vis[u][v]){
			dijk(u);
		}
		cout<<dis[u][v]+w[u]+w[v]<<"\n";
	}
	return 0;
}


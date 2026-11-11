#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
const int N=5e5+5;
ll c,n,m,d,q,w[N];
ll dis[N],vis[N];
vector<pii>e[N];
void Dijkstra(ll st){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	priority_queue<pii,vector<pii>,greater<pii>>q;
	dis[st]=0; 
	q.push({0,st});
	while(!q.empty()){
		auto p=q.top();q.pop();
		ll u=p.s;
		if(vis[u]){
			continue;
		}
		vis[u]=1;
//		cout<<"u:"<<u<<" v:"<<" ";
		for(auto edge:e[u]){
			auto v=edge.f,w=edge.s;
			if(vis[v]){
				continue;
			}
//			cout<<" "<<v<<" ";
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	} 
	for(int i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(int j=1;j<=k;j++){
			ll v,t;
			cin>>v>>t;
			e[m+i].push_back({v,t});
			e[v].push_back({m+i,t});
		}
	}
	while(q--){
		ll st,t;
		cin>>st>>t;
		ll ans=w[st]+w[t];
		Dijkstra(st);
		cout<<ans+dis[t]<<"\n";
	}
	return 0;
}
//0 3 7 20 2
//8 3 6 1 7 2 9
//3 1 4 2 5 5 100
//3 2 6 3 1 7 2
//4 3 2 5 100 4 6 6 7
//1 6
//2 3

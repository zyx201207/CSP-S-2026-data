#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll dijkstra(vector<vector<pair<int,ll>>>& g,int m,int s,int e){
	vector<ll> dist(m+1,INF);
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
	dist[s]=0;pq.push({0,s});
	while(!pq.empty()){
		int u=pq.top().second;ll d=pq.top().first;pq.pop();
		if(d>dist[u])continue;
		for(auto& edge:g[u]){
			int v=edge.first;ll w=edge.second;
			if(d+w<dist[v]){
				dist[v]=d+w;
				pq.push({dist[v],v});
			}
		}
	}
	return dist[e];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int ID,n,m,d,q;
	cin>>ID>>n>>m>>d>>q;
	vector<ll> w(m+1);
	for(int i=1;i<=m;i++)cin>>w[i];
	vector<vector<pair<int,ll>>> g(m+1);
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		vector<int> a(k+1);vector<ll> t(k+1);
		for(int j=1;j<=k;j++)cin>>a[j]>>t[j];
		for(int u=1;u<=k;u++)
			for(int v=u+1;v<=k;v++){
				g[a[u]].push_back({a[v],t[u]+t[v]});
				g[a[v]].push_back({a[u],t[u]+t[v]});
			}
	}
	while(q--){
		int s,e;cin>>s>>e;
		ll ans=w[s]+w[e]+dijkstra(g,m,s,e);
		cout<<ans<<'\n';
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long ll;
int c,n,m,d,q,w[N],k[N],vis[N],dist[N];
vector<pair<int,int> >e[N];
void dij(int s){
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
	memset(dist,0x3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	dist[s]=0;
	pq.push({0,s});
	while(!pq.empty()){
		auto u=pq.top();pq.pop();
		vis[u.second]=1;
		for(auto v:e[u.second]){
			if(vis[v.first]) continue;
			if(u.first+v.second<dist[v.first]){
				dist[v.first]=v.second+u.first;
				pq.push({dist[v.first],v.first});
			}
		}
	}
}
int main(){
	freopen("subway2.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int j=1;j<=k[i];++j){
			int x,y;
			cin>>x>>y;
			e[i+m].push_back({x,y});
			e[x].push_back({i+m,y});
		}
	}
	for(int i=1;i<=q;++i){
		int x,y;
		cin>>x>>y;
		dij(x);
		cout<<(dist[y]+w[x]+w[y])<<'\n';
	}
	return 0;
}
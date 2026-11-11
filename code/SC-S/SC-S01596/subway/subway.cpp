#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;
const int N=505,M=2e5+5,D=25,K=4.2e6+5;
int c,n,m,d,q,w[K],tot,a[M];
ll dis[K];bool vis[K];
priority_queue<pli,vector<pli>,greater<pli>> h;
vector<int> g[K],z[K];
ll dijkstra(int s,int t){
	while(!h.empty())	h.pop();
	fill(dis+1,dis+1+tot,9e18);
	fill(vis+1,vis+1+tot,0);
	h.emplace(pli(dis[s]=w[s],s));
	while(!h.empty()){
		int u=h.top().second;
		h.pop();
		if(vis[u])	continue;
		if(u==t)	return dis[u];
		vis[u]=1;
//		cout<<u<<':'<<dis[u]<<'\n';
		for(int v:g[u])if(dis[u]+w[v]<dis[v])
			h.emplace(pli(dis[v]=dis[u]+w[v],v));
	}
	return 9e18;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[++tot];
		z[i].emplace_back(tot);
	}
	for(int i=1,k;i<=n;++i){
		cin>>k;
		for(int i=1,t;i<=k;++i){
			cin>>t>>w[++tot];
			z[t].emplace_back(a[i]=tot);
		}
		for(int i=1;i<=k;++i)
			for(int j=i+1;j<=k;++j){
//				cout<<a[i]<<"<->"<<a[j]<<'\n';
				g[a[i]].emplace_back(a[j]);
				g[a[j]].emplace_back(a[i]);
			}
	}
	for(int i=1;i<=m;++i)
		for(int u:z[i])
			for(int v:z[i])
				if(u!=v)
					/*cout<<u<<"->"<<v<<'\n',*/g[u].emplace_back(v);
	for(int u,v;q--;){
		cin>>u>>v;
		cout<<dijkstra(u,v)<<'\n';
	}
	return 0;
}
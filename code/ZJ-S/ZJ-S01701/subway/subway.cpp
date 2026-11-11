#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=5e5+10;
int c,n,m,d,q;
int w[N];
int dis[N],vis[N];
struct node{
	int to,w;
	bool operator <(const node &nd) const{
		return w<nd.w;
	}
};
vector<node> g[N];
void add(int u,int v,int w){
	g[u].push_back({v,w});
	g[v].push_back({u,w});
}
void init(){
	memset(vis,0,sizeof(vis));
	memset(dis,0x7f,sizeof(dis));
}
void dij(int s){
	dis[s]=0;
	priority_queue<node> pq;
	pq.push((node){s,0});
	while(!pq.empty()){
		auto it=pq.top();
		pq.pop();
		int u=it.to;
		if(vis[u]) continue;
		vis[u]=1;
		for(auto ndv:g[u]){
			int v=ndv.to,w=ndv.w;
			
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				pq.push((node){v,dis[v]});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		vector<int> a,t;
		int k,x,y;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>y;
			a.push_back(x),t.push_back(y);
		}
		for(int j=1;j<k;j++){
			add(a[j],a[j-1],t[j]+t[j-1]);
		}
	}
	for(int i=1;i<=q;i++){
		int u,v;
		cin>>u>>v;
		init();
		dij(u);
		cout<<(dis[v]+w[u]+w[v])<<"\n";
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
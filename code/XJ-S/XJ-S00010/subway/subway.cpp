#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
const int N=1e7+100,M=5e6+100;
const int A=13,B=131,C=1331,D=17;
vector<pair<int,int>> g[N];
int dis[N],w[M];
void dij(int root){
	fill(dis,dis+N,1e18);
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	q.push({0,root});
	dis[root]=0;
	while(!q.empty()){
		auto cur=q.top();
		q.pop();
		int u=cur.second;
		for(auto i:g[u]){
			int v=i.first,w=i.second;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		g[i*A].push_back({i*B,w[i]});
		g[i*B].push_back({i*A,w[i]});
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int idx,e;
			cin>>idx>>e;
			g[idx*B].push_back({i*C,e});
			g[i*C].push_back({idx*B,e});
		}
	}
	while(q--){
		int x,y;cin>>x>>y;
		dij(A*x);
		cout<<dis[A*y]<<"\n";
	}
	return 0;
}


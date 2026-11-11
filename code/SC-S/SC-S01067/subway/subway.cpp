#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int,int>> g[200005];
int n,m,dis[1000005],bj[1000005],d,c,q,a[1000005];
void dij(int s,int t){
	memset(dis,0x3f3f,sizeof(dis));
	memset(bj,0,sizeof(bj));
	dis[s]=0;
	priority_queue<pair<int,int>> q;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(u==t) return;
		if(bj[u]) continue;
		bj[u]=1;
		for(auto eg : g[u]){
			int w=eg.first;
			int v=eg.second;
			if(dis[w]>dis[u]+v){
				dis[w]=dis[u]+v;
				q.push({-dis[w],w});
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0); 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;cin>>x>>y;
			g[x].push_back({m+i,y});
			g[m+i].push_back({x,y});
		}
	}
	for(int i=1;i<=q;i++){
		int s,t;cin>>s>>t;
		dij(s,t);
		cout<<dis[t]+a[s]+a[t]<<'\n';
	}
	return 0;
}
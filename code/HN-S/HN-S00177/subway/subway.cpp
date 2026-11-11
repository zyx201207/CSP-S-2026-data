#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+5;
int c,n,m,d,q,w[M],t[M],a[M],dist[M],vis[M];
vector<pair<int,int> >G[M];
void dij(int s){
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	q.push({0,s});
	dist[s]=0;
	while(!q.empty()){
		int u=q.top().second;
//		cout<<u;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto v:G[u]){
			int zv=v.first;
			int w=v.second;
			if(dist[zv]>dist[u]+w){
				dist[zv]=dist[u]+w;
				vis[zv]=0;
//				cout<<zv<<" "<<dist[zv]<<"\n";
				q.push({dist[zv],zv});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int i=1;i<=k;i++) cin>>a[i]>>t[i];
		for(int i=1;i<=k;i++){
			for(int j=1;j<=k;j++){
				if(i!=j) G[a[i]].push_back({a[j],t[i]+t[j]});
			}
		}
	}
	for(int i=1;i<=q;i++){
		fill(dist+1,dist+1+m,LONG_LONG_MAX);
		fill(vis+1,vis+1+m,0);
		int x,y;
		cin>>x>>y;
		dij(x); 
		cout<<dist[y]+w[x]+w[y]<<"\n";
	}
	return 0;
} 

#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=1e6+5,INF=1e18;
int c,n,m,d,q,s[N];
vector<pii> adj[N];
int dijkstra(int s,int t){
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	vector<int> dist(N,INF);
	dist[s]=0;
	pq.push({0,s});
	while(!pq.empty()){
		int u=pq.top().second,d=pq.top().first;
		pq.pop();
		if(dist[u]<d)continue; 
		for(int i=0;i<adj[u].size();i++){
			int v=adj[u][i].first,w=adj[u][i].second;
			if(d+w<dist[v]){
				dist[v]=d+w;
				pq.push({d+w,v});
			}
		}
	}
//	for(int i=1;i<=15;i++)cout<<dist[i]<<' ';
//	cout<<'\n'; 
	return dist[t];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<N;i++)s[i]=i;
	vector<vector<pii>> a(n+1);
	vector<int> w(m+1);
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		a[i].resize(k+1);
		for(int j=1;j<=k;j++){
			cin>>a[i][j].first>>a[i][j].second;//up down
			adj[a[i][j].first].push_back({m+i,a[i][j].second});
			adj[m+i].push_back({a[i][j].first,a[i][j].second});
		}
	}
//	for(int i=1;i<=15;i++){
//		cout<<i<<": ";
//		for(pii j:adj[i]){
//			cout<<"{"<<j.first<<","<<j.second<<"}"<<" , ";
//		}
//		cout<<'\n';
//	}
	while(q--){
		int start,end;cin>>start>>end;
		cout<<dijkstra(start,end)+w[start]+w[end]<<'\n';
	}
	return 0;
}
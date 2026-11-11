#include<bits/stdc++.h>
using namespace std;
#define zhr ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
using pii = pair<int,int>;
const int N = 2e3+5;
int c,n,m,d,q;
vector<pair<int,int>> g[3*N];
int a[N];
int t[N];
int dist[N][N*3];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	zhr;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		int val;cin>>val;
		g[i].push_back({i+m,val});
		g[i+m].push_back({i,val});
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
			g[a[j]+m].push_back({a[j]+m+d*i,t[j]});
			g[a[j]+m+d*i].push_back({a[j]+m,t[j]});
			
			g[a[j]+m+i*d].push_back({a[j-1]+m+i*d,0});
			g[a[j-1]+m+i*d].push_back({a[j]+m+i*d,0});
			
		} 
	}
	memset(dist,0x3f,sizeof dist);
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	for(int i=1;i<=m;i++){
		dist[i][i]=0;
		pq.push({0,i});
		while(!pq.empty()){
			auto it = pq.top();pq.pop();
			int val1 = it.first , u = it.second;
			if(val1 > dist[i][u]) continue;
			for(auto x : g[u]){
				int v=x.first , val2=x.second;
				int val=val1+val2;
				if(dist[i][v]>val){
					dist[i][v]=val;
					pq.push({val,v});
				}
			}
		}
	}
	while(q--){
		int u,v;cin>>u>>v;
		cout<<dist[u][v]<<endl;
	}
	return 0;
}

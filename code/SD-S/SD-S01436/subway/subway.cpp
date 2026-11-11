#include<bits/stdc++.h>
using namespace std;
long long w[505010];
long long dist[505010];
vector<pair<long long,int>>g[505010];
bool vis[505010];
const long long INF=0x3f;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i+5000];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int i=1;i<=k;i++){
			int aa;
			long long tt;
			cin>>aa>>tt;
			g[i].push_back({tt,aa+5000});
			g[aa+5000].push_back({tt,i});
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		memset(dist,INF,sizeof(dist));
		dist[x+5000]=0;
		memset(vis,false,sizeof(vis));
		priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
		pq.push({0,x+5000});
		while(!pq.empty()){
			long long dis=pq.top().first;
			int u=pq.top().second;
			pq.pop();
			if(vis[u]){
				continue;
			}
			vis[u]=true;
			for(auto ed:g[u]){
				long long di=ed.first;
				int v=ed.second;
				if(dist[v]>dist[u]+di){
					dist[v]=dist[u]+di;
					pq.push({dist[v],v});
				}
			}
		}
		cout<<dist[y+5000]+w[x+5000]+w[y+5000]<<"\n";
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;

const int MAXN=5e2+27;
const int MAXM=1e3+27;
const long long INF=1e18+27;

long long c,n,m,d,q;
long long w[MAXM],k[MAXN];
long long a[MAXM][MAXM];
long long dist[MAXM][MAXM];
bool vis[MAXM];

vector< pair<int,long long> > in[MAXN];
vector< pair<int,long long> > g[MAXM];

inline void dijkstra(int st){
	priority_queue< pair<long long,int> ,vector< pair<long long,int> > ,greater< pair<long long,int> > > que;
	que.push({0LL,st});
	for(int i=1;i<=m;i++) dist[st][i]=INF,vis[i]=false;
	dist[st][st]=0;

	while(!que.empty()){
		int u=que.top().second;
		que.pop();
//		cout<<u<<":"<<endl;
		if(vis[u]) continue;
		vis[u]=true;
		
		for(auto e:g[u]){
			int v=e.first;
			long long w=e.second;
//			cout<<v<<" "<<w<<" "<<dist[st][v]<<" "<<dist[st][u]+w<<endl;
			if(dist[st][v]>dist[st][u]+w){
				dist[st][v]=dist[st][u]+w;
				if(!vis[v]) que.push({dist[st][v],v});
			}
		}
		
	}
	
}

int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1,u,val;j<=k[i];j++){
			cin>>u>>val;
			in[i].push_back({u,val});
		}
	}
	
	for(int i=1;i<=n;i++){
//		cout<<i<<":"<<endl;
		for(int x=0;x<k[i];x++){
			for(int y=x+1;y<k[i];y++){
//				cout<<"    "<<in[i][x].first<<" "<<in[i][y].first<<" "<<in[i][x].second+in[i][y].second<<endl;
				if(in[i][x].first==in[i][y].first) continue;
				g[in[i][x].first].push_back({in[i][y].first,in[i][x].second+in[i][y].second});
				g[in[i][y].first].push_back({in[i][x].first,in[i][x].second+in[i][y].second});
			}
		}
	}
	
//	for(int i=1;i<=m;i++){
//		cout<<i<<endl;
//		for(auto e:g[i]){
//			cout<<"    "<<e.first<<" "<<e.second<<endl;
//		}
//	}
	
	for(int i=1;i<=m;i++)
		dijkstra(i);
		
	int u,v;
	while(q--){
		cin>>u>>v;
		cout<<w[u]+w[v]+dist[u][v]<<endl;
	}
	
	return 0;
}
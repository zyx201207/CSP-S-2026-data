#include<bits/stdc++.h>
#define pii pair<int,int>
#define int long long
using namespace std;
const int M=5e5+10,N=510,inf=1e18;
int c,n,m,d,q;
vector<pii>g[2*M+N];
int dist[2*M+N];
void dij(int x){
	for(int i=0;i<=2*m+n;i++)dist[i]=inf;
	priority_queue<pii,vector<pii>,greater<pii>>q;
	dist[x]=0;
	q.push({dist[x],x});
	while(!q.empty()){
		int k=q.top().second,dis=q.top().first;
		q.pop();
		if(dis>dist[k])continue;
		for(auto i:g[k]){
			int j=i.first,w=i.second;
			if(dist[j]>dist[k]+w){
				dist[j]=dist[k]+w;
				q.push({dist[j],j});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	//n,m!!!
	for(int i=1;i<=m;i++){
		int w;
		cin>>w;
		g[i].push_back({m+i,w});
		g[m+i].push_back({i,w});
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,t;
			cin>>x>>t;
			g[2*m+i].push_back({m+x,t});
			g[m+x].push_back({2*m+i,t});
		}
	}
	for(int i=1;i<=q;i++){
		int u,v;
		cin>>u>>v;
		dij(u);
		cout<<dist[v]<<'\n';
	}
	
	
	return 0;
}
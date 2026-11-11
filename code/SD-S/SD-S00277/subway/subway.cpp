#include<bits/stdc++.h>
#define int long long
using namespace std;
int c;
int n,m,d,q;
int w[100005];
int dis[50005];
int di[3005][3005];
const int INF=1e18;
vector<pair<int,int> > a[10005];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
void dijkstra(int x){
	for(int i=0;i<50005;i++){
		dis[i]=INF;
	}
	dis[x]=0;
	pq.push({0,x});
	while(!pq.empty()){
		auto now=pq.top();
		pq.pop();
		int dist=now.first;
		int u=now.second;
		for(int i=0;i<a[u].size();i++){
			int v=a[u][i].first;
			if(dis[u]+a[u][i].second<dis[v]){
				dis[v]=dis[u]+a[u][i].second;
				pq.push({dis[v],v});
			}
		}
	}
} 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>c;
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		a[i].push_back({i+m,w[i]});
		a[i+m].push_back({i,w[i]});
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			a[x+m].push_back({2*m+i,y});
			a[2*m+i].push_back({x+m,y});
		}
	}
	if(q<=2000){
		while(q--){
			int u,v;
			cin>>u>>v;
			dijkstra(u);
			cout<<dis[v];
			cout<<"\n";
		}
	}
	else{
		for(int i=1;i<=m;i++){
			dijkstra(i);
			for(int j=1;j<=m;j++){
				di[i][j]=dis[j];
			}
		}
		while(q--){
			int u,v;
			cin>>u>>v;
			cout<<min(di[u][v],di[v][u])<<"\n";
		}
	}
	return 0;
}


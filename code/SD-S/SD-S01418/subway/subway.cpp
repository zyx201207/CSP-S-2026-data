#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,n,m,d,q;
const int N=5e4+10;//地铁站数量 
int w[N];
vector<int>way[N],st[N],road[N];
int t[510][N];
typedef pair<int,int>PII;
vector<PII>edge[N];
int dist[510][510];
void dijkstra(int st){
	priority_queue<PII,vector<PII>,greater<PII>>q;
	q.push({0,st});
	dist[st][st]=0;
	while(!q.empty()){
		PII t=q.top(); q.pop();
		int u=t.second;
		for(auto i:edge[u]){
			int v=i.first,w=i.second;
			if(dist[st][v]>dist[st][u]+w){
				dist[st][v]=dist[st][u]+w;
				q.push({dist[st][v],v});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int cnt; cin>>cnt;
		for(int j=1;j<=cnt;j++){
			int x,y; cin>>x>>y;
			road[i].push_back(x);
			t[i][x]=y;
			way[x].push_back(i);
			if(j==1) st[x].push_back(i);
		} 
	} 
	for(int i=1;i<=m;i++){
		for(auto j:way[i]){//包含当前点的路线 
			for(auto k:way[i]){
				if(j==k) continue;
				int cost=t[j][i]+t[k][i];
				edge[j].push_back({k,cost});
				edge[k].push_back({j,cost});
			}
		}
	}
	memset(dist,0x3f,sizeof dist);
	for(int i=1;i<=n;i++) dijkstra(i);
	while(q--){
		int a,b; cin>>a>>b;
		int ans=2e18;
		for(auto i:st[a]){
			for(auto j:way[b]){
				ans=min(ans,w[a]+w[b]+dist[i][j]+t[i][a]+t[j][b]);
			}
		}
		cout<<ans<<"\n";
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

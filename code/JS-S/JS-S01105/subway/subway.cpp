#include<bits/stdc++.h>
using namespace std;
#define int long long
using pii=pair<int,int>;
const int M=2e4+10;
const int N=5e5+1000;
struct node{
	int to,wi;
};
int c,n,m,d,q;
int w[N];
vector<node> g[N];
bool vis[N];
bool cnt[N];
int dist[N];
void dijkstra(int sx){
	priority_queue<pii,vector<pii>,greater<pii> > q;
	for(int i=1;i<=n+m;i++)dist[i]=INT_MAX;
	for(int i=1;i<=n+m;i++)vis[i]=0;
	q.push({0,sx});
	dist[sx]=0;
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto x:g[u]){
			int v=x.to;
			int w=x.wi;
			if(dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				q.push({dist[v],v});
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=1;i<=m;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int v,d;
			cin>>v>>d;
			g[n+i].push_back({v,d});
			g[v].push_back({n+i,d});
		}
	}
	
	while(q--){
		int s,e;
		cin>>s>>e;
		if(!cnt[s]){
			dijkstra(s);
			cnt[s]=1;
		}
		cout<<dist[e]+w[s]+w[e]<<"\n";
	}
	return 0;
}
/*
 * 	freopen("subway.in"."r",stdin);
	freopen("subway.out","w",stdout);
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/

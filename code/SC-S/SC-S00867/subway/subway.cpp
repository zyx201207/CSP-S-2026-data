#include<bits/stdc++.h>
#define pii pair<int,int>
#define int long long
using namespace std;
const int N=5e2+5,M=5e5+5;
int c,n,m,d,q,w[M],k[N],dis[N][N];
vector<pii> G[N];
vector<pii> g[M];
void dijkstra(int s){
	for(int i=1;i<=n;i++) dis[s][i]=1e18;
	priority_queue<pii,vector<pii>,greater<pii>> qu;
	dis[s][s]=0;
	qu.push({0,s});
	while(!qu.empty()){
		int u=qu.top().second;
		qu.pop();
		for(pii e:G[u]){
			int v=e.first,w=e.second;
			if(dis[s][u]+w<dis[s][v]){
				dis[s][v]=dis[s][u]+w;
				qu.push({dis[s][v],v});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a,t;cin>>a>>t;
			for(pii e:g[a]){
				int v=e.first,w=e.second;
				G[i].push_back({v,t+w});
				G[v].push_back({i,t+w});
			}
			g[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++) dijkstra(i);
	while(q--){
		int x,y,ans=1e18;cin>>x>>y;
		for(pii e1:g[x]){
			for(pii e2:g[y]){
				int u=e1.first,v=e2.first,w1=e1.second,w2=e2.second;
				ans=min(ans,dis[u][v]+w1+w2);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
} 
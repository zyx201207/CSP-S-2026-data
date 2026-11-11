#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define db double
#define pii pair<int,ll>
const int N=505,M=5e5+5;const ll inf=1e18;
ll dis[N][N],w[M],n,m,d,q,vis[N];
vector<pii> e[N],a[M];
void dijkstra(int s){
	for(int i=1;i<=n;i++) dis[s][i]=inf,vis[i]=0;
	priority_queue<pii> q;dis[s][s]=0,q.push({0,s});
	while(!q.empty()){
		int u=q.top().second;q.pop();
		for(auto tmp:e[u]){
			int v=tmp.first;ll w=tmp.second;
			if(dis[s][u]+w<dis[s][v]) dis[s][v]=dis[s][u]+w,q.push({-dis[s][v],v});
		}
	}
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
	cin>>n>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;cin>>x>>y;
			a[x].push_back({i,y});
		}
	}
	for(int i=1;i<=m;i++){
		if(a[i].size()<=1) continue;
		for(int j=0;j<int(a[i].size());j++)
			for(int p=j+1;p<int(a[i].size());p++){
				int x=a[i][j].first,y=a[i][p].first;ll v=a[i][j].second+a[i][p].second;
				e[x].push_back({y,v}),e[y].push_back({x,v});
			}
	}
	for(int i=1;i<=n;i++) 
		dijkstra(i);
	while(q--){
		int x,y;cin>>x>>y;
		ll ans=inf;
		for(auto t1:a[x]) for(auto t2:a[y]){
			int aa=t1.first,bb=t2.first;
			ans=min(ans,t1.second+t2.second+dis[aa][bb]);
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
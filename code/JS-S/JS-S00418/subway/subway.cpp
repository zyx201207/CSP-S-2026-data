#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF=(1LL<<60);
const int N=505;

ll dist[N];
vector<bool> vis(N);
vector<pair<int,ll>> g[N];

void dijkstra(ll n,int start){
	for(int i=1;i<=n;i++){
		vis[i]=false;
		dist[i]=INF;
	}
	dist[start]=0;
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
	q.push({0,start});
	while(!q.empty()){
		//ll d=q.top().first;
		int u=q.top().second;
		q.pop();
		if(vis[u]==true) continue;
		vis[u]=true;
		for(auto&edge:g[u]){
			int v=edge.first;
			ll w=edge.second;
			if(dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				q.push({dist[v],v});
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m;
	int d,q;
	cin>>c>>n>>m>>d>>q;
	vector<ll> w(m+1,0);
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int lastp=-1;
		for(int j=1;j<=k;j++){
			int pos;ll t;
			cin>>pos>>t;
			if(lastp==-1) {
				lastp=pos;
				continue;
			}
			else {
				g[lastp].push_back({pos,t});
				g[pos].push_back({lastp,t});
			}
			lastp=pos;
		}
	}
	while(q--){
		int start,end;
		cin>>start>>end;
		dijkstra(n,start);
		ll ans=dist[end];
		ll cnt=w[start]+w[end];
		ans+=cnt;
		cout<<ans<<endl;
	}
	return 0;
}

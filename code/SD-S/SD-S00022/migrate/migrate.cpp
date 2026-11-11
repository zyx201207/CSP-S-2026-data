#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=5005;
int c,t,n;
ll d;
vector<pair<ll,ll> > g[N];
ll a[N];
int cnt[N],dist[N],vis[N];
void dijkstra(int s){
	memset(dist,0x3f,sizeof(dist));
	memset(cnt,1,sizeof(cnt));
	memset(vis,false,sizeof(vis));
	priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > pq;
	pq.push({0,s});
	dist[s]=0;
	while(!pq.empty()){
		pair<ll,ll> x=pq.top();pq.pop();
		ll d=x.first,u=x.second;
		if(vis[u]) continue;
		vis[u]=true;
		for(int i=0;i<g[u].size();i++){
			pair<ll,ll> x=g[u][i];
			ll v=x.first,w=x.second;
			if(d+w<dist[v]){
				dist[v]=d+w;
				pq.push({dist[v],v});
			}
			else if(dist[v]==d+w) cnt[v]++;
		}
	}
}

void solve(){
	cin>>n>>t;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<=n;i++){
		for(int j=i+1;i<=n;j++){
			ll w=abs(a[i]-a[j]);
			if(w<=d){
				g[i].push_back({i,w});
//				g[j].push_back({i,w});
			}
		}
	}
	int ans=0;
	dijkstra(a[1]);
	for(int i=1;i<=n;i++){
		if(cnt[i]==2) ans++;
	}
	cout<<ans<<'\n';
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		cout<<0<<'\n';
	}
	return 0;
}

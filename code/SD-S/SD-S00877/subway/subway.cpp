#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=2e4+1000;
ll w[N]; 
vector<pair<int,ll> > adj[N];
ll dist[N][505];
struct node{
	ll v,dis;
	bool operator<(const node &a)const{
		return dis>a.dis;
	}
};
bool cnt[N][505];
int c,n,m,d,q;
void dij(int x){
	priority_queue<node> pq;
	pq.push({x,0});
	dist[x][x-m]=0;
	while(pq.size()){
		ll fu=pq.top().v,fdis=pq.top().dis;
		pq.pop();
		if(cnt[fu][x-m]) continue;
		cnt[fu][x-m]=1;
		for(auto vv:adj[fu]){
			ll vid=vv.first,vdis=vv.second;
			if(dist[vid][x-m]>vdis+dist[fu][x-m]){
				dist[vid][x-m]=vdis+dist[fu][x-m];
				pq.push({vid,dist[vid][x-m]});
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n+m;i++){
		for(int j=1;j<=m;j++) dist[i][j]=0x3f3f3f3f3f3f3f3f;
	}
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int av;
			ll tk;
			cin>>av>>tk;
			adj[av].push_back({i+m,tk});
			adj[i+m].push_back({av,tk});
		}
	}
	for(int i=m+1;i<=m+n;i++){
		dij(i);
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=0x3f3f3f3f3f3f3f3f;
		for(int i=1;i<=n;i++){
			ans=min(ans,dist[x][i]+dist[y][i]);
		}
		ans+=w[x];
		ans+=w[y];
		cout<<ans<<"\n";
	}
	return 0;
}


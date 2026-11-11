#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5 + 5,T=5e2 + 5,M = 1e4 + 5;
ll n,c,m,d,q,w[N],k[N],v,t,s[T][2*M+T],cnt,val,vis[N],u,ans,kt,h[N][2],yy;
struct node{
	ll v,w;
};
struct Node{
	ll x,w;
	const bool operator<(const Node a) const{
		return w>a.w;
	}
};
vector<node> g[N+T];
priority_queue<Node> pq;
queue<node> o;
void solve(ll u){
	while(!pq.empty()) pq.pop();
	s[u-m][u]=0,cnt=1;
	pq.push({u,0});
	memset(vis,0,sizeof(vis));
	while(!pq.empty()){
		c=pq.top().x,val=pq.top().w;
		pq.pop();
		if(vis[c]) continue;
		vis[c]=1,s[u-m][c]=val,cnt++;
		for(auto l:g[c]){
			if(!vis[l.v]) pq.push((Node){l.v,val+l.w});
		}
	}
	return ;
}
void bfs(ll u){
	while(!o.empty()) o.pop();
	s[u-m][u]=0;
	o.push((node){u,0});
	cnt=1;
	memset(vis,0,sizeof(vis)),vis[u]=1;
	while(!o.empty()){
		c=o.front().v,val=o.front().w;
		o.pop();
		s[u-m][c]=val,cnt++;
		for(auto l:g[c]){
			if(!vis[l.v]) vis[l.v]=1,o.push((node){l.v,val+1});
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	if(c<=11||c>=24){
		for(ll i=1;i<=m;i++) cin>>w[i];
		for(ll i=1;i<=n;i++){
			cin>>k[i];
			for(ll j=1;j<=k[i];j++) cin>>v>>t,g[v].push_back((node){m+i,t}),g[m+i].push_back((node){v,t});
		}
		for(ll i=1;i<=n;i++) solve(i+m);
		while(q--){
			cin>>u>>v,ans=1e18;
			for(auto l:g[u]) if(s[l.v-m][v]) ans=min(ans,l.w+s[l.v-m][v]);
			cout<<ans+w[u]+w[v]<<"\n";
		}
	}else if(n<=2){
		for(ll i=1;i<=m;i++) cin>>w[i];
		for(ll i=0;i<n;i++){
			cin>>k[i];
			for(ll j=1;j<=k[i];j++) cin>>v>>t,h[v][i]=t;
		}
		if(n==1){
			while(q--){
				cin>>u>>v;
				cout<<w[u]+w[v]+h[u][0]+h[v][0]<<"\n";
			}
		}else{
			kt=2e17;
			for(ll i=1;i<=m;i++) if(h[i][0]&&h[i][1]) kt=min(kt,h[i][0]+h[i][1]);
			while(q--){
				cin>>u>>v,ans=1e18;
				if(h[u][0]&&h[v][0]) ans=min(h[u][0]+h[v][0],ans);
				if(h[u][1]&&h[v][1]) ans=min(h[u][1]+h[v][1],ans);
				if(h[u][0]&&h[v][1]) ans=min(ans,h[u][0]+kt+h[v][1]);
				if(h[u][1]&&h[v][0]) ans=min(ans,h[u][1]+kt+h[v][1]);
				cout<<ans+w[u]+w[v]<<"\n";
			}
		}
	}else{
		for(ll i=1;i<=m;i++) cin>>w[i];
		for(ll i=1;i<=n;i++){
			cin>>k[i];
			for(ll j=1;j<=k[i];j++) cin>>v>>t,g[v].push_back((node){m+i,t}),g[m+i].push_back((node){v,t});
		}
		for(ll i=1;i<=n;i++) bfs(i+m);
		while(q--){
			cin>>u>>v,ans=1e18;
			for(auto l:g[u]) ans=min(ans,t*(1+s[l.v-m][v]));
			cout<<ans+w[u]+w[v]<<"\n";
		}
	}
	return 0;
}
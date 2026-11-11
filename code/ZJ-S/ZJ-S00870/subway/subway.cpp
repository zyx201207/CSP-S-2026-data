#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5,NN=5e5+5;
typedef long long ll;
struct node{
    int v,t;
};
struct Node{
	int x;
	ll s;
};
bool operator <(Node x,Node y){
	return x.s<y.s;
}
int c,n,m,d,q,w[NN],siz[N],vis[N];
ll dis[N][N];
vector<node>a[N];
vector<node>g[NN];
vector<node>G[N];
void dij(int s){
	memset(vis,0,sizeof vis);
	for(int i=1;i<=n;i++)dis[s][i]=2e18;
	dis[s][s]=0;
	priority_queue<Node>q;
	q.push({s,0});
	while(!q.empty()){
		auto u=q.top();q.pop();
		if(vis[u.x])continue;
		vis[u.x]=1;
		for(auto v:G[u.x])
		   if(dis[s][u.x]+v.t<dis[s][v.v])dis[s][v.v]=dis[s][u.x]+v.t,q.push({v.v,dis[s][v.v]});
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>siz[i];
		for(int j=1;j<=siz[i];j++){
			int x,t;
			cin>>x>>t;
			a[i].push_back({x,t});
			g[x].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++)
	   for(auto x:a[i])
	      for(auto y:g[x.v])
	        if(i!=y.v)G[i].push_back({y.v,x.t+y.t});
	for(int i=1;i<=n;i++)dij(i);
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=2e18;
		for(auto X:g[x])
		   for(auto Y:g[y])ans=min(ans,X.t+Y.t+dis[X.v][Y.v]);
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}/*
CCF,I love you.
I AC T2!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
CCF,you are my father
15:34 I got 200pts now
*/
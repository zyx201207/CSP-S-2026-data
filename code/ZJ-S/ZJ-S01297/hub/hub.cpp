#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=55;
ll c,t,n,k,ans,ch[N],vis[N];
vector<int> e[N];
void bfs1(int u,int f){
	vis[u]=1;
	for(int v:e[u]){
		if(v!=f&&!vis[v]) bfs1(v,u);
	}
}
int bfs2(int u){
	memset(vis,0,sizeof vis);
	queue<pair<int,int>> q;
	q.push({u,0});
	vis[u]=1;
	while(!q.empty()){
		auto t=q.front();q.pop();
		if(ch[t.first]) return t.second;
		for(int v:e[t.first]){
			if(!vis[v]) q.push({v,t.second+1});
		}
	}
	return -1;
}
void query(){
	memset(vis,0,sizeof vis);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(ch[i]&&!vis[i]){
			bfs1(i,0);
			cnt++;
		}
	}
	if(cnt>2) return;
	ll mx=0;
	for(int i=1;i<=n;i++){
		mx=max(mx,(ll)bfs2(i));
	}
	ans=min(ans,mx);
}
void dfs(int l,int tot){
	if(tot==k){
		query();
		return;
	}
	if(l==n+1) return;
	dfs(l+1,tot);
	ch[l]=1;
	dfs(l+1,tot+1);
	ch[l]=0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		ans=1e18;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			ll u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}
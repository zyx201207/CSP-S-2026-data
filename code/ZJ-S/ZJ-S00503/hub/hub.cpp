#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,ans;
int ch[100005],in[100005];
vector<int> G[100005];
int dis[100005];
bool vis[100005];
int bfs(int st){
	memset(vis,0,sizeof(vis));
	queue<int> q;
	q.push(st);dis[st]=0;vis[st]=1;
	while(q.size()){
		int p=q.front();q.pop();
		for(int v:G[p]){
			if(vis[v]) continue;
			dis[v]=dis[p]+1;
			vis[v]=1;
			q.push(v);
		}
	}
	int ld=1e9;
	for(int i=1;i<=n;i++) if(in[i]) ld=min(ld,dis[i]);
	return ld;
}
void dfs(int c,int x){
	if(c>n){
		if(x==k){
			int r=0;
			for(int i=1;i<=n;i++){
				if(!in[i]){
					r=max(r,bfs(i));
				}
			}
			ans=min(ans,r);
		}
		return;
	}
	dfs(c+1,x);
	ch[x+1]=c;in[c]=1;
	dfs(c+1,x+1);
	ch[x+1]=0;in[c]=0;
}
void solve(){
	ans=1e9;
	cin>>n>>k;
	for(int i=1;i<=n;i++) G[i].clear();
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	cout<<ans<<"\n";
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=1e6+6;
vector<int> ed[N];
int a[N],dis[N],f[N];
int c,_,ans,n,k;
bool vis[N];
queue<int> q;
void find(int u){
	if(dis[u]==0) return;
	dis[u]=0;
	for(int v:ed[u]) find(v);
}
bool check(){
	if(k==2) return 1;
	for(int i=1;i<=n;i++) dis[i]=0;
	for(int i=1;i<=k;i++) dis[a[i]]=1;
	int cnt=0;
	for(int i=1;i<=k;i++){
		if(dis[a[i]]) find(a[i]),cnt++;
		if(cnt>2) return 0;
	}
	return 1;
}
void dfs(int x){
	if(x==k+1){
		if(!check()) return;
		for(int i=1;i<=n;i++) dis[i]=n+1;
		while(!q.empty()) q.pop();
		for(int i=1;i<=k;i++) q.push(a[i]),dis[a[i]]=0;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(int v:ed[u]){
				if(dis[v]>dis[u]+1){
					dis[v]=dis[u]+1;					
					if(dis[v]>=ans) break;
					q.push(v);
				}
			}
		}
		int res=0;
		for(int i=1;i<=n;i++) res=max(res,dis[i]);
		ans=min(res,ans);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1,a[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) ed[i].clear();
	int u,v;
	for(int i=1;i<n;i++){
		cin>>u>>v;
		ed[u].pb(v);
		ed[v].pb(u);
	}
	
	ans=n+1;
	dfs(1);
	
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>_;
	while(_--) solve();
	return 0;
}
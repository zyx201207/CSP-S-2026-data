#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int Case,T,n,k;
int fa[N],vis[N];
int dis[N];
int ans=2e9;
vector<int>tr[N];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
bool check(){
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int u=1;u<=n;u++){
		if(!vis[u]) continue;
		for(int v:tr[u]){
			if(!vis[v]) continue;
			fa[find(u)]=find(v);
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]) continue;
		if(fa[i]==i){
			cnt++;
			if(cnt>2) return 0;
		}
	}
	return cnt<=2;
}
int bfs(){
	for(int i=1;i<=n;i++) dis[i]=0;
	queue<int>q;
	for(int i=1;i<=n;i++){
		if(vis[i]) q.push(i);
	}
	while(!q.empty()){
		int u=q.front(); q.pop();
		for(int v:tr[u]){
			if(vis[v]||dis[v]) continue;
			q.push(v); dis[v]=dis[u]+1;
		}
	}
	int ma=0;
	for(int i=1;i<=n;i++) ma=max(ma,dis[i]);
	return ma;
}
void dfs(int i,int l){ // ±©Á¦Ñ¡µã 
	if(l>k){
		if(!check()) return ;
		int maxn=bfs();
		ans=min(ans,maxn);
		return ;
	}
	if(i>n) return ;
	for(int j=i;j<=n;j++){
		vis[j]=1;
		dfs(j+1,l+1);
		vis[j]=0;
		dfs(j+1,l);
	}
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>Case>>T;
	while(T--){
		ans=2e9;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v; cin>>u>>v;
			tr[u].push_back(v);
			tr[v].push_back(u);
		}
		dfs(1,1);
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++) tr[i].clear();
	}
	return 0;
}

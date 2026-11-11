#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e6+5;
struct node{
	int v,nxt;
}e[MAXN<<1];
int c,p[MAXN],tot,n,k;
void addedge(int u,int v){
	e[++tot].v=v;
	e[tot].nxt=p[u];
	p[u]=tot;
}
bool vis[MAXN];
int path[MAXN],Min=1e9,dep[MAXN];
int lca(int u,int v){//这场的暴力怎么都这么困难 
	
}
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	for(int i=p[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(v==fa){
			continue;
		}
		dfs(v,u);
	}
}
void builtin(int cnt){
	if(cnt>k){
		Min=1e9;
		dfs(1,0);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			path[cnt]=i;
			vis[i]=1;
			builtin(cnt+1);
			vis[i]=0;
		}
	}
}
void solve(){
	cin>>n>>k;
	if(c==13 || c==14){
		int x=(n-1)/k,ans=0;
		for(int i=2;i*(i+1)<=n;i++){
			ans=i-1;
		}
		cout<<ans<<endl;
		return;
	}
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		addedge(u,v);
		addedge(v,u);
	}
	builtin(1);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
/*










((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((












*/

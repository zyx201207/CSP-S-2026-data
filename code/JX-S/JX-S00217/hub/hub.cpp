#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int grand[N][22];
int depth[N];
vector<int> g[N];
int n,k;
void dfs(int now,int lst){
	for(int nxt:g[now]){
		if(nxt==lst) continue;
		depth[nxt]=depth[now]+1;
		grand[nxt][0]=now;
		dfs(nxt,now);
	}
}
int lca(int u,int v);
void init(){
	for(int j=1;j<=20;j++){
		for(int i=1;i<=n;i++){
			grand[i][j]=grand[grand[i][j-1]][j-1];
		}
	}
}
int dis(int u,int v){
	return (depth[u]+depth[v]-2*depth[lca(u,v)]);
}
int fa[N];
int Find(int x){
	if(fa[x]==x) return x;
	fa[x]=Find(fa[x]);
	return fa[x];
}
void Union(int x,int y){
	fa[Find(y)]=Find(x);
}
void finit(){
	for(int i=1;i<=n;i++) fa[i]=i;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		depth[1]=1;
		dfs(1,0);
		init();
		if(n<=10){
			int ans=n;
			for(int s=1;s<(1<<n);s++){
				if(__builtin_popcount(s)!=k) continue;
				finit();
				for(int i=1;i<=n;i++){
					if((s>>(i-1))&1){
						for(int j:g[i]){
							if((s>>(j-1))&1){
								Union(i,j);
							}
						}
					}
				}
				int cnt=0;
				for(int i=1;i<=n;i++){
					if((s>>(i-1))&1) cnt+=(fa[i]==i);
				}
				if(cnt>2) continue;
				int res=0;
				for(int i=1;i<=n;i++){
					int cur=n;
					for(int j=1;j<=n;j++){
						if((s>>(j-1))&1) cur=min(cur,dis(i,j));
					}
					res=max(res,cur);
				}
				ans=min(ans,res);
			}
			cout<<ans<<"\n";
			for(int i=1;i<=n;i++) g[i].clear();
			continue;
		}
	}
}
int lca(int u,int v){
	if(u==v) return u;
	if(depth[u]<depth[v]) swap(u,v);
	for(int i=20;i>=0;i--){
		if(depth[grand[u][i]]>=depth[v]) u=grand[u][i];
	}
	if(u==v) return u;
	for(int i=20;i>=0;i--){
		if(grand[u][i]!=grand[v][i]){
			u=grand[u][i],v=grand[v][i];
		}
	}
	return grand[u][0];
}

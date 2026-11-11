#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e6+5;
int yuanshen,t;
int n,k,a[MAXN],fa[MAXN],ans=2e9;
int dep[MAXN],f[MAXN],top[MAXN],son[MAXN],siz[MAXN];
int head[MAXN],tot;
int mp[1005][1005];
struct Edge{
	int to,next;
}e[MAXN<<1];
inline void add(int u,int v){
	e[++tot].to=v;
	e[tot].next=head[u];
	head[u]=tot;
}
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int xx=find(x),yy=find(y);
	if(xx==yy) return;
	fa[xx]=yy;
}
void dfs1(int u,int fat){
	siz[u]=1;
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].to;
		if(v==fat) continue;
		dep[v]=dep[u]+1;
		f[v]=u;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]]) son[u]=v;
	}
}
void dfs2(int u,int t){
	top[u]=t;
	if(son[u]) dfs2(son[u],t);
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].to;
		if(v==f[u]||v==son[u]) continue;
		dfs2(v,v);
	}
}
int LCA(int x,int y){
	int fx=top[x],fy=top[y];
	while(fx!=fy){
		if(fx<fy) swap(x,y),swap(fx,fy);
		x=fx,fx=top[fx];
	}
	return dep[x]>dep[y]?y:x;
}
void dfs(int step){
	if(step>k){
		int cnt=k,mx=-2e9;
		for(int i=1;i<k;i++){
			for(int j=i+1;j<=k;j++){
				if(mp[a[i]][a[j]]){
					merge(a[i],a[j]);
					cnt--;
				}
			}
		}
		if(cnt>2) return;
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++) mx=max(mx,dep[j]+dep[i]-2*dep[LCA(i,j)]);
		}
		ans=min(ans,mx);
	}
	for(int i=a[step-1]+1;i<=n;i++){
		a[step]=i;
		dfs(step+1);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>yuanshen>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			add(u,v),add(v,u);
			mp[u][v]=mp[v][u]=1;
		}
		for(int i=1;i<=n;i++) fa[i]=i;
		dfs(1);
		cout<<ans<<"\n";
	}
	return 0;
}

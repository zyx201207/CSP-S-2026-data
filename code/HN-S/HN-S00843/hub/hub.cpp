#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1000100;
int c,t,n,k,ans,tot;
vector<int> g[N];
bool f[N],be[N],vis[N];
int dep[N],fa[N],siz[N],son[N],top[N],cs[N],best[N];
mt19937 s(time(NULL));
void dfs1(int u,int f){
	fa[u]=f;
	dep[u]=dep[f]+1;
	siz[u]=1;
	int mx=-1;
	for(auto v:g[u]){
		if(v==f) continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[v]>mx){
			mx=siz[v];
			son[u]=v;
		}
	}
}
void dfs2(int u,int tp){
	top[u]=tp;
	if(son[u]) dfs2(son[u],tp);
	for(auto v:g[u]){
		if(v==fa[u]||v==son[u]) continue;
		dfs2(v,v);
	}
}
int lca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		x=fa[top[x]];
	}
	return dep[x]>dep[y]?y:x;
}
void build(int u){
	if(tot>=k) return;
	cs[++tot]=best[tot]=u;
	f[u]=be[u]=1;
	for(auto v:g[u]) if(!f[v]) build(v);
}
int calc(){
	int res=0;
	for(int i=1;i<=n;i++){
		if(f[i]) continue;
		int mn=INT_MAX;
		for(int j=1;j<=tot;j++) mn=min(mn,dep[i]+dep[cs[j]]-2*dep[lca(i,cs[j])]);
		res=max(res,mn);
	}
	return res; 
}
void dfs(int u){
	vis[u]=1; 
	for(auto v:g[u]) if(!vis[v]&&f[v]) dfs(v);
}
bool check(){
	for(int i=1;i<=n;i++) vis[i]=0;
	int cnt=0;
	for(int i=1;i<=tot;i++) if(!vis[cs[i]]){
		dfs(cs[i]);
		cnt++;
	}
	return cnt<=2;
}
void SA(){
	double T=2333.0,dT=0.996;
	if(s()%2) for(int i=1;i<=n;i++) f[i]=be[i],cs[i]=best[i];
	int cur=calc();
	while(T>1e-3){
		int id=s()%tot+1,nx=s()%n+1,old=cs[id];
		if(f[nx]){
			T*=dT;
			continue;
		}
		f[old]=0,f[nx]=1;
		cs[id]=nx;
		if(!check()){
			T*=dT;
			f[old]=1,f[nx]=0,cs[id]=old;
			continue;
		}
		int nv=calc(),dE=nv-cur;
		if(dE<0||exp((double)-dE/T)>(double)s()/(double)s.max()){
			cur=nv;
			if(cur<ans){
				ans=cur;
				for(int i=1;i<=n;i++) be[i]=f[i],best[i]=cs[i];
			}
		}
		else f[old]=1,f[nx]=0,cs[id]=old;
		T*=dT;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			g[i].clear();
			dep[i]=fa[i]=top[i]=son[i]=siz[i]=f[i]=be[i]=vis[i]=cs[i]=best[i]=0;
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u); 
		}
		tot=0;
		dfs1(1,0);dfs2(1,1);
		build(1);
		ans=calc();
		for(int i=1;i<=10;i++) SA();
		cout<<ans<<"\n";
	}
	return 0;
}
/*
AFO
*/

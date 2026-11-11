#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return x;
}
const int N=1000005;
int n,k;
int tot,head[N],to[N*2],nxt[N*2];
void addedge(int u,int v){
	tot++,to[tot]=v;
	nxt[tot]=head[u],head[u]=tot;
}
int fa[N][25],dep[N];
void dfs(int u,int f){
	fa[u][0]=f,dep[u]=dep[f]+1;
	for(int i=1;i<=20;i++) fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f) continue;
		dfs(v,u);
	}
}
int lca(int u,int v){
	if(dep[u]>dep[v]) swap(u,v);
	for(int i=20;i>=0;i--)
		if(dep[fa[v][i]]>=dep[u]) v=fa[v][i];
	if(u==v) return u;
	for(int i=20;i>=0;i--)
		if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
int dist(int u,int v){
	int l=lca(u,v);
	return dep[u]+dep[v]-2*dep[l];
}
bool del[N],vis[N];
void dfs(int u){
	vis[u]=true;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(vis[v]||del[v]) continue;
		dfs(v);
	}
}
void solve(){
	n=read(),k=read(),tot=0;
	for(int i=1;i<=n;i++) head[i]=0;
	for(int i=1;i<n;i++){
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}
	dfs(1,0);
	int ans=1e9;
	for(int s=0;s<(1<<n);s++){
		vector<int> ve;
		for(int i=1;i<=n;i++){
			vis[i]=false;
			if(s>>(i-1)&1) del[i]=false,ve.push_back(i);
			else del[i]=true; 
		}
		if(ve.size()!=k) continue;
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(!del[i]&&!vis[i]){
				cnt++;
				dfs(i);
			}
		}
		if(cnt!=2) continue;
		int val=0;
		for(int i=1;i<=n;i++){
			if(!del[i]) continue;
			int tmp=1e9;
			for(int u:ve) tmp=min(tmp,dist(u,i));
			val=max(val,tmp);
		}
		ans=min(ans,val);
	}
	cout<<ans<<endl;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=read(),t=read();
	while(t--) solve();
	return 0;
}
/*yyx*/
/*
CCF don't let me ¹Ò·Ö pls 

CCF give me 7 dog pls, I will do everything
CCF give me 7 dog pls, I will do everything
CCF give me 7 dog pls, I will do everything

Ä¿Ç°247 
*/ 

#include<bits/stdc++.h>
#define int long long
#define debug printf("!!!\n")
using namespace std;
int read(){
	char c=getchar();
	int x=0,f=1;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
	return x*f;
}
void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
void write(int x,char c){
	write(x);putchar(c);
}
const int N=1e6+5;
int _,n,k,dep[N],fa[N][21];
vector<int> g[N];
bool vis[N],col[N];
void dfs(int u,int fat){
	dep[u]=dep[fat]+1;fa[u][0]=fat;
	for(int i=1;i<21;i++) fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int v:g[u]) if(v!=fat) dfs(v,u);
}
void dfs1(int u){
	for(int v:g[u]){
		if(!col[v]||vis[v]) continue;
		vis[v]=1;
		dfs1(v);
	}
}
int LCA(int x,int y){
	if(x==y) return x;
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=20;~i;i--){
		if(dep[fa[x][i]]>=dep[y]) x=fa[x][i];
	}
	if(x==y) return x;
	for(int i=20;~i;i--){
		if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	}
	return fa[x][0];
}
int dis(int x,int y){
	int lca=LCA(x,y);
	return dep[x]+dep[y]-2*dep[lca];
}
int get(int x){
	int res=1e18;
	for(int i=1;i<=n;i++){
		if(col[i]) res=min(res,dis(i,x));
	}
	return res;
}
int calc(){
	int res=0;
	for(int i=1;i<=n;i++) res=max(res,get(i));
	return res;
}
void solve(){
	int ans=1e18;
	n=read();k=read();
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<n;i++){
		int u=read(),v=read();
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	int mx=1ll<<n;
	for(int sta=1;sta<mx;sta++){
		if(__builtin_popcount(sta)!=k) continue;
		for(int i=1;i<=n;i++) vis[i]=0,col[i]=0;
		for(int i=1;i<=n;i++) col[i]=(sta>>(i-1)&1);
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(!vis[i]&&col[i]) vis[i]=1,dfs1(i),cnt++;
		}
		if(cnt>2) continue;
		ans=min(ans,calc());
	}
	write(ans,'\n');
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	_=read();
	for(int t=read();t--;solve());
	return 0;
}
/*
0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
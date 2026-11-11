#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int mx=1e6+10;
const int inf=0x3f3f3f3f;
int c,n,m,d,q;
ll w1[mx];
int hd[mx],nxt[mx],to[mx],cnt=0;
ll w[mx];
void add(int u,int v,int h){
	to[++cnt]=v;
	w[cnt]=h;
	nxt[cnt]=hd[u];
	hd[u]=cnt;
}
int a[mx];
int f[mx][30];
int dep[mx];
ll dis[mx];
void dfs(int u,int fa){
	f[u][0]=fa;
	dep[u]=dep[fa]+1;
	for(int i=1;i<30;i++) f[u][i]=f[f[u][i-1]][i-1];
	for(int i=hd[u];i;i=nxt[i]){
		int v=to[i],h=w[i];
		if(v==fa) continue;
		dis[v]=dis[u]+h;
		dfs(v,u);
	}
}

int lca(int x,int y){
	if(dep[x]>dep[y]) swap(x,y);
	for(int i=29;i>=0;i--){
		if(dep[f[y][i]]>=dep[x]) y=f[y][i];
	}
	if(x==y) return y;
	for(int i=29;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			x=f[x][i],y=f[y][i];
		}
	}
	return f[y][0];
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w1[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int u,h;
			cin>>u>>h;
			add(m+i,u,h);
			add(u,m+i,h);
		}
	}
	dfs(1,0);
	while(q--){
		int x,y;
		cin>>x>>y;
		int ff=lca(x,y);
		ll res=dis[x]+dis[y]-2*dis[ff]+w1[x]+w1[y];
		cout<<res<<"\n";
	}
	return 0;
}

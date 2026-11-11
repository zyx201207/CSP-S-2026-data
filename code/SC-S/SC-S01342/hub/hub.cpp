#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int c,T,n,m,f[N];
vector<int> a[N];
int ans,b[N],l[N],vis[N],d[N];
queue<int> q;
void check(){
	int tt=0,ac=0;
	while(!q.empty())q.pop();
	for(int i=1;i<=n;i++){
		if(b[i]&&!b[f[i]])tt++;
		if(b[i]){
			vis[i]=1;d[i]=0;
			q.push(i);
		}
		else vis[i]=0,d[i]=1e9;
	}
	if(tt>2)return ;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(auto v:a[x])
			if(!vis[v]){
				d[v]=d[x]+1;
				vis[v]=1;
				q.push(v);
			}
	}
	for(int i=1;i<=n;i++)ac=max(ac,d[i]);
	ans=min(ans,ac);
	return ;
}
void dfs2(int x,int fa){
	f[x]=fa;
	l[x]=0;
	for(auto v:a[x])
		if(v!=fa){
			dfs2(v,x);
			l[x]=max(l[x],l[v]+1);
		}
	return ;
}
void dfs(int x,int y){
	if(y==m){
		check();
		return ;
	}
	if(x>n)return ;
	dfs(x+1,y);
	b[x]=1;
	dfs(x+1,y+1);
	b[x]=0;
	return ;
}
struct solve_big{
	int n,m;
	vector<int> a[N];
	int f[N][N],dep[N],g[N][25],l[N],sz[N],tt[N];
	int mx[N],mx2[N],mx3[N],ii[N],ii2[N];
	void dfs(int x,int fa){
		g[x][0]=fa;
		dep[x]=dep[fa]+1;
		for(auto v:a[x])
			if(v!=fa){
				dfs(v,x);
				sz[x]+=sz[v];
				l[x]=max(l[x],l[v]+1);
			}
		f[x][1]=0;
		sz[x]++;
		for(auto v:a[x])
			if(v!=fa){
				//不选
				for(int j=min(m,sz[x]);j;j--){
					f[x][j]=max(f[x][j],l[v]+1);
					for(int t=1;t<=min(j-1,sz[v]);t++)
						f[x][j]=min(f[x][j],max(f[x][j-t],f[v][t]));
				}
			}
		return ;
	}
	void dfs2(int x,int fa){
		mx[x]=mx2[x]=ii[x]=mx3[x]=ii2[x]=0;
		for(auto v:a[x])
			if(v!=fa){
				if(l[v]+1>mx[x])mx3[x]=mx2[x],ii2[x]=ii[x],mx2[x]=mx[x],mx[x]=l[v]+1,ii[x]=v;
				else if(l[v]+1>mx2[x])mx2[x]=l[v]+1,ii2[x]=v;
				else if(l[v]+1>mx3[x])mx3[x]=l[v]+1;
			}
		for(auto v:a[x])
			if(v!=fa){
				tt[v]=tt[x]+1;
				if(ii[x]==v)tt[v]=max(tt[v],mx2[x]+2);
				else tt[v]=max(tt[v],mx[x]+2);
				dfs2(v,x);
			}
		return;
	}
	int lca(int x,int y){
		if(dep[x]>dep[y])swap(x,y);
		int w=dep[y]-dep[x];
		for(int j=11;~j;j--)
			if((w&(1<<j)))y=g[y][j];
		if(x==y)return x;
		for(int j=11;~j;j--)
			if(g[x][j]!=g[y][j])x=g[x][j],y=g[y][j];
		return g[x][0];
	}
	void sol(){
		while(T--){
			int ans=1e9;
			cin>>n>>m;
			for(int i=1;i<=n;i++){
				a[i].clear();
				for(int j=0;j<=m;j++)f[i][j]=1e9;
			}
			for(int i=1;i<n;i++){
				int u,v;
				cin>>u>>v;
				a[u].push_back(v);
				a[v].push_back(u);
			}
			for(int x=1;x<=n;x++){
				for(int i=1;i<=n;i++){
					sz[i]=tt[i]=l[i]=0;
					for(int j=0;j<=m;j++)f[i][j]=1e9;
				}
				dfs(x,0);
				for(int j=1;j<=11;j++)
					for(int k=1;k<=n;k++)
						g[k][j]=g[g[k][j-1]][j-1];
				dfs2(x,0);
				for(int u=1;u<=n;u++){
					ans=min(ans,max(f[u][min(sz[u],m)],tt[u]));
					for(int v=1;v<=n;v++){
						int gg=0,pr,pr2;
						int w=lca(u,v);
						if(w==u||w==v||sz[u]+sz[v]<m)continue ;
						pr=u;pr2=v; 
						for(int y=u;g[y][0]!=w;pr=y=g[y][0]){
							int fa=g[y][0],t=mx[fa];
							if(ii[fa]==y)t=mx2[fa];
							gg=max(gg,min(t+dep[u]-dep[fa],t+dep[v]+dep[fa]-dep[w]*2));
						}
						for(int y=v;g[y][0]!=w;pr2=y=g[y][0]){
							int fa=g[y][0],t=mx[fa];
							if(ii[fa]==y)t=mx2[fa];
							gg=max(gg,min(t+dep[v]-dep[fa],t+dep[u]+dep[fa]-dep[w]*2));
						}
						if(ii[w]!=pr&&ii[w]!=pr2)gg=max(gg,min(dep[u],dep[v])-dep[w]+mx[w]);
						if(ii2[w]!=pr&&ii2[w]!=pr2)gg=max(gg,min(dep[u],dep[v])-dep[w]+mx2[w]);
						gg=max(gg,min(dep[u],dep[v])-dep[w]+mx3[w]);
						for(int j=1;j<m;j++){
							ans=min(ans,max(f[u][j],max(gg,max(f[v][m-j],min(dep[u]-dep[w],dep[v]-dep[w])+tt[w]))));
						}
					}
				}
			}
			cout<<ans<<'\n';
		}
		return ;
	}
}tt;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	if(c>=4){
		tt.sol();
		return 0;
	}
	while(T--){
		cin>>n>>m;
		ans=1e9;
		for(int i=1;i<=n;i++)
			a[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		dfs2(1,0);
		dfs(1,0);
		cout<<ans<<'\n';
	}
	return 0;
} 
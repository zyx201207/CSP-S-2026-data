#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int INF=2e9;
int c,n,k;
int p[N],vis[N];
int ans;
int f[N];
vector<int>ed[N];
int find(int x){
	if(x==f[x])return x;
	return f[x]=find(f[x]);
}
bool check(){
	for(int i=1;i<=k;i++){
		f[p[i]]=p[i];
	}
	for(int i=1;i<=k;i++){
		int u=p[i];
		for(int v:ed[u]){
			if(!vis[v])continue;
			f[find(v)]=find(u);
		}
	}
	vector<int>get(n+1,0);
	int cnt=0;
	for(int i=1;i<=k;i++){
		if(!get[find(p[i])])cnt++;
		get[find(p[i])]=1;
	}
	return cnt<=2;
}
int dep[N],fa[N][25];

void dfs1(int u,int father){
	dep[u]=dep[father]+1;
	fa[u][0]=father;
	for(int i=1;i<=20;i++){
		fa[u][i]=fa[fa[u][i-1]][i-1];
	}
	for(int v:ed[u]){
		if(v==father)continue;
		dfs1(v,u);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=20;i>=0;i--){
		if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
	}
	for(int i=20;i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	if(x==y)return x;
	else return fa[x][0];
}

void dfs(int depth){
	if(depth==k+1){
		if(!check())return;
		int r=0;
		for(int x=1;x<=n;x++){
			int d=INF;
			for(int i=1;i<=k;i++){
				int y=p[i];
				d=min(dep[x]+dep[y]-dep[lca(x,y)]*2,d);
			}
			r=max(r,d);
		}
		ans=min(r,ans);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		p[depth]=i;
		vis[i]=1;
		dfs(depth+1);
		vis[i]=0;
	}
}
void solve(){
	cin>>n>>k;
	ans=INF;
	for(int i=1;i<=n;i++)ed[i].clear();
	for(int i=1;i<=n-1;i++){
		int u,v;
		cin>>u>>v;
		ed[u].push_back(v);
		ed[v].push_back(u);
	}
	dfs1(1,0);
	if(c<=3){
		dfs(1);
		cout<<ans<<endl;
	}
}
int t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}

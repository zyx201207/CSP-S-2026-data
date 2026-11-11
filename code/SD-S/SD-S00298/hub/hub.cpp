#include<bits/stdc++.h>
#define int long long
using namespace std;
const int xx=1e6+5e2;
const int mod=998244353;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+ch-48;
		ch=getchar();
	}
	return x*f;
}
int n,k;
struct node{
	int nex,fro,to,val; 
}e[xx<<1];
int he[xx],tot;
void add(int u,int v,int w){
	e[++tot].nex=he[u];
	e[tot].fro=u;
	e[tot].to=v;
	e[tot].val=w;
	he[u]=tot;
}
int dep[xx],f[xx][25];
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	f[u][0]=fa;
	for(int i=1;i<=21;++i){
		f[u][i]=f[f[u][i-1]][i-1];
	}
	for(int i=he[u];i;i=e[i].nex){
		int v=e[i].to;
		if(v==fa) continue;
		dfs(v,u);
	}
}
int lca(int x,int y){
	if(dep[x]>dep[y]) swap(x,y);
	for(int i=21;i>=0;--i){
		if(dep[f[y][i]]>dep[x]) y=f[y][i];
	}
	if(x==y) return x;
	for(int i=21;i>=0;--i){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
int ans=0x3f3f3f3f;
int fa[xx],sizes[xx];
int ltk;
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy) return;
	--ltk;
	if(sizes[fx]>sizes[fy]){
		fa[fy]=fx;
		sizes[fx]+=sizes[fy];
	}
	else{
		fa[fx]=fy;
		sizes[fy]+=sizes[fx];
	}
}
void dfs2(vector<int> a,vector<bool> vis,int now,int cnt){
	if(now>n&&cnt<k) return;
	if(cnt==k){
		ltk=k;
		for(int i=1;i<=n;++i){
			fa[i]=i;
			sizes[i]=1;
		}
		for(int i=1;i<2*n-2;i+=2){
			int u=e[i].fro,v=e[i].to;
			if(vis[u]&&vis[v]){
				merge(u,v);
			}
		}
		if(ltk>2) return;
		int nnow=0;
		for(int i=1;i<=n;++i){
			int dis=0x3f3f3f3f;
			for(int j=0;j<k;++j){
				//if(i==a[j]) 
				int l=lca(i,a[j]);
				dis=min(dis,dep[i]+dep[a[j]]-dep[l]-dep[f[l][0]]);
			}
			nnow=max(nnow,dis);
		}
		ans=min(ans,nnow);
		return;
	}
	dfs2(a,vis,now+1,cnt);
	a.push_back(now);
	vis[now]=1;
	dfs2(a,vis,now+1,cnt+1);
	a.pop_back();
	vis[now]=0;
}
vector<int> a;
void solve(){
	ans=0x3f3f3f3f;
	n=read(),k=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		add(u,v,1);
		add(v,u,1);
	}
	vector<bool> vis;
	memset(f,0,sizeof(f));
	memset(dep,0,sizeof(dep));
	dfs(1,0);
	vis.resize(2*n+1);
	while(a.size()) a.pop_back();
	for(int i=1;i<=n;++i){
		vis[i]=0;
	}
	dfs2(a,vis,1,0);
	cout<<ans<<'\n';
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int T=1,c;
	cin>>c>>T;
	while(T--){
		solve();
	}
}


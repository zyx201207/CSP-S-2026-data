#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,T,n,k,dep[N],f[N][22],ans[N],mdis[N],op[N];
vector<int> v[N];
void dfs(int x,int fa){
	dep[x]=dep[fa]+1,f[x][0]=fa;
	for(int i=1;i<=20;i++) f[x][i]=f[f[x][i-1]][i-1];
	for(int i=0;i<v[x].size();i++){
		int y=v[x][i];
		if(y!=fa) dfs(y,x);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=20;i>=0;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	if(x==y) return x;
	for(int i=20;i>=0;i--) if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}
int dis(int x,int y) {return dep[x]+dep[y]-2*dep[lca(x,y)];}
void dfs1(int x,int fa,int cnt,int res,int p){
	ans[cnt]=min(ans[cnt],res);
	if(cnt==k) return;
	for(int i=0;i<v[x].size();i++){
		int y=v[x][i];
		if(y==fa) continue;
		int res1=res,p1=p;
		if(op[y]==op[x]) res1=min(mdis[y],mdis[x]);
		else if(mdis[y]<mdis[x]) res1=mdis[y],p1=op[y];
		dfs1(y,x,cnt+1,res1,p1);
	}
}
int vis[N],anss;
bool check(){
	int cnt=0,sum=0;
	for(int i=1;i<=n;i++){
		if(vis[i]) sum++;
		if(sum>k) return 0;
		if(vis[i]&&!vis[f[i][0]]) cnt++;
		if(cnt>2) return 0;
	}
	return 1;
}
int get(){
	int res=0;
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		int w=2e9;
		for(int j=1;j<=n;j++){
			if(!vis[j]) continue;
			w=min(w,dis(i,j));
		}
		res=max(res,w);
	}
	return res;
}
void dfs2(int x){
	if(x>n){
		if(check()) anss=min(anss,get());
		return;
	}
	vis[x]=1,dfs2(x+1),vis[x]=0,dfs2(x+1);
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=k;i++) ans[i]=2e9;
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0);
	if(n<=10){
		anss=2e9,dfs2(1);
		cout<<anss<<'\n';
		for(int i=1;i<=n;i++) v[i].clear();
		return;
	}
	for(int i=1;i<=n;i++){
		mdis[i]=0;
		for(int j=1;j<=n;j++){
			int z=dis(i,j);
			if(mdis[i]<z) mdis[i]=z,op[i]=j;
		}
	}
	for(int i=1;i<=n;i++) dfs1(i,0,1,mdis[i],op[i]);
	int res=ans[k];
	for(int i=1;i<k;i++) res=min(res,max(ans[i],ans[k-i]));
	cout<<res<<'\n';
	for(int i=1;i<=n;i++) v[i].clear();
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--) solve();
	return 0;
}
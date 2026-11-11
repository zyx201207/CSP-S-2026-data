#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
using namespace std;
const int inf=2e9;
const int maxn=1000005;
vector<int> a[maxn];
int f[maxn][21];
int dep[maxn];
int dis[maxn];
int vis[maxn];
int vs[maxn];
int C,_;
int n,m;
int ans;
void dfs(int x,int fa){
	dep[x]=dep[fa]+1;
	f[x][0]=fa;
	for(int i=1;i<=20;i++) f[x][i]=f[f[x][i-1]][i-1];
	int l=a[x].size();
	for(int i=0;i<l;i++){
		int nx=a[x][i];
		if(nx!=fa) dfs(nx,x);
	}
}
int lca(int x,int y){
	if(x==y) return x;
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=20;i>=0;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	if(x==y) return x;
	for(int i=20;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
int bfs(int sx){
	for(int i=1;i<=n;i++) vs[i]=0;
	queue<int> que;
	que.push(sx);
	dis[sx]=0;
	vs[sx]=1;
	while(!que.empty()){
		int x=que.front();
		que.pop();
		if(vis[x]) return dis[x];
		int l=a[x].size();
		for(int i=0;i<l;i++){
			int nx=a[x][i];
			if(!vs[nx]){
				if(vis[nx]) return dis[x]+1;
				dis[nx]=dis[x]+1;
				vs[nx]=1;
				que.push(nx);
			}
		}
	}
}
int calc(){
	int tot=0;
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		int d=bfs(i);
		if(d>tot) tot=d; 
	}
	return tot;
}
void dfs3(int x){
	vs[x]=1;
	int l=a[x].size();
	for(int i=0;i<l;i++){
		int nx=a[x][i];
		if(vis[nx]&&!vs[nx]) dfs3(nx);
	}
}
bool check(){
	for(int i=1;i<=n;i++) vs[i]=0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(vis[i]&&!vs[i]){
			cnt++;
			dfs3(i);
		}
	}
	return (cnt<=2);
}
void dfs2(int x,int has){
	if(has+(n-x+1)<m||has>m) return;
	if(x>n){
		if(!check()) return;
		int s=calc();
		if(vis[2]==1&&vis[3]==1&&vis[10]==1) cout<<s<<"\n\n";
		if(s<ans) ans=s;
		return;
	}
	vis[x]=0;
	dfs2(x+1,has);
	vis[x]=1;
	dfs2(x+1,has+1);
}
void solve(){
	for(int i=1;i<=n;i++) a[i].clear();
	cin>>n>>m;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	if(C<=3){
		ans=inf;
		dfs2(1,0);
		cout<<ans<<"\n";
		return;
	}
	if(C==7){
		ans=0;
		dfs(1,0);
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				
			}
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	cin>>C>>_;
	while(_--) solve(); 
	return 0;
}

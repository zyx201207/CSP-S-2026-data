#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int c,t,n,k,f[N][21],dep[N],ans=1e9;
vector<int> e[N];
bool ok[N],flag[N];
void dfs(int u,int fa){
	dep[u]=dep[fa]+1,f[u][0]=fa;
	for (auto v:e[u]){
		if (v==fa) continue;
		dfs(v,u);
	}
}
void dp(int u){
	flag[u]=1;
	for (auto v:e[u]){
		if (flag[v] || !ok[v]) continue;
		dp(v);
	}
}
void init(){
	for (int j=1;j<=20;j++)
		for (int i=1;i<=n;i++)
			f[i][j]=f[f[i][j-1]][j-1];
}
int lca(int u,int v){
	if (dep[u]<dep[v]) swap(u,v);
	for (int i=20;i>=0;i--) if (dep[f[u][i]]>=dep[v]) u=f[u][i];
	if (u==v) return u;
	for (int i=20;i>=0;i--) if (f[u][i]!=f[v][i]) u=f[u][i],v=f[v][i];
	return f[u][0];
}
int dist(int u,int v){
	return dep[u]+dep[v]-2*dep[lca(u,v)];
}
bool check(){
	fill(flag+1,flag+n+1,0);
	int pos=-1;
	for (int i=1;i<=n;i++){
		if (ok[i]){
			pos=i;
			break;
		}
	}
	dp(pos);
	pos=-1;
	for (int i=1;i<=n;i++){
		if (ok[i] && !flag[i]){
			pos=i;
			break;
		}
	}
	if (pos==-1) return 1;
	else{
		dp(pos);
		for (int i=1;i<=n;i++) if (ok[i] && !flag[i]) return 0;
		return 1;
	}
}
void solve(int x,int cnt){
	if (cnt>k) return;
	if (x==n+1){
		if (cnt<k) return;
		if (check()){
			int mx=0;
			vector<int> box;
			for (int i=1;i<=n;i++) if (ok[i]) box.push_back(i);
			for (int i=1;i<=n;i++){
				int mn=1e9;
				for (auto x:box) mn=min(mn,dist(i,x));
				mx=max(mx,mn); 
			}
			ans=min(ans,mx);
		}
		return;
	}
	ok[x]=1;
	solve(x+1,cnt+1);
	ok[x]=0;
	solve(x+1,cnt);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while (t--){
		scanf("%d%d",&n,&k);
		for (int i=1;i<=n;i++) e[i].clear();
		for (int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs(1,0);
		init();
		ans=1e9;
		solve(1,0);
		printf("%d\n",ans);
	}
	return 0;
} 

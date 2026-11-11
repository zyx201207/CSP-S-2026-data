#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define PII pair<int,int>
#define db double
const int N  = 5e5+5;
const int inf = 1e18;
int id = 0;
int n,k;
vector<int>g[N];
int dp1[N];
int dp2[N];
int up[N];
int vis[N];
int dep[N];
void init(){
	for(int i = 1;i <= n;i++){
		g[i].clear();
	}
}
int dfs(int x,int fa,int mid,int mx){
	dep[x]=dep[fa]+1;
	for(int tt = 0;tt < g[x].size();tt++){
		int v = g[x][tt];
		if(v == fa)continue;
		mx = max(mx,dfs(v,x,mid,0));
//		mx = max(mx,dep[v]);
	}
	if(mx-dep[x]>mid){
		mx=0;
		vis[x]=1;
	}
	return mx;
}
void dfs1(int x,int fa,int u){
	dp1[x]=!vis[x];
	up[x]=u;
	if(vis[x])u=x;
	for(int tt = 0;tt < g[x].size();tt++){
		int v = g[x][tt];
		if(v == fa)continue;
		dfs1(v,x,u);
		dp1[x]+=dp1[v];
	}
}
void dfs2(int x,int fa){
	for(int tt = 0;tt < g[x].size();tt++){
		int v = g[x][tt];
		if(v == fa)continue;
		dp2[v]=dp2[x]+dp1[x]-dp1[v];
		dfs2(v,x); 
	}
}
int check(int mid){
	for(int i = 0;i <= n;i++){
		dp1[i]=dp2[i]=inf;
		up[i]=i;
		vis[i]=0;
		dep[i]=0;
	}
	dp2[1]=0;
	dp2[0]=0;
	dfs(1,0,mid,0);
	dfs1(1,0,0);
	dfs2(1,0);
	int ans = inf;
	int tt = 0;
	for(int i = 1;i <= n;i++){
		if(!up[i])up[i]=i;
		ans=min(ans,dp1[i]+dp2[up[i]]);
		tt += vis[i];
	}
	return ans+tt <= k;
}
int vvis[N];
int viss[N];
void dfss(int x,int fa){
	viss[x]=1;
	for(int tt = 0;tt < g[x].size();tt++){
		int v = g[x][tt];
		if(viss[v]||!vvis[v])continue;
		dfss(v,x); 
	}
}
int vvvis[N];
int ddfs(int x,int fa){
	int mi = inf;
	vvvis[x]=1;
	for(int tt = 0;tt < g[x].size();tt++){
		int v = g[x][tt];
		if(vvvis[v])continue;
		mi = min(mi,ddfs(v,x)+1); 
	}
	return mi;
}
void solve(){
	cin >> n >> k;
	init();
	for(int i = 1;i < n;i++){
		int u,v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if(id>=4){
	int l = 0,r = n*n;
	int ans = 1;
	while(l <= r){
		int mid = l + r >> 1;
		if(check(mid)){
			r=mid-1;
			ans=mid;
		}
		else{
			l = mid + 1;
		}
	}
	cout << ans << '\n';
	return;
	}
	int ans = inf;
	for(int i = 0;i < (1ll << n);i++){
		for(int j = 0;j < n;j++){
			if((i >> j)&1){
				vvis[j+1]=1;
			}
		}
		int cnt = 0;
		for(int i = 1;i <= n;i++)if(!viss[i]&&vvis[i])dfss(i,0),cnt++;
		int mx = 0;
		if(cnt<=2){
			for(int i = 1;i <= n;i++){
				mx += ddfs(i,0);
			}
			ans = min(ans,mx);
		}
	}
	cout << ans;
}
signed main(){
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int _ = 1;
	cin >> id;
	 cin >> _;
	while(_--)solve();
	return 0;
}

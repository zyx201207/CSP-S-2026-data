#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
vector<int> e[100010];
int t[20],vis[100010],dt[100010];
void dfs2(int u){
	vis[u]=1;
	for(auto v:e[u])
		if(t[v]&&!vis[v])
			dfs2(v);
}
void dfs3(int u){
	for(auto v:e[u])
		if(dt[v]>dt[u]+1)
			dt[v]=dt[u]+1,dfs3(v);
}
int ans;
void check(int f){
	if(f!=k)return;
	for(int i=1;i<=n;i++)vis[i]=0,dt[i]=1e18;
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(t[i]&&!vis[i])cnt++,dfs2(i);
	if(cnt>2)return;
	for(int i=1;i<=n;i++)
		if(t[i])dt[i]=0;
	for(int i=1;i<=n;i++)
		if(t[i])dfs3(i);
	int nw=0;
	for(int i=1;i<=n;i++)
		nw=max(nw,dt[i]);
	ans=min(ans,nw);
}
void dfs(int x,int cc){
	if(cc>k)return;
	if(x>n){check(cc);return;}
	t[x]=0;dfs(x+1,cc);
	t[x]=1;dfs(x+1,cc+1);
}
void solve1(){
	ans=1e18;
	dfs(1,0);
	cout<<ans<<'\n';
}
void solve2(){
	int m=n/2;
	if(k==n){cout<<0<<'\n';return;}
	if(k>=m){cout<<1<<'\n';return;}
	int l=2,r=(m+1)/2+1;
	while(l<r){
		int mid=(l+r)/2; 
		if((mid-1)*4+k<m)l=mid+1;
		else r=mid;
	}
	cout<<l<<'\n';
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)e[i].clear();
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	if(n<=10)solve1();
	else solve2();
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;cin>>c>>t;
	while(t--)solve();
	return 0;
}
//2026 rp++ 
//¾¡Á¦ÁËß÷¡­¡­ 

#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,k,ans;
vector<int> v[1000005],V;
bool vis[1000005];
int fa[1000005],dep[1000005],dp[1000005][21];
int find(int x){return (x==fa[x]?x:fa[x]=find(fa[x]));}
void unionn(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy) fa[fx]=fy;
	return;
}
void pre(int cur,int fa){
	dep[cur]=dep[fa]+1,dp[cur][0]=fa;
	for(int i=1; i<=20; i++) dp[cur][i]=dp[dp[cur][i-1]][i-1];
	for(int nxt:v[cur]) if(nxt!=fa) pre(nxt,cur);
	return;
}
int LCA(int x,int y){
	if(dep[x]>dep[y]) swap(x,y);
	for(int i=20; i>=0; i--) if(dep[x]<=dep[dp[y][i]]) y=dp[y][i];
	if(x==y) return x;
	for(int i=20; i>=0; i--) if(dp[x][i]!=dp[y][i]) x=dp[x][i],y=dp[y][i];
	return dp[x][0];
}
int dist(int x,int y){return dep[x]+dep[y]-2*dep[LCA(x,y)];}
void help(){
	if(V.size()<k) return;
	for(int x:V) fa[x]=x;
	for(int x:V) for(int nxt:v[x]) if(vis[nxt]) unionn(x,nxt);
	int cnt=0;
	for(int x:V) cnt+=find(x)==x;
	if(cnt>=3) return;
	int mx=0;
	for(int i=1; i<=n; i++) if(!vis[i]){
		int mn=(int)1e18;
		for(int x:V) mn=min(mn,dist(i,x));
		mx=max(mx,mn);
	}
	ans=min(ans,mx);
	return;
}
void dfs(int cur){
	if(cur>n||V.size()==k) return help();
	dfs(cur+1);
	V.push_back(cur),vis[cur]=true;
	dfs(cur+1);
	V.pop_back(),vis[cur]=false;
	return;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1; i<=n; i++) v[i].clear();
		for(int i=1,x,y; i<n; i++) cin>>x>>y,v[x].push_back(y),v[y].push_back(x);
		ans=(int)1e18;
		if(n==k){cout<<"0\n";continue;}
		pre(1,0);
		if(c<=3){
			dfs(1);
			cout<<ans<<'\n';
		}
		else if(c==13||c==14){
			if(k>=n/2){cout<<"1\n";continue;}
			int val=n/2+2;
			if(k==1) cout<<val/2<<'\n';
			else cout<<(val-k+5)/4<<'\n';
		}
	}
	return 0;
}
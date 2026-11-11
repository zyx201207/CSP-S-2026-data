#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define MIN(x,y) (x)=min((x),(y))
#define MAX(x,y) (x)=max((x),(y))
const int N=30;
vector < int > a[N];
int n,k;
int vis[N];
int up[20][N],d[N];
void dfs(int u,int fa){
	d[u]=d[fa]+1;
	up[0][u]=fa;
	for(int i=1;i<20;i++){
		up[i][u]=up[i-1][up[i-1][u]];
	}
	for(int i=0;i<a[u].size();i++){
		const int &v=a[u][i];
		if(v==fa) continue;
		dfs(v,u);
	}
}
int lca(int u,int v){
	if(d[u]<d[v]) swap(u,v);
	for(int i=19;i>=0;i--){
		if(d[u]-(1<<i)>=d[v]) u=up[i][u];
	}
	if(u==v) return u;
	for(int i=19;i>=0;i--){
		if(up[i][u]!=up[i][v]){
			u=up[i][u];
			v=up[i][v];
		}
	}
	return up[0][u];
}
void find(int u){
	vis[u]=0;
	for(int i=0;i<a[u].size();i++){
		const int &v=a[u][i];
		if(!vis[v]) continue;
		find(v);
	}
}
int ans=INT_MAX;
int dis(int u,int v){
	return d[u]+d[v]-2*d[lca(u,v)];
}
int count(int x){
	int res=0;
	while(x){
		x-=x&-x;
		res++;
	}
	return res;
}
void check(int mask){
	if(count(mask)!=k) return;
	memset(vis,0,sizeof(vis));
	for(int i=0;i<n;i++){
		if((mask>>i)&1){
			vis[i+1]=1;
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(vis[i]){
			if(++cnt>2) return;
			find(i);
		}
	}
	int res=0;
	for(int i=1;i<=n;i++){
		int min_=INT_MAX;
		for(int j=1;j<=n;j++){
			if(((mask>>(j-1))&1)==0)
				continue;
			MIN(min_,dis(i,j));
		}
		MAX(res,min_);
	}
	MIN(ans,res);
}
void solve(){
	for(int i=1;i<=n;i++){
		vector < int >().swap(a[i]);
	}
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	memset(d,0,sizeof(d));
	memset(up,0,sizeof(up));
	dfs(1,0);ans=INT_MAX;
	for(int mask=1;mask<(1<<n);mask++){
		check(mask);
//		cout<<ans<<endl;
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,t;cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}

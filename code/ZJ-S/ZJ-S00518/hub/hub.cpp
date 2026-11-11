#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
int n,k;
const int N=1e6+5;
vector<int>g[N];
int vis[N];
int ans=INF;
int f[N];
int find(int x){
	if(x==f[x]){
		return x;
	}
	return f[x]=find(f[x]);
}
bool check(){
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=n;i++){
		if(!vis[i]) continue;
		for(auto v:g[i]){
			if(!vis[v]) continue;
			int x=find(i);
			int y=find(v);
			f[x]=y;
		}
	}
	int res=0;
	for(int i=1;i<=n;i++){
		if(vis[i]&&find(i)==i){
			res++;
		}
	}
	return res<=2;
}
int ey[N];
int fds=0;
int hd[N];
void dp(int x,int fa,int t){
	//cout<<x<<'\n';
	if(hd[x]) return;
	hd[x]=1;
	if(vis[x]){
		ey[fds]=min(t,ey[fds]);
		return;
	}
	for(auto v:g[x]){
		if(v==fa) continue;
		dp(v,x,t+1);
	}
}
void dfs(int x,int t){
	//cout<<x<<endl;
	if(x==n+1){
		if(t!=k) return;
		if(!check()) return;
	//	cout<<1<<endl;
		for(int i=1;i<=n;i++){
			ey[i]=INF;
			fds=i;
			for(int j=1;j<=n;j++)hd[j]=0;
			dp(i,0,0);
		}
	//	cout<<1<<endl;
		int mx=0;
		for(int i=1;i<=n;i++){
			mx=max(mx,ey[i]);
		}
		ans=min(ans,mx);
		return;
	}
	if(t==k){
		dfs(x+1,t);
	}
	else if(n-x+1==k-t){
		vis[x]=1;
		dfs(x+1,t+1);
		vis[x]=0;
	}
	else{
		vis[x]=1;
		dfs(x+1,t+1);
		vis[x]=0;
		dfs(x+1,t);
	}
}
int ds[1005];
int c,t;
void ml(int x,int fa,int t){
	ds[x]=min(ds[x],t);
	for(auto v:g[x]){
		if(v==fa) continue;
		ml(v,x,t+1);
	}
}
void solve(){
	ans=INF;
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if(c<=6)dfs(1,0);
	else{
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				vis[i]=vis[j]=1;
				for(int k=1;k<=n;k++){
					ds[k]=INF;
				}
				ds[i]=ds[j]=0;
				ml(i,0,0);
				ml(j,0,0);
				int mx=0;
				for(int k=1;k<=n;k++){
					mx=max(mx,ds[k]);
				}
				ans=min(ans,mx);
			}
		}
	//	cout<<ans<<'\n';
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
/*
0 1
5 2
1 2
2 3
3 4
4 5
*/

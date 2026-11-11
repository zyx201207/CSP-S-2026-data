#include<bits/stdc++.h>
#define int long long
#define inl inline
const int N=1e6+10;
using namespace std;
int c,t;
int n,k,ans=1e18;
int dep[N],dis[20][20];
int f[N],vis[N];
vector<int> e[N];
void dfs(int rt,int u,int fa){
	dep[u]=dep[fa]+1;
	dis[rt][u]=dep[u];
	for(auto v:e[u]){
		if(v==fa)continue;
		dfs(rt,v,u);
	}
	return;
}
void getsum(int u){
	vis[u]=1;
	for(auto v:e[u]){
		if(vis[v]||!f[v])continue;
		getsum(v);
	}
	return;
}
inl bool check(){
	for(int i=1;i<=n;i++)vis[i]=0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(vis[i]||!f[i])continue;
		cnt++;
		getsum(i);
	}
	return (cnt<=2);
}
void dfs2(int now){
	if(now==n+1){
		int cc=0;
		for(int i=1;i<=n;i++){
			if(f[i])cc++;
		}
		if(cc!=k)return;
		if(check()){
			int num=0;
			for(int i=1;i<=n;i++){
				if(f[i])continue;
				int x=1e18;
				for(int j=1;j<=n;j++){
					if(!f[j])continue;
					x=min(x,dis[i][j]);
				}
				num=max(num,x);
			}
			ans=min(ans,num);
		}
		return;
	}
	dfs2(now+1);
	f[now]=1;
	dfs2(now+1);
	f[now]=0;
	return;
}
inl void init(){
	ans=1e18;
	for(int i=0;i<=n;i++){
		vis[i]=dep[i]=0;
		e[i].clear();
		for(int j=0;j<=n;j++){
			dis[i][j]=0;
		}
	}
}
inl void solve(){
	cin>>n>>k;
	init();
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dep[0]=-1;
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		for(int j=1;j<=n;j++){
			dep[j]=0;
		}
		dfs(i,i,0);
	}
	dfs2(1);
	cout<<ans<<endl;
	return;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
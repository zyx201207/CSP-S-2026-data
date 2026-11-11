#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int maxn=105;
const int inf=1e18;
int c,t,n,k,ans;
vector<int> g[maxn];
bool vis[maxn],flag[maxn];
int dis[maxn][maxn];
void walk(int u){
	flag[u]=true;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(!flag[v]&&vis[v]){
			walk(v);
		}
	}
	return;
}
int check(){
	memset(flag,0,sizeof flag);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(vis[i]&&!flag[i]){
			if(cnt==2)return inf;
			walk(i);
			cnt++;
		}
	}
	int mx=0;
	for(int i=1;i<=n;i++){
		int mn=inf;
		if(vis[i])continue;
		for(int j=1;j<=n;j++){
			if(vis[j])mn=min(mn,dis[i][j]);
		}
		mx=max(mx,mn);
	}
	return mx;
}
void dfs(int dep,int sum){
	if(dep==n+1){
		if(sum==k){
			ans=min(ans,check());
		}
		return;
	}
	if(sum<k){
		vis[dep]=true;
		dfs(dep+1,sum+1);
		vis[dep]=false;
	}
	dfs(dep+1,sum);
	return;
}
void floyd(){
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		for(int j=0;j<g[i].size();j++){
			dis[i][g[i][j]]=1;
		}
	}
	for(int t=1;t<=n;t++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][t]+dis[t][j]);
			}
		}
	}
	return;
}
void init(){
	for(int i=1;i<=n;i++){
		g[i].clear();
	}
	ans=inf;
	return;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		init();
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		floyd();
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
}
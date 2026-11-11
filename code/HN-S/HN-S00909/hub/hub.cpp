#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=4000+10;
int n,k;
vector<int>a[maxn];
int dis[maxn][maxn];
int siz[maxn];
int ff[maxn];
int dfn[maxn];
int idx;
void dfs(int u,int fa,int z){
	siz[u]=1;
	dfn[u]=++idx;
	ff[u]=fa;
	for(int i=0;i<a[u].size();i++){
		int v=a[u][i];
		if(v!=fa){
			dis[z][v]=dis[z][u]+1;
			dfs(v,u,z);
			siz[u]+=siz[v];
		}
	}
}

bool vis[maxn];
bool f[maxn];
void dfss(int u){
	f[u]=1;
	for(int i=0;i<a[u].size();i++){
		int v=a[u][i];
		if(vis[v]==1&&f[v]==0)
			dfss(v);
	}
}
int ans=1e18;
void dd(int u,int cnt){
	if(cnt>k)return;
	if(u>n){
		for(int i=1;i<=n;i++)f[i]=0;
		int cc=0;
		for(int i=1;i<=n;i++){
			if(vis[i]&&f[i]==0){
				cc++;
				dfss(i);
			}
		}
		if(cc>2)return;
		int maxx=0;
		for(int i=1;i<=n;i++){
			if(vis[i]==0){
				int minn=1e18;
				for(int j=1;j<=n;j++){
					if(vis[j]){
						minn=min(minn,dis[i][j]);
					}
				}
				maxx=max(maxx,minn);
			}
		}
		ans=min(ans,maxx);
		return;
	}
	vis[u]=1;
	dd(u+1,cnt+1);
	vis[u]=0;
	dd(u+1,cnt);
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for(int i=2;i<=n;i++){
		dfs(i,0,i);
	}
	dfs(1,0,1);
	
	dd(1,0);
	cout<<ans<<"\n";
	for(int i=1;i<=n;i++){
		a[i].clear();
		dfn[i]=0;
		ff[i]=0;
		siz[i]=0;	
	}
	ans=1e18;
	idx=0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}


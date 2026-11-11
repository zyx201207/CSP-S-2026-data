#include<bits/stdc++.h>
#define IO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
using namespace std;
const int N=4005,inf=1e18;
int c,t,n,k,r[N],ans=inf,dis[N][N];
vector<int> g[N];
bool vis[N];
inline void ch(int x){
	for(int i=0;i<(int)g[x].size();i++){
		int to=g[x][i];
		if(vis[to]) continue;
		int id=upper_bound(r+1,r+1+k,to)-r-1;
		if(r[id]!=to) continue;
		vis[to]=1;
		ch(to);
	}
}
inline bool check(){
	memset(vis,0,sizeof vis);
	int cnt=0;
	for(int i=1;i<=k;i++){
		if(!vis[r[i]]){
			cnt++;
			vis[r[i]]=1;
			ch(r[i]);
			if(cnt>2) return true;
		}
	}
	return false;
}
inline void dfs(int x,int pre){
	if(x==k+1){
		if(check()) return;
		int now=0;
		for(int i=1;i<=k;i++){
			for(int j=i+1;j<=k;j++){
				now=max(now,dis[r[i]][r[j]]);
			}
		}
		ans=min(ans,now);
		return;
	}
	for(int i=pre+1;i<=n;i++){
		r[x]=i;
		dfs(x+1,i);
	}
}
inline void solve(){
	ans=inf;
	cin>>n>>k;
	for(int i=1;i<=n;i++) g[i].clear();
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
		dis[u][v]=1,dis[v][u]=1;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	dfs(1,0);
	cout<<ans<<'\n';
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	IO;
	cin>>c>>t;
	while(t--) solve();

	return 0;
}


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
int cid;
vector<int> g[N];
bool vis[N];
void dfs(int u,int num){
	if (vis[u] || (num>>(u-1)&1)==0) return;
	vis[u]=1;
	for (int &v:g[u]){
		dfs(v,num);
	}
}
int dist[100][100];
void dfs2(int u,int fa,int rt){
	if (fa) dist[rt][u]=dist[rt][fa]+1;
	for (int &v:g[u]){
		if (v==fa) continue;
		dfs2(v,u,rt);
	}
}
void solve(){
	int n,k;cin >> n >> k;
	for (int i=1;i<=n;++i) g[i].clear();
	for (int i=1,u,v;i<n;++i){
		cin >> u >> v;
		g[u].emplace_back(v),g[v].emplace_back(u);
	}
	for (int i=1;i<=n;++i) dfs2(i,0,i);
	if (n>10){
		int res=1e9+7;
		for (int u=1;u<=n;++u){
			for (int v=u+1,ans;v<=n;++v){
				ans=0;
				for (int i=1;i<=n;++i){
					ans=max(ans,min(dist[i][u],dist[i][v]));
				}
				res=min(res,ans);
			}
		}
		cout<<res<<'\n';
		return;
	}
	int res=1e9;
	for (int i=0;i<(1<<n);++i){
		for (int j=1;j<=n;++j) vis[j]=0;
		int cnt=0,ttt=0;
		for (int j=1;j<=n;++j){
			if (vis[j]==0 && (i>>(j-1)&1)) dfs(j,i),++cnt;
			ttt+=(i>>(j-1)&1);
		}
		if (ttt!=k || cnt>2) continue;
		int ans=0;
		for (int j=1;j<=n;++j){
			if (i>>(j-1)&1) continue;
			int mn=1e9;
			for (int k=1;k<=n;++k){
				if ((i>>(k-1)&1)){
					mn=min(mn,dist[j][k]);
				}
			}
			ans=max(ans,mn);
		}
//		cout<<i<<" "<<ans<<'\n';
		res=min(res,ans);
	}
	cout<<res<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> cid;
	int T=1;
	cin >> T;
	for (int _=0;_<T;++_) solve();
	cout.flush();
	return 0;
}
//边权全为1
//这个数据范围想要干什么
//这是什么题，我会k=1!
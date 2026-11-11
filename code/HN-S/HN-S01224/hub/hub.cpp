// last battle.
// 100+68+24=192pts，所以我只需要 8 分就能上 200 了？？ 
// 不对啊，这个有点难。
// 完蛋了要求 lca，现场推倍增是吗 
// 好像 O(n^2logn) 能有 40。 
// 这个玩意，很像最小斯坦纳树啊。 
// 但是 k<=1e6，不可做。 
// dfs。 
// 不知道口胡的结论对不对。 
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define mod 998244353
#define ll long long
#define hsh __gnu_pbds::gp_hash_table 
using namespace std;
int lmt,T;
int n,k,full,ans;
vector<int> e[1000005];
int siz[1000005],dp[1000005],d[1000005];
void dfs1(int u,int fa){
	siz[u]=1;
	for(auto p:e[u]){
		if(p==fa) continue;
		dfs1(p,u);
		siz[u]+=siz[p];
	}
}
void dfs2(int u,int fa){
	dp[u]=1;
	for(auto p:e[u]){
		if(p==fa) continue;
		dfs2(p,u);
		dp[u]=max(dp[u],siz[p]);
	}
	dp[u]=max(dp[u],n-siz[u]);
}
void dfs3(int u,int fa,int dep){
	d[u]=dep;
	for(auto p:e[u]){
		if(p==fa) continue;
		dfs3(p,u,dep+1);
	}
}
bool vis[1000005],can[1000005];
void dfs4(int u,int fa){
	vis[u]=1;
	for(auto p:e[u]){
		if(p==fa||!can[p]) continue;
		dfs4(p,u);
	}
}
int dis[1005];
void dfs5(int u,int fa,int dep){
	dis[u]=dep;
	for(auto p:e[u]){
		if(p==fa) continue;
		dfs5(p,u,can[p]?0:dep+1);
	}
}
void cal(vector<int> process){
	for(auto u:process) can[u]=1;
	int cnt=0,f=1;
	for(auto u:process){
		if(!vis[u]){
			dfs4(u,0);cnt++;
			if(cnt>2){
				f=0;
				break;
			}
		}
	}
	if(f){
		dfs5(process[0],0,0);
		ans=min(ans,*max_element(dis+1,dis+1+n));
		memset(dis,0,sizeof dis);
	}
	for(auto u:process) vis[u]=can[u]=0;
}
void dfs(int u,vector<int> process){
	if(process.size()==k){
		cal(process);
		return ;
	}
	for(int i=u;i<=n;i++){
		if(n-i+1<k-process.size()) break;
		process.push_back(u);
		dfs(i+1,process);
		process.pop_back();
	}
}
inline void solve(){
	cin>>n>>k;
	ans=0x7f7f7f7f;
	if(k<=2){ // 只有两个，那就直接树的重心 
		for(int i=1;i<=n;i++){
			e[i].clear();
			siz[i]=dp[i]=d[i]=0;
		}
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		dfs1(1,0);
		dfs2(1,0);
		int minn=0x7f7f7f7f,zx=0;
		for(int i=1;i<=n;i++){
			if(dp[i]<minn){
				minn=dp[i],zx=i;
			}
		}
//		cout<<zx<<'\n';
		dfs3(zx,0,0);
		ans=*max_element(d+1,d+1+n);
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(d[i]==ans)cnt++;
		}
		if((cnt==1)||(cnt==2&&e[zx].size()<=2)) cout<<ans-1<<'\n';
		else cout<<ans<<'\n';
		return ;
	}
	for(int i=1;i<=n;i++){
		e[i].clear();
		vis[i]=0;
	}
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	} // 不演了，全排列启动111 
	dfs(1,vector<int>());
	if(n==k) ans=0;
	cout<<ans<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>lmt>>T;
	while(T--){
		solve();
	}
}
// Reincarnated Soul


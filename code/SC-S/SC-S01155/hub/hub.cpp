//CSP-S 2026 D by wyyinput
//Task name: hub
//Date: 2026/10/31
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define fi first
#define se second
using namespace std;
const int N=35;
int C,T;
int n,k;
bool h[N];//是否为研发基地
vector<int> e[N];
bool vis[N];
int maxn_turn;
int ans;
void dfs1(int);
void dfs2(int);
void dfs3(int,int);
bool check();
bool check(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		cnt+=h[i];
	}
	//必须恰好k座城市
	if(cnt!=k){
		return 0;
	}
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
	//统计连通块数量
	int tot=0;
	for(int i=1;i<=n;i++){
		if(h[i]&&!vis[i]){
			++tot;
			dfs2(i);
		}
	}
	if(tot>2){
		return 0;
	}
	return 1;
}
void dfs1(int now){
	if(now==n+1){
		if(!check()){
			return;
		}
		int maxn=0;
		for(int i=1;i<=n;i++){
			if(!h[i]){
				for(int j=1;j<=n;j++){
					vis[j]=0;
				}
				maxn_turn=n+5;
				dfs3(i,0);
				maxn=max(maxn,maxn_turn);
			}
		}
		ans=min(ans,maxn);
		return;
	}
	h[now]=0;
	dfs1(now+1);
	h[now]=1;
	dfs1(now+1);
	return;
}
void dfs2(int x){
	vis[x]=1;
	for(int y:e[x]){
		if(h[y]&&!vis[y]){
			dfs2(y);
		}
	}
	return;
}
void dfs3(int x,int dis){
	vis[x]=1;
	if(h[x]){
		maxn_turn=min(maxn_turn,dis);
		return;
	}
	for(int y:e[x]){
		if(!vis[y]){
			dfs3(y,dis+1);
		}
	}
	return;
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		e[i].clear();
	}
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	ans=n+5;
	dfs1(1);
	cout<<ans<<"\n";
	return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>C>>T;
	if(/*C==0||*/1<=C&&C<=3){
		while(T--){
			solve();
		}
	}
	return 0;
}
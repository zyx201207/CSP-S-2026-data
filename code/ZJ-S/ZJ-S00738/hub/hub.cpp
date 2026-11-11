#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf = 1e16;
int n,k,c,t;
vector<int>tr[1000005];
vector<int>dist;
bool is_dst[1000005];
bool vis[1000005];
int dp[1000005];
int popcnt(int x){
	int res = 0;
	while(x){
		res++;
		x&=x-1;
	}
	return res;
}
void dfs(int u,int fa){
	vis[u] = 1;
	for(auto it:tr[u]){
		if(it==fa)continue;
		if(!is_dst[it])continue;
		dfs(it,u);
	}
}
void f(int u,int fa){
	if(is_dst[u]){
		dp[u] = 0;
		return ;
	}
	for(auto it:tr[u]){
		if(it==fa)continue;
		f(it,u);
		dp[u] = min(dp[u],dp[it]+1);
	}
}
signed main(){
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i =1;i<=n;i++)tr[i].clear();
		for(int i = 2;i<=n;i++){
			int u,v;
			cin>>u>>v;
			tr[u].push_back(v);
			tr[v].push_back(u);
		}
		int N = (1<<n)-1;
		int ans = inf;
		for(int m = 0;m<=N;m++){
			if(popcnt(m)!=k)continue;
			dist.clear();
			for(int i = 1;i<=n;i++){
				is_dst[i] = 0;
				vis[i] = 0;
			}
			for(int i = 1;i<=n;i++){
				if((m>>(i-1))&1){
					dist.push_back(i);
					is_dst[i] = 1;
				}
			}
			int ltk = 0;
			for(auto di:dist){
				if(!vis[di]){
					dfs(di,-1);
					ltk++;
				}
			}
			if(ltk>2)continue;
			int res = 0;
			for(int i = 1;i<=n;i++){
				if(is_dst[i])continue;
				for(int j = 1;j<=n;j++){
					dp[j] = inf;
				}
				f(i,-1);
				res = max(res,dp[i]);
			}
			ans = min(ans,res);
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/

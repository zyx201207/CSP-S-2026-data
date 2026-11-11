#include<bits/stdc++.h>
using namespace std;
//#define int long long
//#define LOCAL
const int N = 5e5 + 5;
const int mod = 998244353;

int n,d;
int a[N];
int tot,head[N];
struct edge{
	int v,nxt;
}e[N];

int bfs(int st,int ed){
	vector<int> dp(n + 1,0);
	queue<int> q;
	q.push(st);
	bitset<N> vis;
	vis[st] = 1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = head[u];i;i = e[i].nxt){
			int v = e[i].v;
			if(vis[v]) continue;
			vis[v] = 1;
			dp[v] = dp[u] + 1;
		}
	}
	return dp[ed];
}

void dfs(){
	//靠，不会写暴力，睡觉了，回家玩phigros去了 
	//我好菜 
}

void sol(){
	//memset()
	cin >> n >> d;
	for(int i = 1;i <=n;i++){
		cin >> a[i];
	}
	int dp[5005][5005];
	dp[1][0] = dp[1][1] = 1;
    for(int i = 1;i <= n;i++){
    	for(int j = 1;j <= i - 1;j++){
    		for(int k = 1;k <= j - 1;k++){
    			if(abs(a[i] - a[j]) <= d && abs(a[j] - a[k]) <= d){
	    			dp[i][j] += dp[j][k];
				}
			}
		}
	}
	int ans = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j < i;j++){
			if(dp[i][j] == 2) ans++;
		}
	}
	cout << ans << "\n";
}

signed main(){
	#ifndef LOCAL
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c;
	cin >> c;
	int T = 1;
	cin >> T;
	while(T--){
		sol();
	}
	return 0;
}


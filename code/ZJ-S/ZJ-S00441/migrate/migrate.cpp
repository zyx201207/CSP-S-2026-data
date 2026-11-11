#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e6 + 5;
ll read(){
	ll x = 0, f = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f; 
}
int c, t;
int n, d;
ll ans;
ll x[N];
int dp[N], pre[N], nxt[N], mn[N], st[N];
queue<int>q;
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	c = read(), t = read();
	while(t--){
		n = read(), d = read();
		ans = 0;
		for(int i = 1; i <= n; i++) x[i] = read();
		while(!q.empty()) q.pop();
		for(int i = 1; i <= n; i++){
			while(!q.empty() && x[i] - x[q.front()] > d) q.pop();
			if(q.empty()) nxt[i] = i;
			else nxt[i] = q.front();
			q.push(i);
		}
		for(int i = 1; i <= n; i++){
			memset(dp, 0, sizeof(dp));
			dp[i] = 1;
			for(int j = i + 1; j <= n; j++){
				int Mn = n;
				dp[j] = 0;
				for(int k = max(nxt[j], i); k < j; k++) Mn = min(Mn, st[k]);
				for(int k = max(nxt[j], i); k < j; k++){
					if(st[k] == Mn) dp[j] += dp[k];
				}
				st[j] = Mn + 1;
			}
			for(int j = i + 1; j <= n; j++) ans += (dp[j] == 2);
		}
		cout << ans << '\n';
	}
	return 0;
}

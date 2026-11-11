#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int maxn = 5e3 + 10;
inline int read(){
	int res = 0,f = 1; char ch = getchar();
	while (!isdigit(ch)){if (ch == '-') f = -1; ch = getchar();}
	while (isdigit(ch)){res = res * 10 + (ch - '0'); ch = getchar();}
	return res * f;
}
int n,t,sum = 0;
int a[maxn];
int dp[maxn][maxn];

void dfs(int s,int e){
	if (s == e){
		sum++; return;
	}
	if (s > e) return;
	if (a[e] - a[s] <= t){
		dfs(e,e); return;
	}
	for (int i = s + 1;i <= e && a[i] - a[s] <= t;i++) dfs(i,e);
	return;
}

void solve(){
	memset(dp,0,sizeof(dp));
	n = read(); t = read();
	for (int i = 1;i <= n;i++) a[i] = read();
	int ans = 0;
	for (int i = 1;i <= n;i++){
		for (int j = i + 1;j <= n;j++){
			if (a[j] - a[i] <= t){
				dp[i][j] = 1; continue;
			}
			for (int k = i + 1;k <= j - 1;k++) dp[i][j] += dp[i][k] * dp[k][j];
		}
	}
	for (int i = 1;i <= n;i++){
		for (int j = i + 1;j <= n;j++){
			if (a[j] - a[i] <= t) continue;
			for (int k = i + 1;k <= j - 1;k++) dp[i][j] += dp[i][k] * dp[k][j];
		}
	}
	for (int i = 1;i <= n;i++){
		for (int j = i + 1;j <= n;j++) ans += (dp[i][j] == 2);
	}
	cout << ans << endl;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c = read(),T = read();
	while (T--) solve();
	return 0;
}
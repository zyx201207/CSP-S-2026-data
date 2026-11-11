#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> PII;
const int maxn = 2e5 + 10;
int n, m, a[maxn], ans = -0x3f3f3f3f;
void dfs(int now, int cel, int sum) {
	if(now > n) {
		if(cel == m) {
			ans = max(ans, sum);
		}
		return ;
	}
	dfs(now + 1, cel + 1, sum & a[now]);
	dfs(now + 1, cel, a[now]);
}
int dp[1010][1010];
int dfs2(int now, int cel, int sum) {
	if(dp[now][cel] != -1) {
		return dp[now][cel];
	}
	if(now > n) {
		if(cel == m) {
			return sum;
		}
		return -1;
	}
	int mx = -0x3f3f3f3f;
	mx = max(mx, dfs2(now + 1, cel + 1, sum & a[now]));
	mx = max(mx, dfs2(now + 1, cel, a[now]));
	return mx;
}

int f[2][maxn];
int dfs3(int now, int cel, int sum) {
	if(f[now % 2][cel] != -1) {
		return f[now % 2][cel];
	}
	if(now > n) {
		if(cel == m) {
			return sum;
		}
		return -1;
	}
	int mx = -0x3f3f3f3f;
	mx = max(mx, dfs3(now + 1, cel + 1, sum & a[now]));
	mx = max(mx, dfs3(now + 1, cel, a[now]));
	return mx;
}

int main() {
	
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
//	cout << (3 & 3);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	
	if(n <= 20) {
		dfs(1, 0, a[1]);
		cout << ans;
	}
	else if(n <= 2000) {
		memset(dp, -1, sizeof dp);
		cout << dfs2(1, 0, a[1]);
	}
	else {
		memset(f, -1, sizeof f);
		cout << dfs3(1, 0, a[1]);
	}
	
	return 0;
} 

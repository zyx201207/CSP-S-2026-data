#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 1e4+10;
int n, d, a[N];
int dp[N], dis[N], ans;

void calc(int l, int r) {
	memset(dp,0,sizeof dp);
	memset(dis,0,sizeof dis);
	
	dis[l] = 0;
	for (int i = l+1, now = l; i <= r; i++) {
		if (a[i] - a[i-1] > d) break;
		while (a[i] - a[now] > d) now ++;
		dis[i] = dis[now] + 1;
	}
	
	int sum = 0; dp[l] = 1;
	queue<int> q;
	for (int i = l+1, j = l; i <= r; i++) {
		while (j < i && dis[j] == dis[i]-1) {
			q.push(j);
			sum += dp[j];
			j++;
		}
		while (!q.empty() && (a[i] - a[q.front()] > d || dis[q.front()] != dis[i]-1)) {
			sum -= dp[q.front()];
			q.pop();
		}
		dp[i] = sum;
	}
	
	for (int i = l; i <= r; i++) {
		ans += (dp[i] == 2);
	}
}
void solve() {
	ans = 0;
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		calc(i,n);
	}
	cout << (int)ans << "\n";
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c, T;
	cin >> c >> T;
	while (T--) {
		solve();
	}
	return 0;
}

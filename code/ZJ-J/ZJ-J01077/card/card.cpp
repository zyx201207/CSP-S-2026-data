#include <bits/stdc++.h>
using namespace std;
//baoli 56pts
const int N = 5005;
const int M = 3005;
int a[N];
int c[100005], lst[M];
bool dp[N][M];
bool dp1[200005][3];
int ans[100005];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	bool ok = true;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] < a[i - 1]) ok = false;
	}
	if(m <= 2) {
		for(int i = n; i >= 1; i--) {
		if(!c[a[i]]) {
			for(int j = 1; j <= m; j++) {
				dp1[i][j] = dp1[i + 1][j];
			}
			dp1[i][a[i]] = 1;
			lst[a[i]] = i;
		} else {
			for(int j = 1; j <= m; j++) {
				dp1[i][j] = dp1[lst[a[i]]][j];
			}
		}
		c[a[i]]++;
		for(int j = 1; j <= m; j++) {
			ans[j] += dp1[i][j];
			//cout << dp[i][j] << " ";
		}
		//cout << endl;
	}
	for(int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
		return 0;
	}
	//ok = false;
	if(ok) {
		//cout << 31525 << endl;
		for(int i = n; i >= 1; i--) {
			if(!c[a[i]]) {
				ans[a[i]] = i;
				c[a[i]]++;
			} 
		}
		for(int i = 1; i <= m; i++) {
			cout << ans[i] << " ";
		}
		return 0;
	}
	for(int i = n; i >= 1; i--) {
		if(!c[a[i]]) {
			for(int j = 1; j <= m; j++) {
				dp[i][j] = dp[i + 1][j];
			}
			dp[i][a[i]] = 1;
			lst[a[i]] = i;
		} else {
			for(int j = 1; j <= m; j++) {
				dp[i][j] = dp[lst[a[i]]][j];
			}
		}
		c[a[i]]++;
		for(int j = 1; j <= m; j++) {
			ans[j] += dp[i][j];
			//cout << dp[i][j] << " ";
		}
		//cout << endl;
	}
	for(int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}


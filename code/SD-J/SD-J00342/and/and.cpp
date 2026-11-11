#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline int read() {
	int k = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		k = k * 10 + (c - '0');
		c = getchar();
	}
	return k * f;
}

const int T = 2e3 + 5;
const int N = 2e5 + 5;

int n, m;
int a[N];
ll dp[T][T];


int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	n = read(), m = read();
	
	int maxn = 0;
	bool flag = 0;
	for (int i = 1; i <= n; ++ i) {
		a[i] = read();
		maxn = max(maxn, a[i]);
		if (a[i] != i - 1) flag = 1;
	}
	
	if (n <= 2e3) {
		for (int i = 1; i <= n; ++ i) {
			dp[i][1] = a[i];
			for (int j = 2; j <= m; ++ j) {
				for (int l = 1; l < i; ++ l) {
					dp[i][j] = max(dp[i][j], dp[l][j - 1] & a[i]);
				}
			}
		}
		
		ll ans = 0;
		for (int i = 1; i <= n; ++ i) {
			ans = max(ans, dp[i][m]);
		}
		
		printf("%lld", ans);
		
		return 0;
	}
	
	
	if (maxn < 4) {
		int cnt1 = 0, cnt2 = 0, cnt3 = 0;
		for (int i = 1; i <= n; ++ i) {
			if (a[i] == 1) cnt1 ++;
			if (a[i] == 2) cnt2 ++;
			if (a[i] == 3) cnt3 ++; 
		}
		
		int ans = 0;
		if (cnt3 >= m) ans = 3;
		else {
			if (cnt3 + cnt2 >= m) ans = 2;
			else {
				if (cnt3 + cnt1 >= m) ans = 1;
			}
		}
		
		printf("%d", ans);
		
		return 0; 
	}
	
	if (flag == 0) {
		int tmp = 1, k = 0;
		for (k = 0; k <= 20; ++ k) {											
			if (tmp * 2 == n) break;
		}
		ll ans = 0;
		if (m >= tmp) ans = 0;
		else {
			ans = tmp;
			else {
				if (m == 1) ans = n - 1;
			}
		}
		printf("%lld", ans);
		return 0;
	}
	
	puts("Rp++");
	
	return 0;
}

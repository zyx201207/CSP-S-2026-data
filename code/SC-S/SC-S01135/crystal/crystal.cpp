#include <bits/stdc++.h>

using namespace std;
long long n, m, a[1000010], dp[1000010], b[1000010], c[1000010], ans, cnt;
//b[i]:前i个水晶中，最多水晶的操作次数
//c[i]
int main () {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort (a + 1, a + n + 1);
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i] == a[i - 1]) {
			dp[i] = dp[i - 1] + 1;
			b[i] = b[i - 1];
		}
		else if (a[i] != a[i - 1]) {
			if (b[i - 1] + dp[i - 1] * (a[i] - a[i - 1]) <= m) {
				b[i] = b[i - 1] + dp[i - 1] * (a[i] - a[i - 1]);
				dp[i] = dp[i - 1] + 1;
			}
			else if (a[i] - a[i - 1] <= m) {
				cnt++;
				if (a[i] - a[i - 1] > a[i + 1] - a[i]) {
					if (a[i] - a[i - 1] <= a[i + 2] - a[i + 1]) {
						dp[i] = 2;
						b[i] = a[i] - a[i - 1];
					}
					else {
						dp[i] = 1;
						b[i] = 0;
					}
				}
				else {
					dp[i] = 2;
					b[i] = a[i] - a[i - 1];
				}
			}
			else {
				
				dp[i] = 1;
				b[i] = 0;
			}
		}
		//if (b[i] == 0) cout << i << " " << a[i - 1] << " " << a[i] << "\n";
	}
	//for (int i = 1; i <= n; i++) cout << b[i] << " ";
	//cout << "\n";
	for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);
	cout << ans;
	//cout << "\n" << cnt;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

7 7
1 2 3 7 8 9 10

5 6
1 2 6 7 13
*/
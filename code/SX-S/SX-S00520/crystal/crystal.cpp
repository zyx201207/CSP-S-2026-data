#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
long long n, m, a[MAXN], len = 0, dp[MAXN], sum = 1, na;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);

	dp[1] = 0; //dp存的是该位置链条最长情况下的花费
	len = 1;
	for (int i = 2; i <= n; i++) {
		if (dp[i - 1] + len * (a[i] - a[i - 1]) <= m) {
			//cout << "方法1 " << endl;
			dp[i] = dp[i - 1] + len * (a[i] - a[i - 1]);
			len++;
		} else { //这个情况下，无法继续追加，选择遗弃远端点满足近点
			//cout << "方法2 " << endl;
			dp[i] = dp[i - 1] + len * (a[i] - a[i - 1]);
			len++;
			while (dp[i] > m) {
				//cout << dp[i] << " " << len << " dp-=" << a[i - len + 1] << endl;
				dp[i] -= (a[i] - a[i - len + 1]);
				//cout << "k-=1" << a[i] - a[i - len] << endl;
				len--;
				//cout << "遗弃！" << endl;
			}

		}
		//cout << dp[i] << " " << len << endl;
		sum = max(len, sum);
	}
	cout << sum;


	return 0;
}

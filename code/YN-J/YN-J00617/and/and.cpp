#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

string er(int x) {
	int l = 20;
	string s = "";
	while (l >= 0) {
		if (x >= pow(2, l)) {
			x -= pow(2, l);
			s.push_back('1');
		} else {
			s.push_back('0');
		}
		l--;
	}
	return s;
}

int an (int a, int b) {
	int cnt = 0;
	string a1 = er(a), b1 = er(b);
	for (int i = 0; i <= 20; i++) {
		if (a1[i] == '1' && b1[i] == '1') {
			cnt += pow(2, 20 - i);
		}
	}
	return cnt;
}
int n, m, dp[1000000], num[1000000];

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1) {
				dp[j] = num[i];
			} else {
				dp[j] = dp[j];
				for (int k = 1; k < j; k++) {
					dp[j] = max(dp[j], an(dp[k], num[i]));
				}
			}
		}
	}
	cout << dp[n];
	return 0;
}
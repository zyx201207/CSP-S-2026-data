#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 2;
int n;
string c = " ";
vector<vector<int> > dp;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int a;
		char ch;
		scanf("%d %c", &a, &ch);
		for (int j = 1; j <= a; ++j) c.push_back(ch);
	}
	
	n = c.size() - 1;
	dp.resize(n + 1, vector<int>(n + 1, 0));
	
	for (int i = 1; i < n; ++i) {
		if (c[i] == c[i + 1]) dp[i][i + 1] = 0;
		else dp[i][i + 1] = 1;
	}
	
	for (int len = 3; len <= n; ++len) {
		for (int l = 1; l + len - 1 <= n; ++l) {
			int r = l + len - 1;
			if (c[l] == c[r]) dp[l][r] = dp[l + 1][r - 1];
			else dp[l][r] = dp[l + 1][r - 1] + 1;
		}
	}
	
	printf("%d", dp[1][n]);
	
	return 0;
}

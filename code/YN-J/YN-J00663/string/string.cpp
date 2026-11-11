#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
string s;
char a;
long long  ans, sum;
int n;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int k;
		cin >> k >> a;
		for (int j = 1; j <= k; ++j) {
			s += a;
			sum++;
		}
	}
	for (int i = 0; i < sum; ++i) {
		if (sum % 2 == 0) {
			if (i == sum / 2) {
				break;
			}
		}
		if (sum % 2 == 1) {
			if (i == sum / 2 + 1) {
				break;
			}
		}
		if (s[i] != s[sum - 1 - i]) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	freopen("string.in", "r", "stdin");
	freopen("string.out", "w", "stdout");
	int sum = 0, cnt = 0;
	int n, a;
	char b;
	string s;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		for (int j = 1; j <= a; j++) {
			s += b;
		}
		sum += a;
	}
	for (int j = 0; j <= sum / 2 - 1; j++) {
		if (s[j] != s[sum - j - 1])
			cnt++;
	}
	cout << cnt;
	return 0;
}
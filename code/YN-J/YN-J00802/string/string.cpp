#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, a, sum = 0;
	cin >> n;
	string s;
	char c;
	for (int i = 1; i <= n; i++) {
		cin >> a >> c;
		for (int j = 1; j <= a; j++) {
			s += c;
		}
	}
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != s[s.size() - 1 - i]) {
			sum++;
			s[s.size() - 1 - i] = s[i];
		}
	}
	cout << sum;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	int shu;
	char ru;
	string s;
	for (int i = 1; i <= n; i++) {
		cin >> shu >> ru;
		for (int j = 1; j <= shu; j++) {
			s += ru;
		}
	}
	int sum = 0;
	for (int i = 0; i <= s.size() / 2 - 1; i++) {
		if (s[i] != s[s.size() - i - 1]) {
			sum++;
		}
	}
	cout << sum;
	return 0;
}

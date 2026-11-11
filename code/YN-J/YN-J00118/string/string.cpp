#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	string s = "";
	int n;
	cin >> n;
	int a;
	char c;
	while (n--) {
		cin >> a >> c;
		while (a--) {
			s += c;
		}
	}
	int l = s.size() - 1;
	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != s[l - i]) {
			ans++;
		}
	}
	cout << (int)ceil(ans / 2.0);
	return 0;
}
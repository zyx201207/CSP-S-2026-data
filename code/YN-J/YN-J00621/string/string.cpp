#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	string s = {0};
	int n, sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		char c;
		cin >> a >> c;
		while (a--) {
			s += c;
		}
	}
	for (int i = 0; i <= s.size(); i++) {
		cout << s[i];
	}
	cout << endl;
	int l = 1, r = s.size() - 1;
	for (int i = 1; i <= s.size(); i++) {
		if (l >= r) {
			break;
		}
		if (s[l] != s[r]) {
			cout << s[l] << " " << s[r] << endl;
			s[r] = s[l];
			sum++;
			cout << s[l] << " " << s[r] << endl;
		}
		r--, l++;
	}
	cout << sum << endl;
	return 0;
}

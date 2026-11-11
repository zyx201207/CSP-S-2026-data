#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int t, i = 1;
	string s;
	cin >> t;
	while (t--) {
		int n;
		char c;
		cin >> n >> c;
		while (n--) {
			s[i] = c;
			i++;
		}
	}
	i -= 1;

	int ans = 0;
	for (int j = 1; j <= i / 2; j++) {
		if (s[j] != s[i + 1 - j]) {
			ans++;
		}
	}
	cout << ans << endl;
	for (int j = 1; j <= i; j++) {
		cout << s[j];
	}
	cout << endl;
	return 0;
}
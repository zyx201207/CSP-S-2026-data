#include <bits/stdc++.h>
using namespace std;

int main() {

	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	long long n, cnt = 0;
	string s, c;
	cin >> n;
	while (n--) {
		int x;
		string a;
		cin >> x >> a;
		while (x--) {
			s += a;
		}
	}
	bool f = 0;
	long long len = s.length();
	for (int i = len - 1; i >= 0; i--) {
		c += s[i];
	}
	if (s == c) {
		cout << "0";
		return 0;
	}
	for (int i = 0; i < len / 2; i++) {
		if (s[i] != s[len - i])
			cnt++;
	}
	cout << cnt;
	return 0;
}
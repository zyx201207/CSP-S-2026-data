#include <bits/stdc++.h>
using namespace std;
int n, a, cnt = 0;
char ch;
string s, c;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a >> ch;
		for (int j = 1; j <= a; j++) {
			s += ch;
		}
	}
	int len = s.size() - 1;
	int l = s.size() / 2;
	for (int i = len; i >= 0; i--) {
		c += s[i];
	}
	for (int i = 0; i <= l; i++) {
		if (c[i] != s[i]) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int a[10000005];
int n, cnt = 0;
string s;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	for (int i = 0; i <= n; i++) {
		cin >> a[i];
		char b;
		cin >> b;
		s = a[i] * b;
	}
	int c = s.size();
	for (int i = 0; i <= s.length() - 1; i++) {
		if (s[i] != s[c]) {
			cnt++;
			c = c - 1;
			if (s[i] == s[c]) {
				break;
			}
		}
	}
	cout << cnt;
	return 0;
}

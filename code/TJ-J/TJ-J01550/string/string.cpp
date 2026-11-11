#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, a, c;
	cin >> n;
	string s;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		cin >> c;
		for (int j = 1; j <= a; j++) {
			s += c;
		}
	}
	int j = 0;
	for (int i = 1; i <= s.length() / 2; i++) {
		if (s[i - 1] != s[s.length() - i]) {
			s[s.length() - i] = s[i - 1];
			j++;
		}
	}
	cout << j;
}
#include <bits/stdc++.h>
using namespace std;
string s, t1, t2;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		char c;
		cin >> x >> c;
		for (int i = 1; i <= x; i++) {
			s += c;
		}
	}
	if (s.size() % 2 != 0) {
		for (int i = 0; i < (s.size() - 1) / 2; i++) {
			t1 += s[i];
		}
	} else {
		for (int i = 0; i < s.size() / 2; i++) {
			t1 += s[i];
		}
	}
	cout << 0;
	return 0;
}
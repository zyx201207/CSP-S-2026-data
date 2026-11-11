#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	int c = 0;
	for (int i = 1; i < n; i++) {
		string s;
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == s[i]) {
				c++;
			} else {
				c = 0;
			}
		}
	}
	if (c != 0) {
		cout << 0;
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, a, b = 1, t = 0;
	char c;
	string s = {0};
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a >> c;
		for (int x = b; x < b + a; x++) {
			s[x] = c;
		}
		b += a;
	}
	char l = 1, r = b - 1;
	if ((b - 1) % 2 == 0) {
		for (int i = 1; i <= (b - 1) % 2; i++) {
			if (s[l] != s[r]) {
				t++;
			}
		}
	} else {
		for (int i = 1; i <= (b - 1) % 2 + 1; i++) {
			if (s[l] != s[r]) {
				t++;
			}
		}
	}
	cout << t;
	return 0;
}
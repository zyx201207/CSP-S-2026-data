#include <bits/stdc++.h>
using namespace std;
int n, a[200005], h = 0, u = 0;
char s[200005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> s[i];
	}
	if (n == 1) {
		cout << '0';
	} else if (n == 2) {
		if (s[1] == s[2]) {
			cout << '0';
		} else {
			cout << min(a[1], a[2])\2;
		}
	} else if (n > 2) {
		for (int i = 1; i <= n; i++) {
			if (s[i] == s[i + 1]) {
				h = 1;
			} else {
				h = 0;
				break;
			}
		}
		if (h == 1) {
			cout << "0";
		} else {
			for (int i = 2; i <= n; i++) {
				u = max(a[i], u);
			}
			cout << u / 2;
		}
	}
	return 0;
}
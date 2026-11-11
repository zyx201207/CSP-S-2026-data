#include <bits/stdc++.h>
using namespace std;

int a[200010], c[200010];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, cnt = 0, xg = 0;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> c[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < a[i]; j++) {
			s[cnt] = c[i];
			cnt++;
		}
	}
	if (cnt % 2 == 0) {
		for (int i = 0; i <= cnt / 2; i++) {
			if (s[i] != s[cnt - i]) {
				xg++;
			}
		}
	} else {
		for (int i = 0; i <= cnt / 2; i++) {
			if (s[i] != s[cnt - i]) {
				xg++;
			}
		}
	}
	cout << xg;
	return 0;
}
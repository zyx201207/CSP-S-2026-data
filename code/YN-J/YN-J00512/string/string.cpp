#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	string s;
	int res = 0;
	cin >> n;
	int a[n];
	char c[n];
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> c[i];
		cnt += a[i];
		for (int j = 0; j < a[i]; j++) {
			s += c[i];
		}
	}
	int f = 0;
	for (int i = 0; i < cnt; i++) {
		if (s[i] != s[cnt - 1 - i])
			f = 1;
	}
	if (f == 0) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < cnt - 1; i++) {
		if (s[i] != s[i + 1]) {
			f = 1;
			break;
		}
	}
	if (f == 0) {
		cout << 0;
		return 0;
	} else {
		for (int i = 0; i < cnt / 2; i++) {
			if (s[i] != s[cnt - i - 1]) {
				res++;
			}
		}
	}
	cout << res;
	return 0;
}

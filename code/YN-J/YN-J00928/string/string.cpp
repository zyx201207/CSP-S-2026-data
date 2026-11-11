#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, c[N], suml = 0, cnt = 0;
char s[N];
string ss;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x >> s[i];
		c[i] = x;
		suml += x;
	}
	for (int i = 0; i < n; i++) {
		while (c[i]--) {
			ss += s[i];
		}
	}
	for (int i = 0; i < suml / 2; i++) {
		if (ss[i] != ss[suml  - i - 1])
			cnt++;
	}
	cout << cnt;
	return 0;
}


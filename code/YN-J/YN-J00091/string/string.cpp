#include <bits/stdc++.h>
#define N 200002
using namespace std;
int n, a[N], len, ans, len2;
char c[N];
string s = "", sd = "";

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;

	for (int i = 1; i <= n; i++) {

		cin >> a[i] >> c[i];

		for (int j = 1; j <= a[i]; j++) {

			s += c[i];
		}
	}

	len = s.size();

	if (len % 2 == 0) {
		len2 = len / 2;

		for (int i = 0; i <= len2 - 1; i++) {

			if (s[i] != s[i + len2])
				ans++;
		}
	} else {
		len2 = len / 2 + 1;

		for (int i = 0; i < len2 - 1; i++) {

			if (s[i] != s[i + len2])
				ans++;
		}
	}

	cout << ans << "\n";
	return 0;
}
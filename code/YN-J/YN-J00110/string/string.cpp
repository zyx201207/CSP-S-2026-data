#include <bits/stdc++.h>
using namespace std;
long long n, a, tot, ans;
char c, s[1000000000];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;

	for (int i = 1; i <= n; i++) {

		cin >> a >> c;

		while (a--)
			s[tot] = c, tot++;
	}

	for (int i = 0; i <= tot / 2; i++)

		if (s[i] != s[tot - i - 1])
			ans++;
	cout << ans;
	return 0;
}

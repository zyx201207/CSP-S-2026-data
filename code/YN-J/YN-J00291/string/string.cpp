#include <bits/stdc++.h>
using namespace std;
long long a, l = 0, ans = 0;
int n;
string s;
char c;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;

	for (int i = 1; i <= n; i++) {

		cin >> a >> c;
		l += a;

		for (long long j = 1; j <= a; j++)

			s += c;

	}

	int x = 0, y = l - 1;

	if (l % 2 == 0) {
		while (x < y) {
			if (s[x] != s[y])
				ans++;
			x++;
			y--;
		}
	} else {
		while (x != y) {
			if (s[x] != s[y])
				ans++;
			x++;
			y--;
		}
	}

	cout << ans;
	return 0;
}

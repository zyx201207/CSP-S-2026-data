#include <bits/stdc++.h>
using namespace std;
int n, num, cnt, a = 0, b, now, ans;
string s, s1;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;

	for (int i = 1; i <= n; i++) {

		cin >> cnt >> s1;

		for (int j = 1; j <= cnt; j++) {

			s += s1;
		}

		num += cnt;
	}

	b = num - 1;
	now = num / 2;

	if (num % 2 == 0) {
		while (a != now && b != now + 1) {
			if (s[a] != s[b]) {
				ans++;
			}

			a += 1;
			b -= 1;
		}
	} else {
		while (a != b) {

			if (s[a] != s[b]) {
				ans++;
			}

			a += 1;
			b -= 1;
		}
	}

	cout << ans;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long ai[200005];
char ci[200005];
string s, sf;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, l;
	int ans = 0;
	cin >> n;

	for (int i = 1; i <= n; i++) {

		cin >> ai[i] >> ci[i];

		for (int j = 1; j <= ai[i]; j++) {

			s += ci[i];
		}
	}

	l = s.length();

	for (int i = l - 1; i >= 0; i--) {

		sf += s[i];

	}

	for (int i = 0; i < l; i++) {

		if (s[i] != sf[i]) {
			ans++;
		}
	}

	cout << ans / 2;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	long long a, ans = 0;
	string s, t;
	cin >> n;

	for (int i = 1; i <= n; i++) {

		cin >> a >> s;

		for (int k = 0; k < a; k++) {

			t = t + s;
		}

		s = "";
	}

	int c = t.size();

	for (int i = 0; i < c / 2; i++) {

		if (t[i] != t[c - i - 1]) {
			ans++;
		}
	}

	cout << ans;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long L, n;
	cin >> n;
	string s, a;

	for (int i = 0; i < n; i += 2) {

		cin >> a[i];
	}

	for (int i = 0; i < n; i += 2) {

		for (int j = 0; j < a[i]; j++) {

			s += a[j + 1];
		}
	}

	L = s.size();


	long long cnt = 0;

	for (int i = 0; i < L / 2; i++) {

		if (s[i] != s[L - 1 - i]) {
			cnt++;
		}
	}

	cout << cnt;

	return 0;
}

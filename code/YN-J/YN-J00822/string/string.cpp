#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	string s = "";
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {

		int x;
		char c;
		cin >> x >> c;

		for (int j = 0; j < x; j++)

			s += c;
	}

	long long l = 0, r = s.size() - 1, cnt = 0;

	while (l < r) {
		if (s[l] != s[r]) {
			cnt += 1;
		}

		l++;
		r--;
	}

	cout << cnt;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n;
string s;

void j(int m, char c) {
	for (int i = 1; i <= m; i++) {

		s += c;
	}
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;

	for (int i = 1; i <= n; i++) {

		int m;
		char c;
		cin >> m >> c;
		j(m, c);
	}

	int l = s.size() / 2, ll = s.size();
	int cnt = 0;

	for (int i = 1; i <= l; i++) {

		if (s[i - 1] != s[ll - i]) {
			cnt++;
		}
	}

	cout << cnt;
	return 0;
}
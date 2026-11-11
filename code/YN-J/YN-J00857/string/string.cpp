#include <bits/stdc++.h>
using namespace std;

int n, cnt = 0;
string s;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int num;
		char c;
		cin >> num >> c;
		for (int j = 1; j <= num; j++) {
			s += c;
		}
	}
	int m = s.size();
	if (m % 2 == 1) {
		for (int i = 0; i < m / 2; i++) {
			if (s[i] != s[m - i - 1]) {
				cnt++;
			}
		}
	} else {
		for (int i = 0; i <= m / 2; i++) {
			if (s[i] != s[m - i - 1]) {
				cnt++;
			}
		}
	}

	cout << cnt;
	return 0;
}
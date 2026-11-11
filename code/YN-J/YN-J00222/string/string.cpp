#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("string.in", "r", stdin);
//	freopen("string.out", "w", stdout);
	string s;
	int n, a, num = 0;
	char b;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		s.append(a, b);
	}
	long long len = s.size();
	string z = s;
	reverse(s.begin(), s.end());
	if (z != s) {
		for (int i = 1; i <= len; i++) {
			if (s[i] != s[len + 1 - i]) {
				s[i] = s[len + 1 - i];
				num++;
			} else {
				continue;
			}
		}
	}
	cout << num;
	return 0;
}
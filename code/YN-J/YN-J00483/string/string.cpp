#include <bits/stdc++.h>
using namespace std;
long long a[11000];
string s[1500];

int main() {
	freopen("string.in"."r".in);
	freopen("string.out"."w".out);
	int n;
	string a1, b1;
	cin >> n;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> s[i];
	}
	for (int i = 1; i <= n; i++) {
		if (s[i] == s[i + 1]) {
			cout << '0';
			return 0;
		}
		s[i] += '1';
		a1 += s[i];
		cnt++;
	}
	for (int i = n; i >= 0; i--) {
		b1 += s[i];
		if (a1 == b1) {
			cout << cnt;
		}
	}
	return 0;
}
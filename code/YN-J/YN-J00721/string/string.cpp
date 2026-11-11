#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long int n, l = 0;
	cin >> n;
	string s;
	for (int i = 1; i <= n; i++) {
		long long int a;
		char c;
		cin >> a >> c;
		for (int j = l; j < l + a; j++) {
			s[j] = c;
		}
		l += a;
	}
	long long cnt = 0;
	for (int i = 0; i < l / 2; i++) {
		if (s[i] != s[l - 1 - i]) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
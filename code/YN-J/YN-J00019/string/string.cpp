#include <bits/stdc++.h>
using namespace std;
long long n, a;
char c;
string s;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a >> c;
		for (int j = 1; j <= a; j++) {
			s += c;
		}
	}
	long long int c = s.size(), cnt = 0;
	long long int l = 0, r = c - 1;

	while (l <= r) {
		if (s[l] != s[r]) {
			s[r] = s[l];
			cnt++;
		}
		l++;
		r--;
	}
	cout << cnt;
	return 0;
}
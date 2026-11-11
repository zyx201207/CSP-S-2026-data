#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	long long n, a;
	char c;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a >> c;
		for (int j = 1; j <= a; j ++) {
			s += c;
		}
	}
	long long l = s.size() - 1;
	long long ans = 0;
	for (int i = 0; i <= l / 2; i++) {
		if (s[i] != s[l - i]) ans++;
	}
	cout << ans;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
string s;
int l = 0;

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	s[0] = '0';
	for (int i = 1; i <= n; i++) {
		int a;
		char c;
		cin >> a >> c;
		l += a;
		for (int i = 1; i <= a; i++) {
			s += c;
		}
	}
	int sum = 0;
	for (int i = 1; i <= l / 2; i++) {
		if (s[i] != s[l - i + 1]) {
			sum++;
		}
	}
	cout << sum;
	return 0;
}
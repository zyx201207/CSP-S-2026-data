#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
int n, x, cnt;
char a;
string s;
string c;

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		cin >> a;
		while (x--) {
			s += a;
		}
	}
	for (int i = 0; i < s.size() / 2; i++) {
		c += s[i];
	}
	int l = 0, r = s.size() - 1;
	while (l < r) {
		if (s[l] != c[r]) {
			cnt++;
		}
		l++;
		r--;
	}
	cout << cnt;
	return 0;
}
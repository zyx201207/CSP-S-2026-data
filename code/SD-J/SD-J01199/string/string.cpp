#include <bits/stdc++.h>
using namespace std;

long long t, n, k, m;

int main() {
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	long long sum = 0;
	cin >> n;
	string s = "";
	for (int i = 1; i <= n; i++) {
		long long a;
		char x;
		cin >> a >> x;
		for (int i = 1; i <= a; i++) {
			s += x;
		}
	}
//	cout << s << "   ---\n";
	long long l = 0, r = s.length () - 1, ans = 0;
	while (l < r) {
		if (s[l] != s[r]) {
			ans++;
		}
		l++;
		r--;
	}
	cout << ans << "\n";
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/

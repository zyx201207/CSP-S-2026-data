#include <bits/stdc++.h>
using namespace std;
long long n, a, ans;
string s, s1;
char c;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (long long i = 1; i <= n; i++) {
		cin >> a >> c;
		for (long long j = 1; j <= a; j++) {
			s = s + c;
		}
	}
	s1 = s;
	reverse(s1.begin(), s1.end());
	if (s == s1) {
		cout << "0";
		return 0;
	} else {
		for (long long i = 0; i < s.size(); i++) {
			if (s1[i] != s[i])
				ans++;
		}
	}
	cout << ans / 2;
	return 0;
}
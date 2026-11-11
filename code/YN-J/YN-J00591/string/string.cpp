#include <bits/stdc++.h>
using namespace std;
string s;
long long n;
string c;
long long a;
long long ans;

int beupto(long long a) {
	if (a % 2 == 0) {
		return a / 2;
	} else {
		return a / 2 + 1;
	}
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (long long i = 1; i <= n; i++) {
		cin >> a >> c;
		for (long long j = 1; j <= a; j++) {
			\
			s += c;
		}
	}
	for (long long i = 0; i < beupto(s.size()); i++) {
		if (s[i] != s[s.size() - i - 1]) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}
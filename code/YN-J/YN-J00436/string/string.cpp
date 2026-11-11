#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin.tie(0);
	cout.tie(0);
	long long n, cnt = 0;
	string s;
	cin >> n;
	for (long long i = 1; i <= n; i++) {
		long long x;
		char c;
		cin >> x >> c;
		for (long long j = 1; j <= x; j++) {
			s += c;
		}
	}
	long long mid = s.size() / 2;
	for (long long i = 0; i < mid; i++) {
		if (s[i] != s[s.size() - i - 1]) {
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
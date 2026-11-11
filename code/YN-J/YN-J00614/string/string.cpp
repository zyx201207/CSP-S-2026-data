#include <bits/stdc++.h>
using namespace std;
//#define int long long

long long is_huiwen(string s) {
	string s1;
	for (long long i = 0; i < s.size(); i++) {
		s1 += s[s.size() - 1 - i];
	}
	if (s1 == s)
		return 0;
	else {
		long long cnt = 0;
		for (long long i = 0; i < s.size(); i++) {
			if (s1[i] != s[i])
				cnt++;
		}
		return cnt;
	}
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.ans", "w", stdout);
	string s, cinn;
	long long n, m;
	cin >> n;
	for (long long i = 0; i < n; i++) {
		cin >> m >> cinn;
		for (long long j = 0; j < m; j++) {
			s += cinn;
		}
	}

	cout << is_huiwen(s);
	return 0;
}
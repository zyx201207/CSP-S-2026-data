#include <bits/stdc++.h>
using namespace std;

bool hw(string s) {
	string a = s;
	reverse(s.begin(), s.end());
	if (a == s)
		return 1;
	return 0;
}

long long cnt(string s) {
	long long l = s.length(), m = s.length(), ans = 0;
	for (long long i = 0; i < l; i++) {
		m--;
		if (hw(s)) {
			return ans;
		}
		if (s[i] == s[m])
			continue;
		s[m] = s[i];
		ans++;
	}
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, a;
	char c;
	string s = "";
	cin >> n;
	if (n == 1) {
		cout << 0;
		return 0;
	}
	while (n--) {
		cin >> a >> c;
		if (a > 1000)
			return 0;
		for (int i = 1; i <= a; i++) {
			s += c;
		}
	}
	cout << cnt(s);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
long long n;
string s;
string s1;
string l;
string r;
long long ans;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	cin >> n;

	for (long long i = 1; i <= n; i++) {

		long long a;
		char c;

		cin >> a >> c;

		for (long long j = 1; j <= a; j++) {

			s += c;
		}
	}

	s1 = s;
	reverse(s.begin(), s.end());

	if (s1 == s) {
		cout << 0 << endl;
		return 0;
	}

	long long cnt = floor(s.size() / 2.0);

	for (long long i = 0; i <= cnt - 1; i++) {

		l += s1[i];
	}

	for (long long i = s1.size() - 1; i >= s1.size() - cnt; i--) {

		r += s1[i];
	}

	for (long long i = 0; i < l.size(); i++) {

		if (l[i] != r[i]) {
			ans++;
		}
	}

	cout << ans << endl;
	return 0;
}
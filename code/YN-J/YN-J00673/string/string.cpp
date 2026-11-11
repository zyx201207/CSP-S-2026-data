#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n;
	long long a;
	string c;
	cin >> n;
	string s;

	while (n--) {
		cin >> a >> c;

		for (int i = 1; i <= a; i++) {

			s += c;
		}
	}

	string s1 = s;
	reverse(s.begin(), s.end());

	if (s1 == s)
		cout << 0;
	return 0;
}

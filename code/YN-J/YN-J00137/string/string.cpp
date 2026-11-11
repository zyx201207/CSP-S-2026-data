#include <bits/stdc++.h>
using namespace std;
long long n;
string s;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	cin >> n;


	while (n--) {
		long long a;
		char c;
		cin >> a >> c;

		for (long long i = 0; i < a; i++) {

			s += c;
		}
	}

	long long l = s.size();
	char a[l + 1], b[l + 1];

	for (long long i = 0; i < l; i++) {

		a[i] = s[i];
		b[i] = s[l - i - 1];
	}

	long long ans = 0;

	for (long long i = 0; i < l; i++) {

		//cout << a[i] << b[i] << " ";

		if (a[i] != b[i]) {
			ans++;

		}
	}

	cout << ans / 2;
	return 0;
}
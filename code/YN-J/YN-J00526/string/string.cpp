#include <bits/stdc++.h>
using namespace std;
long long a[200005], ans;
char sp[200005];
string s;
long long  l = 0, n;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n;

	cin >> n;
	long long r = n - 1;



	for (int i = 0; i < n; i++) {

		cin >> a[i] >> sp[i];
	}

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < a[i]; j++) {

			s += sp[i];
		}
	}

	while (l <= r) {
		if (s[l] != s[r]) {
			ans++;
		}

		l++;
		r--;
	}

	cout << ans;
	return 0;
}
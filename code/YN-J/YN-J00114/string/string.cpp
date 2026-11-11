#include <bits/stdc++.h>
using namespace std;
string a;
long long n, s[250000];
char x[250000];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;

	for (int i = 1; i <= n ; i++) {

		cin >> s[i] >> x[i];
	}

	a = "";

	for (int i = 1; i <= n ; i++) {

		for (int j = 1; j <= s[i] ; j++) {

			a += x[i];
		}
	}

	int ans = 0;
	int l;
	l = a.size() / 2 ;

	if (l % 2 == 0) {
		for (int i = 0; i <= l; i++) {

			if (a[i] != a[a.size() - i]) {
				ans++;
			}
		}

		cout << ans;
		return 0;
	} else {
		for (int i = 0; i <= l; i++) {

			if (a[i] != a[a.size() - i]) {
				ans++;
			}
		}

		cout << ans + 1;
		return 0;
	}



}


#include <bits/stdc++.h>
using namespace std;
int a[200020];
string s[200020];
string c;
int ans = 1;
int cnt = 0;
int sum = 0;
int tmp = 0;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
		cin >> c;
		cnt += a[i];

		for (int j = ans; j <= a[i] + ans; j++) {

			s[j] = c;

		}

		ans += a[i];
	}

	tmp = cnt;

	for (int i = 1; i <= cnt; i++) {

		if (i == tmp) {
			break;
		}

		if (s[i] != s[tmp]) {
			sum++;
		}

		tmp--;
	}

	cout << sum;
	return 0;
}

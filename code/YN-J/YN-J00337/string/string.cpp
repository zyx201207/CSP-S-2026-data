#include <bits/stdc++.h>
using namespace std;

struct word {
	long long num;
	char c;
} a2[100000005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	string a;
	long long num1, n, cnt = 0;
	char c;
	cin >> n;

	for (int i = 1; i <= n; i++) {

		cin >> num1 >> c;

		if (n * num1 > 3149000005) {
			a2[1].num = num1;

			for (int i = 1; i < n; i++) {

				cin >> a2[i].num >> a2[i].c;
			}

			long long ans = 0;

			for (int i = 0; i < n; i++) {

				int j = n - 1 - i ;

				if (a2[i].c != a2[j].c) {
					ans += max(a2[i].num, a2[j].num);

					if (a2[i].num > a2[j].num)
						a2[j - 1].num -= a2[i].num - a2[j].num;
					else if (a2[i].num < a2[j].num) {
						a2[i + 1].num -= a2[j].num - a2[i].num;
					}

					a2[i].c = a2[j].c;
				}
			}

			cout << ans;
			return 0;
		}

		for (int i = 1; i <= num1; i++) {

			a += c;
		}
	}

	long long len = a.size(), ans = 0;

	for (int i = 0; i < len; i++) {

		int j = len - 1 - i ;

		if (a[i] != a[j]) {
			ans++;
			a[i] = a[j];
		}
	}

	cout << ans;
	return 0;
}

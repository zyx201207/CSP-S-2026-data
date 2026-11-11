#include <bits/stdc++.h>
using namespace std;
int a[1000000];
char c[1000000];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	char s;
	bool p = 1;
	long long cnt = 0;
	string an;

	for (int i = 0; i < n; i++) {

		cin >> a[i];
		cnt += a[i];
		cin >> c[i];

		for (int j = 1; j <= a[i]; j++) {

			an += c[i];
		}

		if (s != c[i] && i != 0) {
			p = 0;
		}

		s = c[i];
	}

	if (p == 1) {
		cout << 0;
	}

	if (p != 1) {

		string ans;
		long long k = an.size();
		long long h = 0;

		for (int i = 1; i <= an.size(); i++) {

			ans += an[k - 1];
			k--;

			if (an[k - 1] != an[i - 1]) {
				h++;
			}
		}

		cout << ceil(h / 2);
	}

	return 0;
}
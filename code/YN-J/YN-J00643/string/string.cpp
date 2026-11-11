#include <bits/stdc++.h>
using namespace std;
const int N = 1e8 + 5;
char c[N], d[N];
long long int a[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	int n;
	cin >> n;
	long long int b = 0;
	long long int e = 1;
	int j = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		for (; j <= a[i]; j++) {
			d[j] = c[i];
		}
		b += a[i];
	}
	int ans = 0;

	if (b % 2 == 0) {
		int i = 1, k = b;
		while (i <= b / 2 && k >= b / 2) {
			if (d[i] != d[k]) {
				ans++;
			}

			i++;
			j--;
		}
		cout << ans;
	} else {
		int i = 1, k = b;
		while (i <= (b - 1) / 2 && k >= (b + 1) / 2) {
			int f, g;
			f = d[i];
			g = d[k];
			if (f % 1 != g % 1) {
				ans++;
			}

			i++;
			j--;
		}
		cout << ans;
	}
	return 0;
}
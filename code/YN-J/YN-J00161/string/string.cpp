#include <bits/stdc++.h>
using namespace std;
long long n, cnt = 0;

long long a[200005] = {0};
string s1, s;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	int x = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> s1[i];

		for (int j = 0; j < a[i]; j++) {
			s[j + x] = s1[i];
		}
		x += a[i];
	}
	int i = 0, j = x - 1, k = 1;
	while (1) {
		if (i > (x - 1) / 2 || j < (x - 1) / 2) {
			break;
		}
		if (s[i] != s[j]) {
			s[i] = s[j];
			cnt += abs(a[k] - a[n - k]);
		}
		i += a[k];
		j -= a[k];
		k++;
	}
	cout << cnt;
	return 0;
}
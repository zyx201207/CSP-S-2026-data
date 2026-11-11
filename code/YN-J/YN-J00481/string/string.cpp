#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 2e5 + 10;
long long a[N], h = 1, cnt;
char s[N], c[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		int r = a[i];
		while (r--) {
			s[h] = c[i];
			h++;
		}
	}
	int l = 1, r = h - 1;
	while (l <= r) {
		if (s[l] != s[r]) {
			cnt++;
			l++;
			r--;
		} else {
			l++;
			r--;
		}
	}
	cout << cnt;
	return 0;
}

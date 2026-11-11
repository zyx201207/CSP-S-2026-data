#include <bits/stdc++.h>
using namespace std;

long long sl[200005] = {};

char s[200005] = {};
long long n, ans = 0, sum = 0;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> sl[i] >> s[i];
	}
	long long p1 = 1, p2 = n;
	while (p1 < p2) {
		if (s[p1] != s[p2]) {
			if (sl[p1] < sl[p2]) {
				ans += sl[p1];
				sl[p2] -= sl[p1];
				sl[p1] = 0;

			} else {
				ans += sl[p2];
				sl[p1] -= sl[p2];
				sl[p2] = 0;
			}
		} else {
			if (sl[p1] < sl[p2]) {
				sl[p2] -= sl[p1];
				sl[p1] = 0;
			} else {
				sl[p1] -= sl[p2];
				sl[p2] = 0;
			}
		}
		if (sl[p1] == 0) {
			p1++;
		}
		if (sl[p2] == 0) {
			p2--;
		}
	}
	cout << ans;
	return 0;
}

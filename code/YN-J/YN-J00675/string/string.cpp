#include <bits/stdc++.h>
using namespace std;
int n, a[1000001], l = 1, r;
long long t = 0;
char s[1000001];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> s[i];
	}
	r = n;
	while (l < r) {
		if (s[l] != s[r]) {
			t += min(a[l], a[r]);
			if (a[l] > a[r]) {
				a[l] -= a[r];
				r--;
			} else if (a[l] < a[r]) {
				a[r] -= a[l];
				l++;
			} else {
				r--;
				l++;
			}
		}
	}
	cout << t;
	return 0;
}
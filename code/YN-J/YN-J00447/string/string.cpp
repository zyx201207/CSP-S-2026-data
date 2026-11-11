#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 1e5 + 10;
int a[N];
char c[N];
char s[N], fs[N];
int t = 1, t1 = 1;
int cnt;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		for (int j = 1; j <= a[i]; j++) {
			s[t] = c[i];
			t++;
		}
	}
	for (int i = t; i >= 1; i--) {
		fs[t1] = s[i];
		t1++;
	}
	for (int i = 1; i <= t; i++) {
		if (fs[i] != s[i]) {
			cnt++;
		}
	}
	cout << cnt / 2;
	return 0;
}

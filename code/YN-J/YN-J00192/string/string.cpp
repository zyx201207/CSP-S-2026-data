#include <bits/stdc++.h>
using namespace std;
int n, cc, cnt;
char a[10000005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	int u, t = 1;
	char x;
	for (int i = 1; i <= n; i++) {
		cin >> u >> x;
		cc += u;
		for (int j = 1; j <= u; j++) {
			a[t] = x;
			t++;
		}
	}
	int l = 1, r = cc;
	while (l <= r) {
		if (a[l] == a[r]) {
			l++;
			r--;
		} else if (a[l] != a[r]) {
			cnt++;
			l++;
			r--;
		}
	}
	cout << cnt;
}
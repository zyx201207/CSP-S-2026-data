#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
char x[200005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, s = 0;
	cin >> n;
	for (int i = 1; i <= n; i = i + 1) {
		cin >> a[i] >> x[i];
	}
	int l = 1, r = n;
	while (l <= r) {
		if (x[l] != x[r]) {
			s += a[r];
		}
		l += 1;
		r -= 1;
	}
	cout << s;
	return 0;
}
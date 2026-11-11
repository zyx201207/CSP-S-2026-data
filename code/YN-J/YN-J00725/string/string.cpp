#include <bits/stdc++.h>
using namespace std;
#define ll long long
int b[200010], l, r;
char f[200010];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ll n, cnt = 0;
	cin >> n;
	l = 1, r = n;
	for (int i = 1; i <= n; i++) {
		cin >> b[i] >> f[i];
	}
	while (r - l != (n % 2 - 1)) {
		if (f[l] != f[r]) {
			cnt += min(b[l], b[r]);
		}
		if (b[l] > b[r])
			b[l] -= b[r], r--;
		else if (b[l] < b[r])
			b[r] -= b[l], l++;
		else
			l++, r--;
	}
	cout << cnt;
	return 0;
}
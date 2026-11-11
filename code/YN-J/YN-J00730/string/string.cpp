#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long n, a[N], cnt = 0ll;
char c[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> c[i];
	int l = 1, r = n;
	while (l < r) {
		int k = min(a[l], a[r]);
		if (c[l] != c[r])
			cnt = cnt + k;
		a[l] = a[l] - k;
		a[r] = a[r] - k;
		if (!a[l])
			l++;
		if (!a[r])
			r--;
	}
	cout << cnt;
	return 0;
}
//¿ª×¢ÊÍ£¡£¡£¡
#include <bits/stdc++.h>
using namespace std;

struct ST {
	long long mun;
	char ch;
};

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n;
	cin >> n;
	ST a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i].mun >> a[i].ch;
	}
	long long ans = 0;
	int l = 0, r = n - 1;
	while (l < r) {
		int k = min(a[l].mun, a[r].mun);
		if (a[l].ch != a[r].ch)
			ans += k;
		a[l].mun -= k;
		a[r].mun -= k;
		if (a[l].mun == 0)
			l++;
		if (a[r].mun == 0)
			r--;
	}
	cout << ans;
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

int a[200010];
char c[200010];

int main( ) {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i] >> c[i];
	int i = 1, j = n;
	long long ans = 0;
	while (i < j) {
		int cur = min(a[i], a[j]);
		if (c[i] == c[j]) {
			a[i] -= cur, a[j] -= cur;
			if (a[j] == 0) --j;
			if (a[i] == 0) ++i;
		} else {
			ans += cur;
			a[j] -= cur;
			a[i] -= cur;
			if (a[j] == 0) --j;
			if (a[i] == 0) ++i;
		}
	}
	cout << ans;
	return 0;
}//1000000000

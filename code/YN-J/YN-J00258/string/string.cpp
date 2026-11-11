#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[200010];
char b[200010];
int sam;

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> b[i];
	for (int i = 1, j = n; i < j;) {
		if (b[i] != b[j])
			sam += min(a[i], a[j]);
		if (a[i] > a[j])
			a[i] -= a[j], j--;
		else if (a[i] < a[j])
			a[j] -= a[i], i++;
		else
			i++, j--;
	}
	cout << sam;
	return 0;
}

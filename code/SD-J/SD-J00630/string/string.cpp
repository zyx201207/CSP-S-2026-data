#include <bits/stdc++.h>
using namespace std;
const int M = 2e5 + 10;
int n;
struct node {
	long long x;
	char c;
} a[M];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].c;
	}
	int l = 1, r = n;
	long long ans = 0, ls = a[1].x, rs = a[n].x;
	while (l < r) {
		if (a[l].c != a[r].c) ans += min(ls, rs);
		if (ls == rs) {
			l++, r--, ls = a[l].x, rs = a[r].x;
		} else if (ls < rs) {
			l++, rs -= ls, ls = a[l].x;
		} else {
			r--, ls -= rs, rs = a[r].x;
		}
	}
	cout << ans << endl;
	return 0;
}

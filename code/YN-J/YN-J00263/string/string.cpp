#include <bits/stdc++.h>//Chinese can fly !
using namespace std;
#define int long long
const int N = 2e5 + 5;
int n, ans;

struct sephiroth {
	int num;
	char c;
} a[N];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].num >> a[i].c;
	}
	int f = 1, l = n;
	while (f < l) {
		int sum = 0;
		sum = min(a[f].num, a[l].num);
		a[f].num -= sum, a[l].num -= sum;
		if (a[f].c != a[l].c) {
			ans += sum;
		}
		if (a[f].num == 0)
			f++;
		if (a[l].num == 0)
			l--;
	}
	cout << ans << "\n";
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
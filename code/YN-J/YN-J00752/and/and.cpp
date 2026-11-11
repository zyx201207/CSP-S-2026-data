#include <bits/stdc++.h>
using namespace std;
#define IOS std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
const int N = 2e5 + 5;
int n, m, a[N], maxx = 0;

signed main() {
	IOS
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n + 1 - m; i++) {
		int andd = a[i];
		for (int j = i; j <= i + m - 1; j++) {
			andd &= a[j];
		}
		maxx = max(maxx, andd);
	}
	cout << maxx;
	return 0;
}

/*
3 15 12 12
a :0011 1111  1100   1100
| :0011 1111  1111   1100
+ :0011 10010 11110  101010
|+:0011 10010 100001 101101
& :101010-100111+1111
^ :0011 1100  0000  1100
*/
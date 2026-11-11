#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int maxn = 2e5 + 10;
int n;
struct node {
	int a;
	char s;
} zc[maxn];
int l, r;
int ans = 0;
signed main () {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	l = 1, r = n;
	for (int i = 1; i <= n; i ++) {
		cin >> zc[i].a >> zc[i].s;
	}
	while (l < r) {
		if (zc[l].s != zc[r].s) {
			if (zc[l].a > zc[r].a) {
				zc[l].a -= zc[r].a;
				ans += zc[r].a;
				r --;
			} else if (zc[l].a == zc[r].a) {
				ans += zc[l].a;
				l ++;
				r --;
			} else {
				zc[r].a -= zc[l].a;
				ans += zc[l].a;
				l ++;
			}
		} else {
			if (zc[l].a > zc[r].a) {
				zc[l].a -= zc[r].a;
				r --;
			} else if (zc[l].a == zc[r].a) {
				l ++;
				r --;
			} else {
				zc[r].a -= zc[l].a;
				l ++;
			}
		}
	}
	cout << ans;
	return 0;
}



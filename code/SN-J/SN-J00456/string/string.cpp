#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int s; char c;
}a[200005];
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].s >> a[i].c;
	int l = 1, r = n, ans = 0;
	while (l < r) {
		if (a[l].s == a[r].s) {
			if (a[l].c != a[r].c) ans += a[l].s;
			l++; r--;
		}else if (a[l].s > a[r].s) {
			if (a[l].c != a[r].c) ans += a[r].s;
			a[l].s -= a[r].s;
			a[r].s = 0; r--;
		}else {
			if (a[l].c != a[r].c) ans += a[l].s;
			a[r].s -= a[l].s;
			a[l].s = 0; l++;
		}
	}
	cout << ans;
	return 0;
} 

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n;
struct Node {
	int a;
	char c;
} a[N];
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].a >> a[i].c;
	}
	int ans = 0;
	for (int l = 1, r = n; l < r; ) {
		if (a[l].c != a[r].c) {
			ans += min(a[l].a, a[r].a);
		}
		if (a[l].a == a[r].a) {
			l++; r--;
		} else if (a[l].a < a[r].a) {
			a[r].a -= a[l].a;
			l++;
		} else {
			a[l].a -= a[r].a;
			r--;
		}
	}
	cout << ans;
	return 0;
}

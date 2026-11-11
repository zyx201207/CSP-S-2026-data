#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 7;
int n, ans, l;
struct node {
	int cnt;
	char c;
} a[N];
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].cnt >> a[i].c;
	bool flag = 0;
	for (int i = 2; i <= n; i++) {
		if (a[i].c != a[i - 1]. c) {
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		cout << 0;
		return ;
	}
	int r = n;
	while (l <= r) {
		if (a[l].cnt == a[r].cnt && a[l].c != a[r].c) ans += a[l].cnt, r--, l++;
		if (a[l].cnt == a[r].cnt && a[l].c == a[r].c) l++, r--;
		if (a[l].cnt < a[r].cnt && a[l].c != a[r].c) a[r].cnt -= a[l].cnt, ans += a[l].cnt, l++; 
		if (a[l].cnt < a[r].cnt && a[l].c == a[r].c && a[r].c != a[l + 1].c) l++, a[r].cnt -= a[l].cnt;
		if (a[l].cnt > a[r].cnt && a[l].c != a[r].c) a[l].cnt -= a[r].cnt, ans += a[r].cnt, r--; 
		if (a[l].cnt > a[r].cnt && a[l].c == a[r].c && a[l].c != a[r - 1].c) r--, a[l].cnt -= a[r].cnt;
	}
	cout << ans;
}
signed main() {
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int T = 1;
//	cin >> T;
	while (T--) solve();
	return 0;
}


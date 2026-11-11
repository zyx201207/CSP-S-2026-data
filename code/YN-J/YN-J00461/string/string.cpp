#include <bits/stdc++.h>
using namespace std;
#define in cin
#define out cout
#define int long long
const int N = 2e5 + 5;
struct node { int cnt; char ch; } a[N];
int n;
signed main() {
	freopen("string.in", "r", stdin), freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false), in.tie(nullptr), out.tie(nullptr);
	in >> n;
	for (int i = 1; i <= n; i++) in >> a[i].cnt >> a[i].ch;
	int ans = 0;
	for (int l = 1, r = n; l < r;)
		if (a[l].cnt >= a[r].cnt) ans += (a[l].ch != a[r].ch) * a[r].cnt, a[l].cnt -= a[r].cnt, r--;
		else ans += (a[l].ch != a[r].ch) * a[l].cnt, a[r].cnt -= a[l].cnt, l++;
	out << ans;
	return 0;
}
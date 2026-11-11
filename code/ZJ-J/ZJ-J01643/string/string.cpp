#include <bits/stdc++.h>
#define File(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout)
#define int long long
#define endl '\n'
using namespace std;
const int N = 2e5 + 10;
struct Nod {
	int len;
	char ch;
} a[N];
signed main() {
	File("string");
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	int res = 0;
	for (int i = 1; i <= n; i ++) cin >> a[i].len >> a[i].ch, res += a[i].len;
	int i = 1, j = res;
	int pi = 1, pj = n;
	int ans = 0;	
	while (i <= j) {
		if (a[pi].len >= a[pj].len) {
			if (a[pi].ch != a[pj].ch)
				ans += a[pj].len;
			i += a[pj].len;
			j -= a[pj].len;
			a[pi].len -= a[pj].len;
			pj --;
		} else {
			if (a[pj].ch != a[pi].ch)
				ans += a[pi].len;
			i += a[pi].len;
			j -= a[pi].len;
			a[pj].len -= a[pi].len;
			pi ++;
		}
	}
	cout << ans;
	return 0;
}

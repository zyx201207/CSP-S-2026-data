#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 2e5 + 10;
int a[MAXN], pre[MAXN], suf[MAXN]; 
char ch[MAXN];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, match = 0, ans = 0; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> ch[i];
		pre[i] = pre[i - 1] + a[i];
	}
	for (int i = n; i >= 1; --i)
		suf[i] = suf[i + 1] + a[i];
	reverse(suf + 1, suf + n + 1);
	
	while (match < pre[n] / 2) {
		int lp = upper_bound(pre + 1, pre + n + 1, match) - pre;
		int rp = upper_bound(suf + 1, suf + n + 1, match) - suf;
		rp = n + 1 - rp;
		if (lp >= rp) break;
		int lRes = pre[lp] - match;
		int rRes = suf[n + 1 - rp] - match;
		if (lRes <= rRes) {
			match += lRes;
			ans += (ch[lp] != ch[rp]) * lRes;
		}
		else {
			match += rRes;
			ans += (ch[lp] != ch[rp]) * rRes;
		}
//		cout << lp << " " << rp << " " <<
//			" " << suf[n + 1 - rp] << " " << match << " " << ans << "\n";
	}
	cout << ans; return 0;
} 

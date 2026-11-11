#include <bits/stdc++.h>

#define int long long
#define PII pair <int, int>

using namespace std;

struct node{
	int l, r;
	char ch;	
};

void solve() {
    int n, allen = 0;
    cin >> n;
	vector <node> s(n), rs(n);
	for (int i = 0; i < n; i++) {
		int x; char y;
		cin >> x >> y;
		allen += x;
		if (i == 0) 
			s[i].l = 1, s[i].r = x, s[i].ch = y;
		else
			s[i].l = s[i - 1].r + 1, s[i].r = s[i - 1].r + x, s[i].ch = y;
	}	
	
	for (int i = 0; i < n; i++) 
		rs[i].l = allen + 1 - s[i].r, rs[i].r = allen + 1 - s[i].l, rs[i].ch = s[i].ch;
//	for (int i = 0; i < n; i++) 
//		cout << s[i].l << ' ' << s[i].r << ' ' << s[i].ch << '\n';
//	for (int i = 0; i < n; i++) 
//		cout << rs[i].l << ' ' << rs[i].r << ' ' << rs[i].ch << '\n';
	int res = 0, it = 1, left = 0, right = n - 1;
	while (left <= n && right >= 0) {
		int len;
//		cout << it << '\n';
		if (rs[right].r < s[left].r) {
			len = rs[right].r - it + 1;
			res += len * ((rs[right].ch == s[left].ch) == 0);
			it = rs[right].r + 1;
			right--;
		}
		else if (rs[right].r == s[left].r) {
			len = rs[right].r - it + 1;
			res += len * ((rs[right].ch == s[left].ch) == 0);
			it = rs[right].r + 1;
			right--, left++;
		}
		else {
			len = s[left].r - it + 1;
			res += len * ((rs[right].ch == s[left].ch) == 0);
			it = s[left].r + 1;
			left++;
		}
	}
	
	cout << res / 2 << '\n';
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
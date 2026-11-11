#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXN = 2e5 + 10;
int cnt, ans, nxt[MAXN], lst[MAXN], cl, cn;

void clear(int* arr, int& len) {
	for (int i = 1; i <= len; ++i)
		arr[i] = 0;
	len = 0; return;
}

void add(int* arr, int& len, int x) {
	arr[++len] = x;
	return;
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, x; cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> x; 
		add(lst, cl, x);
	}
	
	for (int bit = 30; bit >= 0; --bit) {
		if (cn > 0) clear(lst, cl);
		for (int i = 1; i <= cn; ++i) add(lst, cl, nxt[i]);
		cnt = 0; clear(nxt, cn);
		for (int i = 1; i <= cl; ++i) 
			if ((lst[i] >> bit) & 1) {
				cnt++;
				add(nxt, cn, lst[i]);
			}
		if (cnt >= m) ans |= (1 << bit);
		else clear(nxt, cn);
	}
	cout << ans; return 0;
}

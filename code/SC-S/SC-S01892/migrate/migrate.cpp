#include<bits/stdc++.h>
#define file "migrate"
#define int long long
using namespace std;
int c, T, n, d, x[2000000 + 5];
inline int nxt(int i) { return upper_bound(x + i, x + n + 1, x[i] + d) - x - 1; }
int32_t main() {
	freopen(file ".in", "r", stdin);
	freopen(file ".out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin >> c >> T;
	while (T--) {
		cin >> n >> d;
		for (int i = 1; i <= n; ++i)
			cin >> x[i];
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				if (nxt(i) >= j) continue;
				bool flg = 1, t = 0;
				int k = nxt(i), lst = i;
				while (nxt(k) < j) {
					if (nxt(k) == k) {
						flg = 0; break;
					}
					int cnt = 0;
					if (lst < k - 1 && nxt(k - 1) == nxt(k)) cnt++;
					if (lst < k - 2 && nxt(k - 2) == nxt(k)) cnt++;
					if (cnt == 1) {
						if (t) flg = 0;
						else t = 1;
//						cerr << "(current flg = " << flg <<")in " << i << " and " << j << ", " << k << " march" << endl;
					}
					if (cnt == 2) flg = 0;
					lst = k; k = nxt(k);
				}
				int cnt = 0;
				if (lst < k - 1 && nxt(k - 1) >= j) cnt++;
				if (lst < k - 2 && nxt(k - 2) >= j) cnt++;
				if (cnt == 1) {
					if (t) flg = 0;
					else t = 1;
//					cerr << "(current flg = " << flg <<")in " << i << " and " << j << ", " << k << " march" << endl;
				}
				if (cnt == 2) flg = 0;
				if (flg && t) ans++/*, cout << i << ' ' << j << endl*/;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
/*
白鸟白鸟不要回头望
你要替我飞去那地方
一去那地方 那是你我共同故乡
别回来
*/
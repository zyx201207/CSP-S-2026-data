#include <bits/stdc++.h>
#define int long long
using std::cin;
using std::cout;
using std::endl;
using std::clog;
int n, m;
const int maxn = 5e5 + 1;
int a[maxn];
int ans = 0;
int q[maxn], qt = 0;
int cnt[maxn];
signed main() {
	#ifndef MCH
		freopen("card.in", "r", stdin);
		freopen("card.out", "w", stdout);
	#else
		freopen("D:/cspj/card/card4.in", "r", stdin);
	#endif
	// 打磨你
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	;
//	std::bitset<maxn> dis;
	for (int i = 1; i <= n; ++i) {
		qt = 0;
//		dis.reset();
		for (int k = i; k <= n; ++k) {
//			if (dis[a[k]]) continue;
//clog << a[k] << ' ';
			bool cl = false;
			int tqt = qt;
			for (int j = 0; j < qt; ++j) {
				if (cl) {
//				dis[q[j]] = true;
				q[j] = 0;}
				else if (q[j] == a[k]) {
					cl = true;
					// qt[j] = a[k];
					tqt = j + 1;
//					dis[a[k]] = true;
}
			}
			qt = tqt;
			if (!cl) {
				q[qt++] = a[k];
			}
		}
		// 我的第一局怎么消失了
//		clog << "| ";
		for (int j = 0; j < qt; ++j) {
//			clog << q[j] << ' ';
			cnt[q[j]]++;
		}
//		clog << endl;
//		cnt[a[i - 1]]++;
	}
	for (int i = 1; i <= m; ++i) {
//		if (cnt[i] == 0) break;
		cout << cnt[i] << ' ';
	}
	cout << endl;
	// 早知道倒序开题了...?
//	for (int i = 0; i < n; ++i) {
//		;
//	}
//	cout << ans << endl;
	return 0;
}
// 可恶, 连两百分都到不了了
// CCF I will get LOVE from you
// 等我回家再来和你大战 inf 回合
// AHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
// QwQ
// 只有... 160... pts...


#include <bits/stdc++.h>
#define int long long
using std::cin;
using std::cout;
using std::endl;
using std::clog;
int n;
const int maxn = 2e5 + 1;
int a[maxn]; char c[maxn];
//std::string s;
int asum = 0;
int ans = 0;
signed main() {
	clog << "你们现在进行的评测被禁止了, 这是通知" << endl;
	#ifndef MCH
		freopen("string.in", "r", stdin);
		freopen("string.out", "w", stdout);
	#else
//		freopen("D:/cspj/string/string6.in", "r", stdin);
//		freopen("D:/cspj/string/string6.out", "r", stdout);
		freopen("string.log", "w", stderr);
	#endif
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> c[i];
//		for (int j = 0; j < a[i]; ++j) {
//			s += c[i];
//		}
		asum += a[i];
	}
	#ifdef MCH
		clog << "n = " << n << ", asum = " << asum << endl;
	#endif
//	clog << s << endl;
//	int i = 0, j = asum - 1;
//	while (i < j) {
//		ans += (s[i++] != s[j--]); // TLE ^_^
//		;
//	}
	int i = 0, j = n - 1, io = 0, jo = 0;
	int ri = 0, rj = asum - 1; // real i real j  true home true world (?
	while (ri <= rj) {
		// 是累计 ans 的时候出问题了吗 还是我的做法本身就有问题
		if (a[i] > a[j]) {
			jo = a[i] - a[j]; rj = rj - jo - a[j];
			if (c[i] != c[j]) ans += a[j];
			while (true) {
				if (a[--j] - jo <= 0) {
					jo = 0 - (a[j] - jo);
					if (c[i] != c[j]) ans += a[j];
					continue;
				} else {
					if (c[i] != c[j]) ans += jo;
					break;
				}
			}
//			int jocnt = 
			ri += a[i++];
		} else if (a[i] < a[j]) {
			io = a[j] - a[i]; ri += io + a[i];
			if (c[i] != c[j]) ans += a[i];
			while (true) {
				if (a[++i] - io <= 0) {
					io = 0 - a[i] + io;
					if (c[i] != c[j]) ans += a[i];
					continue;
				} else {
					if (c[i] != c[j]) ans += io;
					break;
				}
			}
			rj -= a[j--];
		} else {
			ans += (c[i] != c[j]) * a[i];
			ri += a[i++], rj -= a[j--];
//			++i; --j;
io = 0, jo = 0;
		}
		#ifdef MCH
			clog << ri << ' ' << rj << ' ' << i << ' ' << j << endl;
		#endif
	}
	cout << ans << endl;
//	clog << "...!" << endl;
	return 0;
}
// 不是为什么啊


#include <bits/stdc++.h>
#define int long long
using std::cin;
using std::cout;
using std::endl;
using std::clog;
// !? 背包?!
int n, m;
const int maxn = 2e5 + 1;
int a[maxn];
//int dp[maxn];
int ans = 0;
std::bitset<maxn> vis;
void dfs(int mc, int an) {
	if (mc == m) {
		ans = std::max(ans, an);
		return ;
}
	if (mc == 0) {
//		for (auto ai: a) {
//			dfs(mc + 1, ai);
//		}
for (int i = 1; i <= n; ++i) {
	if (vis[i]) continue;
	vis[i] = true;
	dfs(mc + 1, a[i]);
	vis[i] = false;
}
	} else
//	for (auto ai: a) {
	for (int i = 1; i <= n; ++i) {
//		dfs(mc + 1, an & ai);
if (vis[i]) continue;
vis[i] = true;
		dfs(mc + 1, an & a[i]);
		vis[i] = false;
	}
	return ;
}
signed main() {
	clog << "..." << endl;
	#ifndef MCH
		freopen("and.in", "r", stdin);
		freopen("and.out", "w", stdout);
	#endif
	cin >> n >> m;
	// 好消息 似乎能用背包
	// 坏消息 前面忘了中间忘了
//	int ans = 0;
	for (int i = 1; i <= n; ++i) cin >> a[i];;
	{
	/*
	for (int ai = 1; ai <= n; ++ai) {
		memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; ++i) {
//		cin >> a[i];
		for (int j = m; j > 0; --j) {
			{
// Only feels like
// Nothing could be better
// When I with you
// When I with you

// Dancing all night
// 后面忘了.
// 这是通知
				; ; ;;;
				; ; ;;;
				;; ; ;;;
				;; ; ;;;
				; ; ; ;;;;
				; ; ; ;;;;
				;; ;; ;;; ; ;
				;; ;; ;;; ; ;
				;;;
				;;;
				;;; ;
				;;; ;
				;;; ;;;
				;;; ;;;
				; ; ; ; ;
				; ; ; ; ;
				;;;;;;;
				;;;;;;;
				;;;; ; ;
				;;;; ; ;
				;; ;; ;; ;; ;; ;; ;; ;; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ; ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
				// BOOM!!
}               // X X X   XX X
				// 订阅 OI-Debug 谢谢喵
			; // 你还有两个小时不到, 但是你没做出来 T2 和 T3
			if (dp[j] != 0) dp[j] = std::max(dp[j], dp[j - 1] & a[i]);
			else dp[j] = a[ai];
		}
	} ans = std::max(ans, dp[m]); }
//	cout << dp[m] << endl;
	cout << ans << endl;
//	*/
	/*
	// 算了, 暴力 (
	int ans = 0;
	for (int i = 0, t; i < m; ++i) {
		t = 0;
		for (int j = 1; j <= n; ++j) {
			;
		}
	}
	cout << ans << endl;
	*/
	}
	dfs(0, 0);
	cout << ans << endl;
	return 0;
}


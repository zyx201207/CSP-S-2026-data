// CSP 2026 rp++
// 多测清空
// 保证 sumn 手动清空
// 四倍线段树 
// 滚动数组清空
// long long 要不要开
// 开了会不会 MLE
// 代码过编译
// freopen 写对
// 文件名写对 
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define repp(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define perr(i, a, b) for (int i = (a); i > (b); i--)
#define endl '\n'
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
inline int read(){
	int res = 0, f = 1; char c = getchar();
	while (!isdigit(c)){ if (c == '-') f = -1; c = getchar(); }
	while (isdigit(c)){ res = res * 10 + c - '0'; c = getchar(); }
	return res * f;
}

// Definitions.

const int N = 5e5 + 10;
int n, m, s[N], mn, mx, val[N];
bool check(int len){
	rep(r, len, n){
		int l = r - len + 1;
		if (val[r] * len - (s[r] - s[l - 1]) <= m) return 1;
	}
	return 0;
}
void solve(){
	n = read(), m = read();
	rep(i, 1, n) val[i] = read();
	sort(val + 1, val + n + 1);
	rep(i, 1, n) s[i] = s[i - 1] + val[i];
	int l = 1, r = n, res = 0;
	while (l <= r){
		int mid = (l + r) / 2;
		if (check(mid)) res = mid, l = mid + 1;
		else r = mid - 1;
	}
	printf("%lld\n", res);
}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int t = 1;
	while (t--) solve();
	return 0;
}

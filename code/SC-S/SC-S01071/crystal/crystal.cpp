#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i ++ )
#define per(i, l, r) for(int i = (l); i >= (r); i -- )
#define frein(s) freopen(s, "r", stdin)
#define freout(s) freopen(s, "w", stdout)
#define int long long
#define endl '\n'
using namespace std;

static constexpr int N = 5e5 + 5;
static int n;
static long long m, a[N], pre[N];

bool check(int x) {
	rep(i, 1, n - x + 1) {
		int j = i + x - 1;
		long long su = a[j] * x - pre[j] + pre[i - 1]; 
		if(su <= m) return true;
	}
	return false;
} 

signed main() {
	frein("crystal.in"), freout("crystal.out");
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	rep(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	rep(i, 1, n) pre[i] = pre[i - 1] + a[i];
	int l = 1, r = n, mid, ans;
	while(l <= r) {
		mid = l + r >> 1;
		if(check(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	cout << ans << endl;
	return 0;
}
//code by wsy_I.luogu uid: 1152799
/*
二分答案，必定在一个连续段中。
这个连续段需要求出最小值，额其实就是在最中间的那个数的位置。调整法可以论证 
前缀和，做完了？ 
*/
#include <bits/stdc++.h>
#define int long long
#define fp(i,a,b) for(int i=a;i<=b;i++)
#define pf(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

constexpr int MN = 5e5+10;
int n, m, a[MN], pre[MN];

bool chk(int x) {
	fp(i,x,n) {
		int nd = (x-1) * a[i] - (pre[i-1] - pre[i-x-1]);
		if(nd <= m) return 1;
	}
	return 0;
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	fp(i,1,n) cin>>a[i];
	sort(a+1, a+1+n);
	fp(i,1,n) pre[i] = pre[i-1] + a[i];
	int l = 1, r = n, mid, ans = 1;
	while(l <= r) {
		mid = (l + r) >> 1;
		if(chk(mid)) {
			ans = mid;
			l = mid + 1;
		} else r = mid - 1;
	}
	cout<<ans;
	return 0;
}

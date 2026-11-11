#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;

// freopen()
// AC on 14:51
// upd: WA on 16:15
// upd: AC on 16:25, add sort
// 关注 luogu@jackzhangcn2013 谢谢喵

int n, m;
int a[N], ma[N][31], sum[N];
void init() {
	for(int i = 1; i <= n; i++) {
		ma[i][0] = a[i];
	}
	for(int i = 1; i < 31; i++) {
		for(int j = 1; j + (1LL << i) - 1 <= n; j++) {
			ma[j][i] = max(ma[j][i - 1], ma[j + (1LL << (i - 1))][i - 1]);
		}
	}
}
int query(int l, int r) {
	int len = __lg(r - l + 1);
	return max(ma[l][len], ma[r - (1LL << len) + 1][len]);
}
bool check(int mid) {
	for(int l = 1; l + mid - 1 <= n; l++) {
		int r = l + mid - 1;
		int s = sum[r] - sum[l - 1];
		int ma = query(l, r);
		int cnt = ma * mid - s;
		if(cnt <= m) {
			return 1;
		}
	}
	return 0;
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	init();
	int l = 1, r = n + 1, mid;
	while(l + 1 < r) {
		mid = (l + r) / 2;
		if(check(mid)) {
			l = mid;
		}
		else {
			r = mid;
		}
	}
	cout << l;
	return 0;
}
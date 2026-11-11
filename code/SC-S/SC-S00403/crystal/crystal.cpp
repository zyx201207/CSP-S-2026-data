#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 5e5 + 7; //kai long long
typedef long long LL;
int n, cnt;
LL m, a[MAXN], b[MAXN], num[MAXN], val[MAXN], minn = 1e12 + 7, maxn = -(1e12 + 7), ans, Ans;
LL sum[MAXN];
bool check(int l, int r) {
	int len = r - l + 1;
	return (1ll * val[a[r]] * len - (sum[r] - sum[l - 1])) <= m;
}
LL getans(int x) {
	LL p = num[x];
//	if (x == 1) return 1;
	LL L = 1, R = p;//
	while (L <= R) {
		LL M = (L + R) >> 1;
		if (check(M, p)) R = M - 1, ans = p - M + 1;
		else L = M + 1;
	}
	return ans;
}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		b[i] = a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	cnt = unique(b + 1, b + n + 1) - b - 1;
	for (int i = 1; i <= n; i++) {
		int p = lower_bound(b + 1, b + cnt + 1, a[i]) - b;
		num[p] = i;
		val[p] = a[i]; a[i] = p;
	}
	for (int i = 1; i <= cnt; i++) {
		Ans = max(getans(i), Ans);
	}
	cout << Ans << endl;
	return 0;
}
//SN-S00695
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 5e5 + 7, inf = 2e18;
int n, m, ans;
int a[N], sum[N];
int cnt, l[N], r[N];
int f(int L, int R, int x){
	if (R < L) return -1;
	int res = x * (R - L + 1);
	res -= sum[R] - sum[L - 1];
	return res <= m;
}
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out","w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	a[0] = -inf, a[n + 1] = inf;
	for (int i = 1; i <= n; i++){
		sum[i] = sum[i - 1] + a[i];
		if (a[i] != a[i - 1]){
			r[cnt] = i - 1;
			l[++cnt] = i;
		}
		if (i == n) r[cnt] = n;
	}
	for (int i = 1; i <= cnt; i++){
		int x = a[l[i]], rlim = r[i], res = l[i];
		int L = 1, R = l[i];
		while(L <= R){
			int mid = (L + R) >> 1;
			if (f(mid, rlim, x)) R = mid - 1, res = mid;
			else L = mid + 1;
		}
		ans = max(ans, rlim - res + 1);
	}
	cout << ans << '\n';
} 

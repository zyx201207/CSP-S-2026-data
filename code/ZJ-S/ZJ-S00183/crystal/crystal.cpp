#include<bits/stdc++.h>
#define int long long
#define rep(i, l, r) for(int i = (l); i <= (r); ++ i)
#define per(i, r, l) for(int i = (r); i >= (l); -- i)
using namespace std;
const int N = 5e5 + 10;
int n, m, a[N];
void Jail() {
	cin >> n >> m;
	rep(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	int sum = 0, j = 1, ans = 0;
	rep(i, 1, n) {
		sum += a[i];
		while(j <= i && a[i] * (i - j + 1) - sum > m) 
			sum -= a[j], ++ j;
//		cout << i << ' ' << j << ' ' << sum << ' ' << a[i] * (i - j + 1) << endl;
		ans = max(ans, i - j + 1);
	}
	cout << ans << endl;
}
signed main() {
	freopen("crystal.in", "r", stdin); freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	while(T --) Jail();
	return 0;
}

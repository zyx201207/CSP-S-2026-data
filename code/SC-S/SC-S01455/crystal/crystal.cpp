#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IL inline
#define FIO(name) freopen(name".in", "r", stdin), freopen(name".out", "w", stdout)
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define lop(i, a, b) for (auto i = (a); i <= (b); i++)
#define pol(i, a, b) for (auto i = (a); i >= (b); i--)
#define asmax(a, b) ((a) = max((a), (b)))
#define asmin(a, b) ((a) = min((a), (b)))
const int N = 5e5 + 5;
int n;
ll m, a[N];
int main () {
	FIO("crystal");
	IOS;
	cin >> n >> m;
	lop(i, 1, n) cin >> a[i];
	sort(a+1, a+1+n);
//	lop(i, 1, n) cout << a[i] << " \n"[i == n];
	ll d = 0;
	int ans = 1;
	for (int l = 1, r = 1; r <= n; r++) {
		d += (r - l) * (a[r] - a[r-1]);
//		cout << "last: " << l << ' ' << r << ' ' << d << '\n';
		while (l <= r && d > m) d -= a[r] - a[l++];
//		cout << "new: " << l << ' ' << r << ' ' << d << '\n';
		asmax(ans, r - l + 1);
	}
	cout << ans;
	return 0;
}
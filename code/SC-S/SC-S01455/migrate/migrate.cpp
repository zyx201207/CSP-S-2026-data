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
#define fst first
#define snd second
const int N = 2e6 + 5;
int n;
ll d, a[N], b[N], cnt[N];
int main () {
	FIO("migrate");
	IOS;
	int subid, T; cin >> subid >> T;
	while (T--) {
		cin >> n >> d;
		lop(i, 1, n) cin >> a[i];
		if (n == 1) {
			cout << "0\n";
		} else if (11 <= subid && subid <= 12) {
			int k = d / (a[2] - a[1]);
			ll ans = n - 2 * k + 1;
			if (k <= 1 || ans <= 0) cout << "0\n";
			else cout << ans << '\n';
		} else if (13 <= subid && subid <= 14) {
			cout << "0\n";
		} else {
			ll ans = 0;
			pol(i, n-3, 1) ans += i;
			cout << ans << '\n';
		}
	} 
	return 0;
}
/*
0 2
4 2 
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool M1;
const int N = 5e5 + 10;
ll n, m, ans, a[N], s[N];
bool M2;
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; cin >> a[i ++] ) ;
	sort(a + 1, a + n + 1);
	for (int i = 1, j = 1; i <= n; i++){
		s[i] = s[i - 1] + a[i];
		while ((i - j) * a[i] - s[i - 1] + s[j - 1] > m) j ++ ;
		ans = max(ans, (ll)i - j + 1);
	}
	cout << ans << '\n' ;
	cerr << 1000 * clock() / CLOCKS_PER_SEC << " MS\n" ;
	cerr << 1.0 * fabs(&M1 - &M2) / 1024 / 1024 << " MB\n" ;
	return 0;
}

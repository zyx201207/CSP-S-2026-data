#include <bits/stdc++.h>
using namespace std;
#define int long long
#define oo 1000000000000000000
#define _i128 __int128
#define pii pair<int, int>
#define fi first
#define se second
#define for1(i, a, b) for (int i = (a); i <= (b); i++)
#define for2(i, a, b) for (int i = (a); i >= (b); i--)
const int N = 2e5 + 5;
int TT = 1;
int a[N];
char c[N];

void solve()
{
	int n; cin >> n;
	for1(i, 1, n) cin >> a[i] >> c[i];
	int i = 1, j = n, p1 = 0, p2 = 0, ans = 0;
	while (i < j){
		if (a[i] - p1 <= a[j] - p2){
			if (c[i] != c[j]) ans += a[i] - p1;
			p2 += a[i] - p1;
			i++, p1 = 0;
			if (p2 == a[j]) j--, p2 = 0;
		} else {
			if (c[i] != c[j]) ans += a[j] - p2;
			p1 += a[j] - p2;
			j--, p2 = 0;
			if (p1 == a[i]) i++, p1 = 0;
		}
	}
	cout << ans << "\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	//cin >> TT;
	while (TT--)
		solve();
	
	return 0;
}

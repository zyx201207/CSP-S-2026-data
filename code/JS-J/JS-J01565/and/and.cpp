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

void solve()
{
	int n, m; cin >> n >> m;
	vector<int> v;
	for1(i, 1, n){
		int a; cin >> a;
		v.push_back(a);
	}
	int ans = 0;
	for2(j, 29, 0){
		int cnt = 0;
		for (int i : v) cnt += (i >> j & 1);
		if (cnt < m) continue;
		ans |= (1 << j);
		vector<int> tmp;
		for (int i : v)
			if (i >> j & 1)
				tmp.push_back(i);
		v = tmp;
	}
	cout << ans << "\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	//cin >> TT;
	while (TT--)
		solve();
	
	return 0;
}

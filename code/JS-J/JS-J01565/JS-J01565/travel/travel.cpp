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
	string c1, s1, c2, s2; cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2){
		cout << 1;
		if (s1[0] == s2[0] && s1[1] == s2[1]){
			cout << 1;
			if (s1[2] <= 'C' && s2[2] <= 'C') cout << 1 << (abs(s1[2] - s2[2]) == 1);
			else if (s1[2] >= 'D' && s2[2] >= 'D') cout << "11";
			else cout << "00";
		} else cout << "000";
	} else cout << "0000";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	//cin >> TT;
	while (TT--)
		solve();
	
	return 0;
}

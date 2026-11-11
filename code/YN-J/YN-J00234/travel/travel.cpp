#include <bits/stdc++.h>
using namespace std;
#define freopen(io) freopen(io".in", "r", stdin), freopen(io".out", "w", stdout)

string c1, s1, c2, s2;

signed main()
{
	freopen("travel");
	cin.tie(0)->sync_with_stdio(0);
	cin >> c1 >> s1 >> c2 >> s2;
	short ans = (c1 == c2);
	cout << ans;
	ans &= (s1[0] == s2[0] && s1[1] == s2[1]);
	cout << ans;
	ans &= ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] > 'C' && s2[2] > 'C'));
	cout << ans;
	ans &= (s1[2] - s2[2] == 1 || s1[2] - s2[2] == -1);
	cout << ans;
}
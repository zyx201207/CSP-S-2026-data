#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef DEBUG
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
#endif
	cin.tie(0)->sync_with_stdio(0);

	int c1, c2, l1, l2;
	char n1, n2;

	cin >> c1 >> l1 >> n1 >> c2 >> l2 >> n2;

	bitset<4> ans;

	ans[3] = (c1 == c2);
	ans[2] = (l1 == l2) && ans[3];
	ans[1] = (!(n1 > 'C' && n2 < 'D' || n1 < 'D' && n2 > 'C')) && ans[2];
	ans[0] = (abs(n1 - n2) == 1 || n1 == 'D' && n2 == 'F' || n1 == 'F' && n2 == 'D') && ans[1];

	cout << ans << endl;

	return 0;
}
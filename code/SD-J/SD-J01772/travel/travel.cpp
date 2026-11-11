#include<bits/stdc++.h>
using namespace std;
bool ans[10];
signed main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	string ca, sa, cb, sb;
	cin >> ca >> sa >> cb >> sb;
	if (ca != cb)
	{
		cout << "0000";
		return 0;
	}
	else
		ans[1] = 1;
		
	if (sa[0] == sb[0] && sa[1] == sb[1])
		ans[2] = 1;
	else
		ans[2] = 0;
		
	if (ans[2] == 1 && ((sa[2] <= 'C' && sb[2] <= 'C') || (sa[2] >= 'D' && sb[2] >= 'D')))
		ans[3] = 1;
	else
		ans[3] = 0;
		
	if (sa > sb) swap(sa, sb);
	if (ans[3] == 1 && ((sb[2] <= 'C' && sb[2] == sa[2] + 1) || (sa[2] == 'D' && sb[2] == 'F')))
		ans[4] = 1;
	else
		ans[4] = 0;
		
	for (int i = 1; i <= 4; i ++)
		cout << ans[i];
	return 0;
}

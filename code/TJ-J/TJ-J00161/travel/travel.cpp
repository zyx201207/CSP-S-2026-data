#include <bits/stdc++.h>
#define int long long

using namespace std;

string cr, sr, cx, sx, ans = "0000";
void fast()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
}
signed main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	fast();
	cin>>cr>>sr>>cx>>sx;
	if (cr == cx)
	{
		ans[0] = '1';
		if (sr[0] == sx[0] && sr[1] == sx[1])
		{
			ans[1] = '1';
			if (sr[2] == 'A' || sr[2] == 'B' || sr[2] == 'C') 
				if (sx[2] == 'A' || sx[2] == 'B' || sx[2] == 'C')
					ans[2] = '1';
			if (sr[2] == 'D' || sr[2] == 'F')
				if (sx[2] == 'D' || sx[2] == 'F')
					ans[2] = '1';
			if ((sr[2] == 'A' && sx[2] == 'B') || (sr[2] == 'B' && sr[2] == 'C') || (sr[2] == 'B' && sr[2] == 'A') || (sr[2] == 'C' && sx[2] == 'B') || (sr[2] == 'D' && sx[2] == 'F') || (sr[2] == 'F' && sx[2] == 'D'))
				ans[3] = '1';	
		}
	}
	cout<<ans;
	return 0;
}
//100pts(?£© 

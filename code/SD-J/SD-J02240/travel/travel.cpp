#include <bits/stdc++.h>
using namespace std;
string cr, sr, cx, sx;
string ans = "";
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r", stdin);
	freopen("travel.out","w", stdout);
	cin >> cr >> sr;
	cin >> cx >> sx;
	if (cr == cx) 
	{
		if ((sx[0] == sr[0] && sx[1] == sr[1]))
		{
			if (sr[2] == 'C' && sx[2] == 'D') ans = "1100";
			else 
			{
				int rr = sr[2] - 'A', xx = sx[2] - 'A';
				if (abs(rr - xx) == 1)
					ans = ans + "1111";
				else if ((rr == 0 && xx == 2) || (rr == 2 && xx == 0)) 
					ans = ans + "1110";
				else 
					ans = ans + "1100";
	 		} 
		}
		else
			ans = "1000";
	}
	else
		ans = "0000";
	cout << ans << endl;
	return 0;
}

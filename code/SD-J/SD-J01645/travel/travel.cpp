#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cr,cx,sr,sx,dp;
	cin >> cr >> sr >> cx >> sx;
	if( cr == cx )
	{
		dp = dp + '1';
		if( sr[0] == sx[0] && sr[1] == sx[1] )
		{
			dp = dp + '1';
			if( ( ( sr[2] == 'A' || sr[2] == 'B' || sr[2] == 'C' ) && ( sx[2] == 'A' || sx[2] == 'B' || sx[2] == 'C' ) ) || ( ( sr[2] == 'D' || sr[2] == 'F' ) && ( sx[2] == 'D' || sx[2] == 'F' ) ) ) 
			{
				dp = dp + '1';
				if( ( sr[2] == 'A' && sx[2] == 'B' ) ||
					( sr[2] == 'B' && sx[2] == 'A' ) ||
					( sr[2] == 'B' && sx[2] == 'C' ) ||
					( sr[2] == 'C' && sx[2] == 'B' ) ||
					( sr[2] == 'D' && sx[2] == 'F' ) ||
					( sr[2] == 'F' && sx[2] == 'D' )
				)
				{
					dp = dp + '1';
				}else dp = "1110";
			}else dp = "1100";
		}else dp = "1000"; 
	}else dp = "0000";
	cout << dp;
	return 0;
}

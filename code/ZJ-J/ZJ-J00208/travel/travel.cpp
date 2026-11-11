#include <bits/stdc++.h>
using namespace std;
int tcr,tcx,ttr,ttx,tlr,tlx,txr,txx;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cr,sr,cx,sx;
	cin >> cr >> sr >> cx >> sx;
	
	if(cr[0] == '0')	tcr = (cr[1] - '0');
	else	tcr = (cr[1] - '0') + 10;
	if(cx[0] == '0')	tcx = (cx[1] - '0');
	else	tcx = (cx[1] - '0') + 10;
	if(tcr != tcx)
	{
		cout << "0000";
		return 0;
	}
	else
	{
		cout << "1";
	}
	
	if(sr[0] == '0')    ttr = (sr[1] - '0');
	else    ttr = (sr[1] - '0') + 10;
	if(sx[0] == '0')    ttx = (sx[1] - '0');
	else    ttx = (sx[1] - '0') + 10;
	if(ttr != ttx)
	{
		cout << "000";
		return 0;
	}
	else
	{
		cout << "1";
	}
	
	if(sr[2] >= 'A' && sr[2] <= 'C' && sx[2] >= 'A' && sx[2] <= 'C')
	{
		cout << "1";
		if(sr[2] == 'B')
		{
			cout << "1";
			return 0;
		}
		else if(sx[2] == 'B')
		{
			cout << "1";
			return 0;
		}
		else
		{
			cout << "0";
		}
	}
	else if(sr[2] >= 'D' && sr[2] <= 'F' && sx[2] >= 'D' && sx[2] <= 'F')
	{
		cout << "11";
		return 0;
	}
	else
	{
		cout << "00";
		return 0;
	}
	return 0;
}

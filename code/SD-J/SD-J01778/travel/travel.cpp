#include<bits/stdc++.h>
using namespace std;
string cr,cx,sr,sx;
int main() 
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","a",stdout);
	cin >> cr >> cx >> sr >> sx;
	if(cr[0] == sr[0])
	{
		cout << 1;
		if(cx[0]==sx[0]&&cx[1] == sx[1])
		{
			cout << 1;
			if(cx[2] <= 'C'&&sx[2] > 'C' || sx[2] <= 'C'&&cx[2] > 'C')
			{
				cout << "00";
			}
			else
			{ 
				cout << 1;
				if(cx[2]-1==sx[2]||cx[2]+1==sx[2])
				{
					cout << 1;
				}
				else
				{
					cout << 0;
				}
			}
		}
		else
		{
			cout <<"000";
		}
		
	}
	else
	{
		cout << "0000";
	}
	return 0;
}

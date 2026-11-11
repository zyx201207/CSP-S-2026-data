#include <bits/stdc++.h>
using namespace std;
int r,x;
string rs,xs;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin >> r >> rs >> x >> xs;
	if (r==x)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	if (r==x)
	{
		if (rs[0]==xs[0] && rs[1]==xs[1])
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
		if (rs[0]==xs[0] && rs[1]==xs[1])
		{
			if (rs[2]<'D' && xs[2]<'D' || rs[2]>'E' && xs[2]>'E')
			{
				cout << 1;
			}
			else
			{
				cout << 0;
			}
			if (rs[2]<'D' && xs[2]<'D' || rs[2]>'E' && xs[2]>'E')
			{
				if (max(rs[2],xs[2])-min(rs[2],xs[2])==1)
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
			cout << "00";
		}
	}
	else
	{
		cout << "000";
	}
	return 0;
}

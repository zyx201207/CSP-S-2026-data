#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string rc,rs,xc,xs;
	cin >> rc >> rs >> xc >> xs;
	if (rc[0]==xc[0] && rc[1]==xc[1])
	{
		if (rs[0]==xs[0] && rs[1]==xs[1])
		{
			if ((rs[2]<='C'&&xs[2]<='C') || (rs[2]>='D'&&xs[2]>='D'))
			{
				if ((rs[2]=='A'&&xs[2]=='C') || rs[2]=='C'&&xs[2]=='A')
				{
					cout << "1110";
				}
				else cout << "1111";
			}
			else cout << "1100";
		}
		else cout << "1000";
	}
	else cout << "0000";
	return 0;
}

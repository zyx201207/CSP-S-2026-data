#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout,tie(0);
	int x,y;
	string xx,yy;
	cin>>x>>xx>>y>>yy;
	if(x==y)
	{
		if(x>1 && x<16 && y>1 && y<16)
		{
			cout<<1;
			if(xx[0]==yy[0] && xx[1]==yy[1])
			{
				cout<<1;
				if(xx[2]=='A')
				{
					if(yy[2]='8')
					{
						cout<<11;
						return 0;
					}
					else if(yy[2]='C')
					{
						cout<<10;
						return 0;
					}
					else 
					{
						cout<<0<<0;
						return 0;
					}
				}
			}
		}
	}
}

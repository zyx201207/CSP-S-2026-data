#include<bits/stdc++.h>
using namespace std;
int cx,cy;
string sx,sy;
int a[6]={1,1,1,2,2};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cx>>sx>>cy>>sy;
	if(cx==cy)
	{
		cout<<"1";
		if(((sy[0]-'0')*10+(sy[1]-'0'))==(sx[0]-'0')*10+(sx[1]-'0'))
		{
			cout<<"1";
			if(a[sy[2]-'A']==a[sx[2]-'A'])
			{
				cout<<"1";
				if(abs((sx[2]-'A')-(sy[2]-'A'))==1)
				{
					cout<<"1";
				}
				else
				{
					cout<<"0";
				}
			}
			else
			{
				cout<<"00";
			}
		}
		else
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}
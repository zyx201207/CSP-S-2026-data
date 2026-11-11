//100
#include<bits/stdc++.h>
using namespace std;
string cx,sx,cy,sy;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>cx>>sx>>cy>>sy;
	if(cx==cy)
	{
		cout<<1;
		if(sx[0]==sy[0]&&sx[1]==sy[1])
		{
			cout<<1;
			if((sx[2]>='A'&&sx[2]<='C'&&sy[2]>='A'&&sy[2]<='C')||(sx[2]>='D'&&sx[2]<='F'&&sy[2]>='D'&&sy[2]<='F'))
			{
				cout<<1;
				bool a=(sx[2]=='A'||sy[2]=='A');
				bool b=(sx[2]=='B'||sy[2]=='B');
				bool c=(sx[2]=='C'||sy[2]=='C');
				bool d=(sx[2]=='D'||sy[2]=='D');
				bool f=(sx[2]=='F'||sy[2]=='F');
				if((a&&b)||(b&&c)||(d&&f))
				{
					cout<<1;	
				}	
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
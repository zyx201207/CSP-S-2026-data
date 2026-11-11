#include <bits/stdc++.h>
#define int long long
using namespace std;
string a,b,c,d;
signed main()
{
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		cout<<1;
		char temp1=b[0];
		char temp2=b[1];
		char temp3=d[0];
		char temp4=d[1];
		if(temp1==temp3 && temp2==temp4)
		{
			cout<<1;
			if((b[2]=='A' && d[2]=='B') || (b[2]=='A' && d[2]=='C') || (b[2]=='B' && d[2]=='A') || (b[2]=='B' && d[2]=='C') || (b[2]=='A' && d[2]=='A') || (b[2]=='B' && d[2]=='B') || (b[2]=='C' && d[2]=='A') || (b[2]=='C' && d[2]=='B') || (b[2]=='C' && d[2]=='C') || (b[2]=='D' && d[2]=='F') || (b[2]=='D' && d[2]=='D') || (b[2]=='F' && d[2]=='D') || (b[2]=='F' && d[2]=='F'))
			{
				cout<<1;
				if((b[2]=='A' && d[2]=='B') || (b[2]=='B' && d[2]=='A') || (b[2]=='B' && d[2]=='C') || (b[2]=='C' && d[2]=='B') || (b[2]=='D' && d[2]=='F') || (b[2]=='F' && d[2]=='D'))
				{
					cout<<1;
					return 0;
				}
				else
				{
					cout<<0;
					return 0;
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
			return 0;
		} 
	}
	else 
	{
		cout<<"0000";
		return 0;
	}
	return 0;
}

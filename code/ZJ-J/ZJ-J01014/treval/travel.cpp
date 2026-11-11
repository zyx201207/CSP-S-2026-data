#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
		string a1,a2;
		a1=s1[0]+s1[1];
		a2=s2[0]+s2[1];
		if(a1==a2)
		{
			cout<<1;
			char x,y;
			x=s1[2];
			y=s2[2];
			if(x<'D' && y<'D' || x>'C' && y>'C')
			{
				cout<<1;
				if(int(abs(x-y))==1)
				{
					cout<<1;
				}
				else
				{
					cout<<0;
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

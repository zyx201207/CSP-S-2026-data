#include<bits/stdc++.h>
using namespace std;
string r,r1,x,x1;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r>>r1>>x>>x1;
	if(r==x)
	{
		cout<<1;
		if(r1[0]==x1[0]&&x1[1]==r1[1])
		{
			cout<<1;
			bool r2=r1[2]!='D'&&r1[2]!='F',x2=x1[2]!='D'&&x1[2]!='F';
			if(r2==x2)
			{
				cout<<1;
				if(!r2)
				{
					cout<<1;
				}else
				{
					if(r1[2]=='B'||x1[2]=='B')
					{
						cout<<1;
					}else
					{
						cout<<0;
					}
				}
			}else
			{
				cout<<0<<0;
			}
		}else
		{
			cout<<"000";
		}
	}else
	{
		cout<<"0000";
	}
	return 0;
}

//西安市高新第二初级中学 八年级16班 SN-J01170 杨博 
#include<bits/stdc++.h>
using namespace std;
string cr,sr;
string cx,sx;
char ar,ax;
int pr,px;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx)
	{
		cout<<1;
		pr=10*(sr[0]-'0')+(sr[1]-'0');
		px=10*(sx[0]-'0')+(sx[1]-'0');
		if(pr==px)
		{
			cout<<1;
			ar=sr[2];
			ax=sx[2];
			if(ar>='D'&&ax>='D')
			{
				cout<<1;
				if(int(ar)-int(ax)==1||int(ar)-int(ax)==-1)
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
			}
				else if(ar<'D'&&ax<'D')
				{
					cout<<1;
					if(int(ar)-int(ax)==1||int(ar)-int(ax)==-1)
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
				cout<<0<<0;
			}
		}
		else
		{
			cout<<0<<0<<0;
		}
	}
	else
	{
		cout<<0<<0<<0<<0;
	}
	return 0;
}

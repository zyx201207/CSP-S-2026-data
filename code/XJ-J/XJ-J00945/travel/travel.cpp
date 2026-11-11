#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string rc,rs,xc,xs;
	char r,x;
	cin>>rc>>rs>>xc>>xs;
	r=rs[2];
	x=xs[2];
	if(!(rc==xc))
	{
		cout<<"0000";
	}
	else
	{
		cout<<"1";
		if((rs[0]==xs[0])&&(rs[1]==xs[1]))
		{
			cout<<"1";
			if(!(((r=='A'||r=='B'||r=='C')&&(x=='A'||x=='B'||x=='C'))||((r=='D'||r=='F')&&(x=='D'||x=='F'))))
			{
				cout<<"00";	
			}
			else
			{
				cout<<1;
				if((r=='A'&&x=='B')||(r=='B'&&x=='A')||(r=='B'&&x=='C')||(r=='C'&&x=='B')||(r=='D'&&x=='F')||(r=='F'&&x=='D'))
				{
					cout<<"1";
				}
				else
				{
					cout<<"0";
				}
			}
		}
		else
		{
			cout<<"000";
		}
	}
	return 0;
}
	
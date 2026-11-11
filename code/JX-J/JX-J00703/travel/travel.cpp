#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	char x,y;
	cin>>c1>>s1>>c2>>s2;
	x=s1[2];
	y=s2[2];
	if(c1==c2)
	{
		cout<<1;
		if(s1[0]==s2[0] && s1[1]==s2[1])
		{
			cout<<1;
			if(((x=='D' || x=='E') && (y=='D' || y=='E')) || ((x=='A' || x=='B' || x=='C') && (y=='A' || y=='B' || y=='C')))
			{
				cout<<1;
				if(x=='A' && y=='B')
				{
					cout<<1;
				}
				else if(x=='B' && (y=='A' || y=='C'))
				{
					cout<<1;
				}
				else if(x=='C' && y=='B')
				{
					cout<<1;
				}
				else if(x=='D' && y=='E')
				{
					cout<<1;
				}
				else if(x=='E' && y=='D')
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
}          

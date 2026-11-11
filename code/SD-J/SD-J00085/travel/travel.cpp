#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1;
	string s2;
	string c1;
	string c2;
	cin>>c1>>s1>>c2>>s2;
	int a=s1[0];
	int b=s1[1];
	int c=s2[0];
	int d=s2[1];
	char e=s1[2];
	char f=s2[2];
	if(c1==c2)
	{
		
		cout<<1;
		if(a==c&&b==d)
		{
			cout<<1;
			if(e<='C'&&f<='C')
			{
				cout<<1;
				if(abs(e-f)==1&&e+f!='I')
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
			}
			else if(e>'C'&&f>'C')
			{
				cout<<1;
				if(abs(e-f)==1&&e+f!='I')
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

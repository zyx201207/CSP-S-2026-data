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
	int a=0,b=0;
	a=(c1[0]-'0')*10+c1[1]-'0';
	b=(c2[0]-'0')*10+c2[1]-'0';
	if(a==b)
	{
		cout<<'1';
		int c=0,d=0;
		c=(s1[0]-'0')*10+(s1[1]-'0');
		d=(s2[0]-'0')*10+(s2[1]-'0');
		if(c==d)
		{
			cout<<'1';
			char e,f;
			e=s1[2];
			f=s2[2];
			if(e<='C'&&f<='C')
			{
				cout<<'1';
				if(e-f==1||e-f==-1)
				{
					cout<<'1';
					return 0;
				}
				else
				{
					cout<<'0';
					return 0;
				}
			}
			else if(e>'C'&&f>'C')
			{
				cout<<'1';
				if(e-f==1||e-f==-1)
				{
					cout<<'1';
					return 0;
				}
				else
				{
					cout<<'0';
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
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	froopen("travel.out","w",stdout);
	int sr,sx;
	string c1,s1,c2,s2;
	char nr,nx;
	cin>>c1>>s1>>c2>>s2;
	sr=(s1[0]-'0')*10+s1[1]-'0';
	sx=(s2[0]-'0')*10+s2[1]-'0';
	nr=s1[2];
	nx=s2[2];
	if(c1!=c2)
	{
		cout<<"0000";
	}
	else if(sr!=sx)
	{
		cout<<"1000";
	}
	else if(nr>='A'&&nr<='C'&&nx>='A'&&nx<='C'||nr>='D'&&nr<='F'&&nx>='D'&&nx<='F')
	{
		if(nr>='D'&&nr<='F'&&nx>='D'&&nx<='F')
		{
			cout<<"1111";
		}
		else
		{
			if(nr=='B'||nx=='B')
			{
				cout<<"1111";
			}
			else
			{
				cout<<"1110";
			}
		}
	}
	else
	{
		cout<<"1100";
	}
	return 0;	
}

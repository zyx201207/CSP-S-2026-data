#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	string f="";
	cin>>a>>b>>c>>d;
	if (a==c)
	{
		f+='1';
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if (b[0]==d[0]&&b[1]==d[1])
	{
		f+='1';
	}
	else
	{
		cout<<"1000";
		return 0;
	}
	int y=b[2];		//A=65
	int z=d[2];
	if ((y<=67&&z>=68)||(z<=67&&y>=68))
	{
		cout<<"1100";
		return 0;
	}
	else
	{
		f+='1';
	}
	if (y-z==-1||y-z==1)
	{
		cout<<"1111";
	}
	else
	{
		if (y>=68&&z>=68)
		{
			cout<<"1111";
		}
		else
		{
			cout<<"1110";
		}
	}	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
string rc,rs,xc,xs;
bool f=false;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>rs>>xc>>xs;
	if(rc==xc)
	{
		cout<<1;
		f=true;
	}
	else
	{
		cout<<0;
	}
	if(rs[0]==xs[0]&&rs[1]==xs[1]&&f==true)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(rs[0]==xs[0]&&rs[1]==xs[1]&&f==true)
	{
		if(rs[2]=='A'||rs[2]=='B'||rs[2]=='C')
		{
			if(xs[2]=='A'||xs[2]=='B'||xs[2]=='C')
			{
				cout<<1;
			}
			else
			{
				cout<<0;
			}
		}
		else{
			if(xs[2]=='D'||xs[2]=='E')
			{
				cout<<1;
			}
			else
			{
				cout<<0;
			}
		}
	}
	else
	{
		cout<<0;
	}
	if(rs[0]==xs[0]&&rs[1]==xs[1]&&f==true)
	{
		if(rs[2]=='A'&&xs[2]=='B')
		{
			cout<<1;
		}
		else if(rs[2]=='c'&&xs[2]=='B')
		{
			cout<<1;
		}
		else if(rs[2]=='B'&&xs[2]=='A')
		{
			cout<<1;
		}
		else if(rs[2]=='B'&&xs[2]=='C')
		{
			cout<<1;
		}
		else if(rs[2]=='F'&&xs[2]=='D')
		{
			cout<<1;
		}
		else if(rs[2]=='D'&&xs[2]=='F')
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
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

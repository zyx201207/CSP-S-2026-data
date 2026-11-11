#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a,b;
	string c;
	string d;
	int f,e,r1=0,r2=0;
	cin>>f>>c>>e>>d;
	a=c[2];
	b=d[2];
	r1=c[0]*10+c[2];
	r2=d[0]*10+c[2];
	
	
	if(f==e)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	if(r1==r2)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	
if((a=='F'||a=='D')||(b=='F'||b=='D'))
{
	if((b=='F'||b=='D')&&(a=='F'||a=='D'))
		{
		cout<<1;
		
	}
	else
	{
		cout<<0<<0;
		return 0;
	}
}
else
{
	cout<<1;
}
	if((a-'A')-(b-'A')==1||(b-'A')-(a-'A')==1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	
	return 0;
}
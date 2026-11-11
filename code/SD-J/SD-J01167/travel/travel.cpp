#include<bits/stdc++.h>
using namespace std;
int c1,s1,c2,s2;
char a,b;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d%c %d %d%c",&c1,&s1,&a,&c2,&s2,&b);
	if(c1!=c2)
	{
		cout<<0<<0<<0<<0;
		return 0;
	}	
	else
	{
		cout<<1;
	}
	if(s1!=s2)
	{
		cout<<0<<0<<0;
		return 0;
	}
	else
	{
		cout<<1;
	}
	int r=0,x=0;
	if(a=='F'||a=='D')
	{
		r=1;
	}
	else if(b=='F'||b=='D')
	{
		x=1;
	}
	if(r==x)
	{
		cout<<1;
	}
	else
	{
		cout<<0<<0;
		return 0;
	}
	if((a=='C'&&b=='A')||a=='A'&&b=='C')
	{
		cout<<0;
	}
	else
	{
		cout<<1;
	}
	return 0;
}


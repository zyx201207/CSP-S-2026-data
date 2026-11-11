#include<bits/stdc++.h>
using namespace std;
int x1,c;string x2,y2;
struct node
{
	int a;string b;
}s[2];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %s %d %s",&s[0].a,&s[0].b,&s[1].a,&s[1].b);
	if(s[0].a==s[1].a)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	x1=(s[0].b[0]-'0')*10+(s[0].b[1]-'0');
	x2=s[0].b[2];
	c=(s[1].b[0]-'0')*10+(s[1].b[1]-'0');
	y2=s[1].b[2];
	if(x1==c)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(x2=="A"&&y2=="B"||x2=="A"&&y2=="C"||x2=="B"&&y2=="A"||x2=="B"&&y2=="C"||x2=="C"&&y2=="A"||x2=="C"&&y2=="B"||x2=="D"&&y2=="F"||x2=="F"&&y2=="D")
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
		if(x2=="A"&&y2=="B"||x2=="B"&&y2=="A"||x2=="B"&&y2=="C"||x2=="C"&&y2=="B"||x2=="D"&&y2=="E"||x2=="E"&&y2=="D")
		cout<<1;
		else
		cout<<0;
			
	return 0;
}
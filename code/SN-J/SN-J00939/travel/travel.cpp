#include<bits/stdc++.h>
using namespace std;
struct node
{
	string c,s;
};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	node a1,a2;
	bool c=1;
	cin>>a1.c>>a1.s>>a2.c>>a2.s;
	if(a1.c==a2.c)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
		c=0;
	}
	if(a1.s[0]==a2.s[0]&&a1.s[1]==a2.s[1])
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
		c=0;
	}
	if(a1.s[2]<='C'&&a2.s[2]<='C'||a1.s[2]>='D'&&a2.s[2]>='D')
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
		c=0;
	}
	if((a1.s[2]-a2.s[2])!=1&&(a2.s[2]-a1.s[2])!=1)
	{
		c=0;
	}
	if(c)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	return 0;
}

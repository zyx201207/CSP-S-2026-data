#include<bits/stdc++.h>
using namespace std;
int a,b,flag=0;
string x,y;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>x>>b>>y;
	if(a==b&&flag==0)
	{
		cout<<1;
	}
	else 
	{
		cout<<0;
		flag=1;
	}
	if(x[0]==y[0]&&x[1]==y[1]&&flag==0)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		flag=1;
	}
	if((x[2]<='C'&&y[2]<='C'||x[2]>='D'&&y[2]>='D')&&flag==0)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		flag=1;
	}
	if(abs(x[2]-y[2])==1&&flag==0)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		flag=1;
	}
	return 0;
}

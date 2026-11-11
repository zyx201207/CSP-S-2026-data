#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	bool flag;
	flag=true;
	if((a[1]==c[1])&&(a[0]==c[0]))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		flag=false;
	}
	if((b[0]==d[0])&&(b[1]==d[1])&&flag==true)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		flag=false;
	}
	if((((b[2]<='C')&&(d[2]<='C'))||((b[2]>='D')&&(d[2]>='D')))&&flag==true)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
		flag=false;
	}
	bool flag1;
	flag1=true;
	if((b[2]=='A'&&d[2]=='C')||(b[2]=='C'&&d[2]=='A'))
	{
		flag1=false;
	}
	if((flag==true)&&(flag1==true))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
    return 0;
}

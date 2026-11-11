#include<bits/stdc++.h>
using namespace std;
#define int long long
bool checkce(char a,char b)
{
	if(a>='A'&&a<='C'&&b>='A'&&b<='C')
	{
		return 1;
	}
	if(a>='D'&&a<='E'&&b>='D'&&b<='E')
	{
		return 1;
	}
	return 0; 
}
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2; 
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	else
	{
		cout<<1;
	}
	char zuo1=s1[2],zuo2=s2[2];
	if(zuo1=='F') zuo1='E';
	if(zuo2=='F') zuo2='E';
	if(s1[0]!=s2[0]||s1[1]!=s2[1])
	{
		cout<<"000";
		return 0;
	}
	else
	{
		cout<<1;
	}
	if(!checkce(zuo1,zuo2))
	{
		cout<<"00";
		return 0;
	}
	else
	{
		cout<<1;
	}
	if(zuo2-zuo1==1||zuo1-zuo2==1)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}

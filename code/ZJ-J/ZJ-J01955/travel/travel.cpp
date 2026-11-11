#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	ll flag=0;
	if(c1==c2)
	{
		cout<<1;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])
	{
		cout<<1;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	int bi=(s1[2]-'0')-(s2[2]-'0');
	int s11=s1[2]-'A';
	int s22=s2[2]-'A';
	int f=0;
	if(s11<=2&&s22>=3||s11>=3&&s22<=2)
	{
		cout<<"00";
		return 0;
	}
	else if(s1[0]==s2[0])
	{
		cout<<1;
	}
	if(abs(bi)==1&&(s11==2)&&(s22!=3)||(s11==3)&&(s22==2))
	{
		cout<<1;
		return 0;
	}
	else if(s11==0||s11==1||s11==4)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define endl '\n'
using namespace std;
string c1,s1,c2,s2;
int a,b,c,d;
bool x=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	a=(c1[0]-'0')*10+c1[1]-'0';
	c=(c2[0]-'0')*10+c2[1]-'0';
	b=(s1[0]-'0')*10+(s1[1]-'0')*10+s1[2]-'A'+1;
	d=(s2[0]-'0')*10+(s2[1]-'0')*10+s2[2]-'A'+1;
	if(a==c)
	{
		cout<<"1";
		x=1;
	}
	else
	{
		x=0;
	}
	if(x==0)
	{
		cout<<"0000";
		return 0;
	}
	if(b/10==d/10)
	{
		cout<<"1";
		x=1;
	}
	else
	{
		x=0;
	}
	if(x==0)
	{
		cout<<"000";
		return 0;
	}
	if((b%10>=1&&b%10<=3&&d%10>=1&&d%10<=3)||(b%10>=4&&b%10<=5&&d%10>=4&&d%10<=5))
	{
		cout<<"1";
		x=1;
	}
	else
	{
		x=0;
	}
	if(x==0)
	{
		cout<<"00";
		return 0;
	}
	if(abs(b%10-d%10)==1&&(b%10!=3&&c%10!=4)&&(b%10!=4&&c%10!=3))
	{
		cout<<"1";
		x=1;
	}
	else
	{
		x=0;
	}
	if(x==0)
	{
		cout<<"0";
		return 0;
	}
	return 0;
}

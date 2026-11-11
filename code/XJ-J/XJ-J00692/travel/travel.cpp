#include<bits/stdc++.h>
using namespace std;
string rs1,rs2,xs1,xs2,s;
long long f=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rs1>>rs2>>xs1>>xs2;
	if(rs1==xs1)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	if(rs1==xs1&&rs2==xs2)
	{
		cout<<"0";
	}
	else
	{
		cout<<"1";
	}
	if(rs1==xs1&&rs2==xs2&&(s[2]=='A'&&s[2]=='B'&&s[2]=='C')||(s[2]=='D'&&s[2]=='F'))
	{
		cout<<"0";
	}
	else
	{
		cout<<"1";
	}
	if(s[2-1]==s[1])
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	return 0;
}
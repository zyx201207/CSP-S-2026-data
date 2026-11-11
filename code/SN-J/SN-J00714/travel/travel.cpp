#include<bits/stdc++.h>
using namespace std;
bool check(char R,char X)
{
	if((R=='F'&&X=='D')||(R=='D'&&X=='F'))
	{
		return 1;
	}
	if(R>='A'&&R<='C'&&X>='A'&&X<='C')
	{
		return 1;
	}
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,t,ss,tt;
	cin>>s>>t>>ss>>tt;
	int n=(s[0]-'0')*10+s[1]-'0';
	int m=(ss[0]-'0')*10+ss[1]-'0';
	char R=t[2];
	char X=tt[2];
	int r=(t[0]-'0')*10+t[1]-'0';
	int x=(tt[0]-'0')*10+tt[1]-'0';
	int r1=0,r2=0,r3=0,r4=0;
	if(n==m)
	{
		r1=1;
	}
	if(n==m&&r==x)
	{
		r2=1;
	}
	if(n==m&&r==x&&check(R,X))
	{
		r3=1;
	}
	if(n==m&&r==x&&check(R,X)&&abs(R-X)==1)
	{
		r4=1;
	}
	printf("%d%d%d%d",r1,r2,r3,r4);
	return 0;
}


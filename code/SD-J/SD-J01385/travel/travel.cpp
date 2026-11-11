#include<bits/stdc++.h>
#define int long long
using namespace std;

string c1,s1,c2,s2;
bool flag=false;
bool c=false;

signed main()
{
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2) printf("1");
	else
	{
		printf("0000");
		return 0;
	}
	
	if(s1[0]==s2[0]&&s1[1]==s2[1]) printf("1");
	else
	{
		printf("000");
		return 0;
	}
	
	if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C') printf("1");
	else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')
	{
		printf("1");
		flag=true;
	}
	else
	{
		printf("00");
		return 0;
	}
	
	if(flag==true) 
	{
		printf("1");
		return 0;
	}
	if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F'))
	{
		printf("1");
	}
	else
	{
		printf("0");
	}
	
	return 0;
}

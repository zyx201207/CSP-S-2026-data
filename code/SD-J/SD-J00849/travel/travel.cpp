#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) printf("1");
	else
	{
		printf("0000");
		return 0;
	}
	int a1=(s1[0]-'0')*10+s1[1]-'0';
	int a2=(s2[0]-'0')*10+s2[1]-'0';
	if(a1==a2) printf("1");
	else
	{
		printf("000");
		return 0;
	}
	if(s1[2]=='A'&&s2[2]=='B') printf("1");
	else if(s1[2]=='B'&&s2[2]=='A') printf("1");
	else if(s1[2]=='A'&&s2[2]=='C') printf("1");
	else if(s1[2]=='C'&&s2[2]=='A') printf("1");
	else if(s1[2]=='B'&&s2[2]=='C') printf("1");
	else if(s1[2]=='C'&&s2[2]=='B') printf("1");
	else if(s1[2]=='D'&&s2[2]=='F') printf("1");
	else if(s1[2]=='F'&&s2[2]=='D') printf("1");
	else
	{
		printf("00");
		return 0;
	}
	if(s1[2]=='A'&&s2[2]=='B') printf("1");
	else if(s1[2]=='B'&&s2[2]=='A') printf("1");
	else if(s1[2]=='B'&&s2[2]=='C') printf("1");
	else if(s1[2]=='C'&&s2[2]=='B') printf("1");
	else if(s1[2]=='D'&&s2[2]=='F') printf("1");
	else if(s1[2]=='F'&&s2[2]=='D') printf("1");
	else printf("0");
	return 0;
}

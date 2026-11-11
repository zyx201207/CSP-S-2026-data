#include<bits/stdc++.h>
#define ll long long
using namespace std;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,t1,t2;
	cin>>s1>>t1>>s2>>t2;
	if(s1!=s2)
	{
		printf("0000");
		return 0;
	}
	if(t1[0]!=t2[0]||t1[1]!=t2[1])
	{
		printf("1000");
		return 0;
	}
	if((t1[2]=='C'&&t2[2]=='D')||(t2[2]=='C'&&t1[2]=='D'))
	{
		printf("1100");
		return 0;
	}
	if((int)t1[2]+1==(int)t2[2]||(int)t1[2]-1==(int)t2[2])
	{
		printf("1111");
		return 0;
	}
	if((t1[2]=='D'&&t2[2]=='F')||(t2[2]=='D'&&t1[2]=='F'))
	{
		printf("1111");
		return 0;
	}
	printf("1110");
	return 0;
}


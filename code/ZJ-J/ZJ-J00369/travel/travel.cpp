#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ret;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0] && c1[1]==c2[1])
	{
		ret[0]='1';
	}
	else
	{
		ret[0]='0';
	}
	ret=ret;
	if(ret[0]=='1' && s1[0]==s2[0] && s1[1]==s2[1])
	{
		ret[1]='1';
	}
	else
	{
		ret[1]='0';
	}
	ret=ret;
	if(ret[1]=='1' && ((s1[2]<='C' && s2[2]<='C') || (s1[2]>='D' && s2[2]>='D')))
	{
		ret[2]='1';
	}
	else
	{
		ret[2]='0';
	}
	ret=ret;
	if(ret[2]=='1' && (abs(s1[2]-s2[2])==1 || (s1[2]=='D' && s2[2]=='F') || (s1[2]=='F' && s2[2]=='D')))
	{
		ret[3]='1';
	}
	else
	{
		ret[3]='0';
	}
	for(int i=0;i<4;i++) cout<<ret[i];
	return 0;
} 

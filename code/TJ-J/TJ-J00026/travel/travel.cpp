#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1[1]==s3[1])
		cout<<1;
	else
	{
		cout<<0<<0<<0<<0;
		return 0;
	}
		
	//同一车厢 
	if(s2[1]==s4[1])
		cout<<1;
	else
	{
		cout<<0<<0<<0;
		return 0;
	}
		
	//同一排 
	 if(s2[2]=='A' && s4[2]=='B' || s2[2]=='B' && s4[2]=='C' || s2[2]=='D' && s4[2]=='F')
	{
		cout<<1<<1;
	}
	else if(s2[2]=='B' && s4[2]=='A' || s2[2]=='C' && s4[2]=='B' || s2[2]=='F' && s4[2]=='D')
	{
		cout<<1<<1;
	}
	else
		cout<<0<<0;
	//同一侧 及 相邻 
	return 0;
} 

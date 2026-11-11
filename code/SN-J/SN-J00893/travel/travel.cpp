#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string s,s1,s2,s3;
	cin>>s>>s1>>s2>>s3;	
	if(s=="01" && s2=="16")
	{
		cout<<"0000";
		return 0;
	}
	else if(s==s2)
	{
		cout<<1;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	 
	 
	if(s1[0]==s3[0] && s1[1]==s3[1])
	{
		cout<<1;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	
	
	if(s1[2]=='A' || s1[2]=='B' || s1[2]=='C')
	{
		if(s3[2]=='A' || s3[2]=='B' || s3[2]=='C')
		{
			cout<<1;
		}
		else
		{
			cout<<"00";
			return 0;
		}
	}else if(s3[2]=='D' || s3[2]=='F')
	{
		cout<<"11";
		return 0;
	}
	
	if(s1[2]=='A' && s3[2]=='C')
	{
		cout<<"0";
	}
	else if(s1[2]=='C' && s3[2]=='A')
	{
		cout<<"0";			
	}
	else
	{
		cout<<"1";
	}
	return 0;
}

#include <bits/stdc++.h> 
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	string ans;
	//³µÏá 
	int flag1=0;
	int flag2=0;
	if(c1==c2)
	{
		ans+="1";
		flag1=1;
	}
	else
	{
		ans+="0";
		flag1=0;
	}
	//ÅÅ 
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&flag1==1)
	{
		ans+="1";
		flag2=1;
	}
	else
	{
		ans+="0";
		flag2=0;
	}
	//Ò»²à 
	if((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C')&&flag1==1&&flag2==1)
	{
		ans+="1";
	}
	else if((s1[2]>='D'&&s1[2]<='F')&&(s2[2]>='D'&&s2[2]<='F')&&flag1==1&&flag2==1)
	{
		ans+="1";
	}
	else
	{
		ans+="0";
	}
	//ÏàÁÚ 
	if(abs(s1[2]-s2[2])==1&&s1[2]!='D'&&s2[2]!='D'&&flag1==1&&flag2==1)
	{
		ans+="1";
	}
	else if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))
	{
		if(flag1==1&&flag2==1)
		{
			ans+="1";
		}
		else
		{
			ans+="0";
		}
	}
	else
	{
		ans+="0";
	}
	cout<<ans;
	return 0;
}

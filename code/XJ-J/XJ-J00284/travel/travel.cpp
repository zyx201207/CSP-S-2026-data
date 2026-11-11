#include<bits/stdc++.h>
using namespace std;
string ans="";
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	int f=0,f1=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		ans+='1';
	}
	else
	{
		ans+='0';
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&c1==c2)
	{
		ans+='1';
		f1=1;
	}
	else
	{
		ans+='0';
	}
	if(s1[2]=='D')
	{
		if(s2[2]=='F'&&s1[0]==s2[0]&&f1)
		{
			ans+='1';
			f=1;
		}
	}
	else if(s2[2]=='D')
	{
		if(s1[2]=='F'&&s1[0]==s2[0]&&f1)
		{
			ans+='1';
			f=1;
		}
	}
	else if(s1[2]=='C')
	{
		if((s2[2]=='A'||s2[2]=='B')&&f1)
		{
			ans+='1';
			f=1;
		}
	}
	else if(s2[2]=='C')
	{
		if((s1[2]=='A'||s1[2]=='B')&&f1)
		{
			ans+='1';
			f=1;
		}
	}
	else if(s2[2]=='F')
	{
		if(s1[2]=='D'&&s1[0]==f1)
		{
			ans+='1';
			f=1;
		}
	}
	else if(s1[2]=='F')
	{
		if(s2[2]=='D'&&f1)
		{
			ans+='1';
			f=1;
		}
	}
	else if(s1[2]=='B')
	{
		if((s2[2]=='A'||s2[2]=='C')&&f1)
		{
			ans+='1';
			f=1;
		}
	}
	else if(s2[2]=='B')
	{
		if((s1[2]=='A'||s1[2]=='C')&&f1)
		{
			ans+='1';
			f=1;
		}
	}
	else if(s1[2]=='A')
	{
		if((s2[2]=='B'||s2[2]=='C')&&f1)
		{
			ans+='1';
			f=1;
		}
	}
	else if(s2[2]=='A')
	{
		if((s1[2]=='B'||s1[2]=='C')&&f1)
		{
			ans+='1';
			f=1;
		}
	}
	else
	{
		ans+='0';
	}
	if(f&&abs(s1[2]-'0'+s1[2]-'0'-s1[2]-'0'+s2[2]-'0')==1)
	{
		ans+='1';
	}
	else
	{
		ans+='0';
	}
	if(ans.size()<4)
	{
		cout<<ans+'0';
		return 0;
	}
	cout<<ans;
	return 0;
} 
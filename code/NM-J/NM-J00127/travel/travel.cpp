#include <iostream>
#include <string>
using namespace std;
bool a(string c1,string c2);
bool b(string c1,string c2,string s1,string s2);
bool c(string c1,string c2,string s1,string s2);
bool d(string c1,string c2,string s1,string s2);
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1;
	string s1;
	string c2;
	string s2;
	string s;
	cin>>c1>>s1>>c2>>s2;
	if(a(c1,c2)==true) s[1]='1';
	else s[1]='0';
	if(b(c1,c2,s1,s2)==true) s[2]='1';
	else s[2]='0';
	if(c(c1,c2,s1,s2)==true) s[3]='1';
	else s[3]='0';
	if(d(c1,c2,s1,s2)==true) s[4]='1';
	else s[4]='0';
	for(int j=1;j<=4;j++)
	{
		cout<<s[j];
	}
	return 0;
}
bool a(string c1,string c2)
{
	int sum=0;
	for(int i=1;i<=sizeof(c1);i++)
	{
		if(c1[i]==c2[i])
		{
			sum++;
		}
	}
	if(sum==sizeof(c1))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool b(string c1,string c2,string s1,string s2)
{
	if(a(c1,c2)==false)
	{
		return false;
	}
	int sum=0;
	for(int g=1;g<=sizeof(s1)-1;g++)
	{
		if(s1[g]==s2[g])
		{
			sum++;
		}
	}
	if(sum==sizeof(s1)-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool c(string c1,string c2,string s1,string s2)
{
	if(b(c1,c2,s1,s2)==false)
	{
		return false;
	}
	int t=sizeof(s1);
	if(s1[t]<='c'&&s2[t]<='c')
	{
		return true;
	}
	else if(s1[t]>='d'&&s2[t]>='d')
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool d(string c1,string c2,string s1,string s2)
{
	if(c(c1,c2,s1,s2)==false)
	{
		return false;
	}
	int t=sizeof(s1);
	if(s1[t]+1==s2[t]||s1[t]-1==s2[t])
	{
		return true;
	}
	else
	{
		return false;
	}
}

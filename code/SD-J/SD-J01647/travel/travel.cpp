#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int ans1=0,ans2=0;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<c1.size();i++)
	{
		if(c1[i]!=c2[i])
		{
			cout<<"0000";
			return 0;
		}
	}
	cout<<"1";
	for(int i=0;i<s1.size();i++)
	{
		if(s1[i]>='0'&&s1[i]<='9')
		{
			ans1=ans1*10+(s1[i]-'0');
		}
	}
	for(int i=0;i<s2.size();i++)
	{
		if(s2[i]>='0'&&s2[i]<='9')
		{
			ans2=ans2*10+(s2[i]-'0');
		}
	}
	if(ans1!=ans2)
	{
		cout<<"000";
		return 0;
	}
	cout<<"1";
	int len1=s1.size()-1,len2=s2.size()-1;
	if(s1[len1]=='A'||s1[len1]=='B'||s1[len1]=='C')
	{
		if(s2[len2]=='D'||s2[len2]=='F')
		{
			cout<<"00";
			return 0;
		}
	}
	else if(s1[len1]=='D'||s1[len1]=='F')
	{
		if(s2[len2]!='D'&&s2[len2]!='F')
		{
			cout<<"00";
			return 0;
		}
	}
	cout<<"1";
	if(s1[len1]=='A'&&s2[len2]=='B')
	{
		cout<<"1";
	}
	else if(s1[len1]=='B'&&(s2[len2]=='A'||s2[len2]=='C'))
	{
		cout<<"1";
	}
	else if(s1[len1]=='C'&&s2[len2]=='B')
	{
		cout<<"1";
	}
	else if(s1[len1]=='D'&&s2[len2]=='F')
	{
		cout<<"1";
	}
	else if(s1[len1]=='F'&&s2[len2]=='D')
	{
		cout<<"1";
	}
	else
	{
		cout<<0;
	}
	return 0;
}

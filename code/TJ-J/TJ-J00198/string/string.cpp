#include <bits/stdc++.h>
using namespace std;
char m[1000000000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int p=0;
		char a;
		cin>>p>>a;
		for(int j=1;j<=p;j++)
		{
			s+=a;
		}
	}
	int ll=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]==s[i+1])
		{
			ll=1;
		}
		else if(s[i]!=s[i+1])
		{
			ll=0;
			break;
		}
		
	}
	if(ll==1)
	{
		cout<<0;
		return 0;
	}	
	for(int i=0;i<s.size();i++)
	{
		m[i]=s[i];
	}
	for(int i=0;i<s.size()/2;i++)
	{
		for(int j=s.size();j>s.size()/2;j--)
		{
			
			if(s[i]!=s[j])
			{
				s[j]=s[i];
			}
		}
	}
	int pp=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=m[i])
		{
			pp++;
		}
	}
	cout<<pp;
	return 0;
}
	

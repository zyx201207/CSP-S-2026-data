#include <bits/stdc++.h>
using namespace std;
long long int x,y,n,k=0,ans=0;string s1,s2;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		char c;
		int x;
		cin>>x>>c;
		for(int j=0;j<x;j++)
		{
			s1+=c; 
		}
	}
	x=s1.length()/2,y=s1.length();
	for(int i=0;i<x;i++)
	{
		s2+=s1[i];
	}
	if(s1.length()%2==1)
	{
		for(int i=y-1;i>x;i--)
		{
			if(s2[k]!=s1[i])
			{
				ans++;
			}
			k++;
		}
	}
	else
	{
		for(int i=y-1;i>x-1;i--)
		{
			if(s2[k]!=s1[i])
			{
				ans++;
			}
			k++;
		}
	}
	cout<<ans;
	return 0;
 } 

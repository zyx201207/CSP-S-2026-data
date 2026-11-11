#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[10005],ans=0;
	string s,b[10005];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		for(int i=1;i<=a[i];i++)
		{
			s+=b[i];
		}
	}
	string s1,s2;
	for(int i=s.length()/2;i>=0;i--)
	{
		s1+=s[i];
	}
	for(int i=s.length()/2;i<=s.length();i++)
	{
		s2+=s[i];
	}
	for(int i=1;i<=s.length()/2;i++)
	{
		if(s1[i]!=s2[i])
		{
			ans++;
		}
		
	}
	
	cout<<ans;
	return 0;
}
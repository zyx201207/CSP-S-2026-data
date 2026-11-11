#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int a[200040],n,ans=0;
	char w[200040];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>w[i];
		for(int j=0;j<a[i];j++)
			s=s+w[j];
	}
	string l1=s;
	for(int i=0;i<s.length();i++)
	{
		s[i] = s[n+1-i];
	}
	for(int i=0;i<n;i++)
	{
		if(l1[i]!=s[i])
			ans++;
	}
	cout<<ans;
	return 0;
}
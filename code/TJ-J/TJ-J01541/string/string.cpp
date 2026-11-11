#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long a[200000];
	char b[200000];
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>b[i];
	}
	bool q=1;
	string s,s1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			s+=b[i];
		}
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=a[i];j++)
		{
			s1+=b[i];
		}
	}
	if(s==s1)
	{
		cout<<0;
	}
	else
	{
		for(int i=1;i<=n/2;i++)
		{
			if(a[i]>=a[n-i+1])
			{
				ans+=a[i];
			}
			else
			{
				ans+=a[n-i+1];	
			}
		}
		cout<<ans;
	}
	
	return 0;
}

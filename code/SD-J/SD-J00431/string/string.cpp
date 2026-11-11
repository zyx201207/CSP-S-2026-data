#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int a[maxn];
char b[maxn];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	long long l=0;
	for(int i=1;i<=n;i++)
	{
		l+=a[i];
	}
	if(n==1)
	{
		cout<<0;
	}
	else if(n==2)
	{
		if(b[1]!=b[2])
		{
			cout<<min(a[1],a[2]);
		}
		else
		{
			cout<<0;
		}
	}
	else
	{
		string s="";
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=a[i];j++)
			{
				s+=b[i];
			}
		}
		for(int i=0;i<s.size()/2;i++)
		{
			if(s[i]!=s[s.size()-i])
			{
				ans++;
			}
		}
		cout<<ans;
	}	
	return 0;
} 

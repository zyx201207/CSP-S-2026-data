#include<bits/stdc++.h>
using namespace std;
int n;
int l=1;
long long m;
long long a[100005];
char c[100005];
char s[100005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long p=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		m+=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			s[l++]=c[i];
		}
	}
	if(m%2==0)
	{
		for(int i=1;i<=n/2;i++)
		{
			if(s[i]!=s[m-i+1])
			{
				p++;
			}
		}
	}
	else
	{
		for(int i=1;i<=n-1/2;i++)
		{
			if(s[i]!=s[m-i+1])
			{
				p++;
			}
		}	
	}
	cout<<p;
	return 0;
}

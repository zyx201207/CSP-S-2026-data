#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0,num=0;
	cin>>n;
	long long a[n+1];
	string s[n+1];
	for (int i=1;i<=n;i++)
	{
		cin>>a[i]>>s[i];
		sum+=a[i];
	}	
	int b=1,d=n,x;
	string y;
	bool z;
	if (n%2==0)
	{
		for (int i=1;i<=n/2;i++)
		{
			if (i!=1&&y!="kl")
			{
				if (z)
				{
					if (s[d]!=y)
					{
						num+=x;
					}
					a[d]-=x;
				}
				else
				{
					if (s[b]!=y)
					{
						num+=x;
					}
					a[b]-=x;
				}
			}
			if(s[b]!=s[d])
			{
				num+=min(a[b],a[d]);
				x=max(a[b],a[d])-min(a[b],a[d]);
				if (a[b]>a[d])
				{
					z=1;
					y=s[b];
				}
				else if(a[b]<a[d])
				{
					z=0;
					y=s[d];
				}
				else
				{
					y="kl";
				}
			}
			d--;
		}
	}
	else
	{
		for (int i=1;i<=n/2+1;i++)
		{
			if (i!=1&&y!="kl")
			{
				if (z)
				{
					if (s[d]!=y)
					{
						num+=x;
					}
					a[d]-=x;
				}
				else
				{
					if (s[b]!=y)
					{
						num+=x;
					}
					a[b]-=x;
				}
				if (i==n/2+1)
				{
					continue;
				}
			}
			if(s[b]!=s[d])
			{
				num+=min(a[b],a[d]);
				x=max(a[b],a[d])-min(a[b],a[d]);
				if (a[b]>a[d])
				{
					z=1;
					y=s[b];
				}
				else if(a[b]<a[d])
				{
					z=0;
					y=s[d];
				}
				else
				{
					y="kl";
				}
			}
			d--;
		}
	}
	cout<<num;
	return 0;
}

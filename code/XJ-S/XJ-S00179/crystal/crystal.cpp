#include<bits/stdc++.h>
using namespace std;
long long a[500005]={0},b[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,pan=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i]-a[i-1];
		if(b[i]==b[i-1])
		{
			pan++;
		}
	}
	if(pan>5000)
	{
		long long p=b[2],c=1;
		long long sum=m;
		for(int i=1;i<=n;i++)
		{
			if(sum-i*p>=0)
			{
				sum-=i*p;
				c++;
			}
		}
		cout<<c;
		return 0;
	}
	sort(a+1,a+n+1);
	
	int i;
	int maxn=1;
	for(int i=n;i>=maxn;i--)
	{
		long long sum=m,c=1;
		int j=i-1;
		while(1)
		{
			if(sum-(a[i]-a[j])>=0)
			{
				sum-=(a[i]-a[j]);
				c++;
				j--;
			}
			else
			{
				if(c>maxn)
				{
					maxn=c;
				}
				break;
			}
		}	
	}
	cout<<maxn;
	return 0;
}

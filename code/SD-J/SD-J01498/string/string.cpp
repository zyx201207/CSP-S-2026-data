#include <bits/stdc++.h>
using namespace std;
string s;
long long a[200005];
char c[200005];		
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long pos=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		pos+=a[i];
	}
	long long ans=0;
	pos/=2;
	long long sum=0,wei=0;
	long long x=0;
	char y;
	for(int i=1;i<=n;i++)
	{
		if(sum+a[i]>pos)
		{
			x=pos-sum;
			y=c[i];
			a[i]-=x;
			wei=i-1;
			if(pos%2==1)
			{
				a[i]--;
			}
			break;
		}
		else
		{
			sum+=a[i];
		}
	}
	sum=n;
	for(int i=1;i<=wei+1;i++)
	{
		if(i!=wei+1)
		{
		while(a[i]!=0)
		{
			if(a[i]>=a[sum])
			{
				if(c[i]!=c[sum])
				{
					ans+=a[sum];
				}
				a[i]-=a[sum];
				sum--;
			}
			else
			{
				a[sum]-=a[i];
				if(c[i]!=c[sum])
				{
					ans+=a[i];
				}
				break;
			}
		}
		}
		else
		{
			while(x!=0)
		{
			if(x>=a[sum])
			{
				if(y!=c[sum])
				{
					ans+=a[sum];
				}
				x-=a[sum];
				sum--;
			}
			else
			{
				a[sum]-=x;
				if(y!=c[sum])
				{
					ans+=x;
				}
				break;
			}
		}
		}
	}
	cout <<ans;
	return 0;
}

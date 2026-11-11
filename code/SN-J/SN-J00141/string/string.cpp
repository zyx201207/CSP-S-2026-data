#include <bits/stdc++.h>
using namespace std;
int a[100000000];
char c[100000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0;
	cin >> n;
	int mid=(1+n)/2;
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i] >> c[i];
	} 
	if(n==2)
	{
		if(c[1]==c[2])
		{
			cout << 0;
			return 0;
		}
		else
		{
			cout << min(a[1],a[2]);
			return 0;
		}
	}
	if(n%2==0)
	{
		for(int i = 1;i<=mid;i++)
		{
			if(c[i]==c[n-i+1])
			{
				if(a[i]==a[n-i+1])
				{
					continue;
				}
				else
				{
					if(a[i]>=a[n-i+1])
					{
						int tmp=a[i]-a[n-i+1];
						a[n-i+1]=a[i];
						a[n-i+1]-=tmp;
						sum+=tmp;
						continue;
					}
					else
					{
						int tmp=a[n-i+1]-a[i];
						a[i]=a[n-i+1];
						a[i+1]-=tmp;
						sum+=tmp;
						continue;
					}
				}
			}
			else
			{
				sum+=a[n-i+1];
				
			}
		}
	}
	else
	{
		for(int i = 1;i<mid;i++)
		{
			if(i==mid-1)
			{
				if(a[i]>=a[mid+1])
					{
						int tmp=a[i]-a[mid+1];
						sum+=2*tmp;
						continue;
					}
					else
					{
						int tmp=a[n-i+1]-a[i];
						sum+=2*tmp;
						continue;
					}
			}
			if(c[i]==c[n-i+1])
			{
				if(a[i]==a[n-i+1])
				{
					continue;
				}
				else
				{
					if(a[i]>=a[n-i+1])
					{
						int tmp=a[i]-a[n-i+1];
						a[n-i+1]=a[i];
						a[n-i+1]-=tmp;
						sum+=tmp;
						continue;
					}
					else
					{
						int tmp=a[n-i+1]-a[i];
						a[i]=a[n-i+1];
						a[i+1]-=tmp;
						sum+=tmp;
						continue;
					}
				}
			}
			else
			{
				sum+=a[n-i+1];
				
			}
		}
	}
	cout << sum;
	return 0;
}

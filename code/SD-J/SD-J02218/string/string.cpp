#include<iostream>
using namespace std;
long long a[100010];
char b[100010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,sum=0;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	long long l=1,r=n;
	while(l<r)
	{
		if(b[l]!=b[r])
		{
			if(a[l]>=a[r]) 
			{
				a[l]=a[l]-a[r];
				sum+=a[r];
				r--;
				if(a[l]==0)
				{
					l++;
				}
			}
			if(a[r]>a[l]) 
			{
				a[r]=a[r]-a[l];
				sum+=a[l];
				l++;
				if(a[r]==0)
				{
					r--;
				}
			}
		}
		else
		{
			if(a[l]>=a[r]) 
			{
				a[l]=a[l]-a[r];
				r--;
				if(a[l]==0)
				{
					l++;
				}
			}
			if(a[r]>a[l]) 
			{
				a[r]=a[r]-a[l];
				l++;
				if(a[r]==0)
				{
					r--;
				}
			}
			
		}
	}
	cout<<sum;
	return 0;
}

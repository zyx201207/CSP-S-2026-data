#include<bits/stdc++.h>
using namespace std;
long long n,a[200010];
unsigned long long num,l,r,sum,t;
char c[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		num=num+a[i];	
	}
	l=1;
	r=n;
	while(1)
	{
		if(c[l]!=c[r])
		{
			if(a[l]<a[r])
			{
				if(t+a[l]<=num/2)
				{
					t=t+a[l];
					sum=sum+a[l];
					a[r]=a[r]-a[l];
					l++;
				}
				else
				{
					cout<<sum+(num/2-t);
					return 0;
				}
			}
			else
			if(a[l]==a[r])
			{
				if(t+a[l]<=num/2)
				{
					t=t+a[l];
					sum=sum+a[l];
					l++;
					r--;
				}
				else
				{
					cout<<sum+(num/2-t);
					return 0;
				}
			}
			else
			if(a[l]>a[r])
			{
				if(t+a[r]<=num/2)
				{
					t=t+a[r];
					sum=sum+a[r];
					a[l]=a[l]-a[r];
					r--;
				}
				else
				{
					cout<<sum+(num/2-t);
					return 0;
				}
			}
		}
		else
		if(c[l]==c[r])
		{
			if(a[l]<a[r])
			{
				if(t+a[l]<=num/2)
				{
					t=t+a[l];
					a[r]=a[r]-a[l];
					l++;
				}
				else
				{
					cout<<sum;
					return 0;
				}
			}
			else
			if(a[l]==a[r])
			{
				if(t+a[l]<=num/2)
				{
					t=t+a[l];
					l++;
					r--;
				}
				else
				{
					cout<<sum;
					return 0;
				}
			}
			else
			if(a[l]>a[r])
			{
				if(t+a[r]<=num/2)
				{
					t=t+a[r];
					a[l]=a[l]-a[r];
					r--;
				}
				else
				{
					cout<<sum;
					return 0;
				}
			}
		}
		if(t==num/2)
		{
			cout<<sum;
			return 0;
		}
	}
	cout<<sum;
	return 0;
}
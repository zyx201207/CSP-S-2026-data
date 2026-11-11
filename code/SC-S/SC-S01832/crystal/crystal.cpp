#include<bits/stdc++.h>
using namespace std;
long long a[500002];
int main()
{
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out ","w",stdout);
	long long zd,t,zx=-100000000001;
	int n;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>zd;     
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]>a[j])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}	
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			t=0;
			if(a[j]-a[i]<=zd)
			{
				for(int k=i;k<=j;k++)
				{
					if(a[k]<a[j])
					{
						t=(a[j]-a[k])+t;
					}
				}
				if(t<=zd)
				{
					t=j-i+1;
				}
				else
				{
					t=0;
				}
			}
			if(t>zx)
			{
				zx=t;
			}
		}
	}
	cout<<zx;
	return 0;
 } 
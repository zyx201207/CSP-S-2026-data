#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long int a[N],c[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long int n,m,sum=0,k=1,ans=-1e9,q=0;
	cin>>n>>m;
	bool ww=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[i]=a[i]-a[i-1];
	}
	for(int i=2;i<=n;i++)
	{
		if(c[i]!=c[i-1])
		{
			ww=1;
		}
	}
	if(ww==0)
	{
		for(int i=1;i<=n;i++)
		{
			long long int q=i*(i+1)/2*c[1];
			if(q==m)
			{
				cout<<i;
				return 0;
			}
			if(q>m)
			{
				cout<<i-1;
				return 0;
			}
		}
	}
	else
	{
		for(long long int i=2;i<=n;i++)
		{
			sum=0;
			k=1;
			for(long long int j=i;j<=n;j++)
			{
				sum+=k*c[i];
				k++;
				long long p=0;
				if(sum>m)
				{
					for(int k=j;k<=n;k++)
					{
						if(a[k]==a[j-1])
						{
							p++;
						}
					}
					ans=max(ans,j-i+1+p);
					break;
				}
				if(sum==m)
				{
					for(int k=j+1;k<=n;k++)
					{
						if(a[k]==a[j])
						{
							p++;
						}
					}
					ans=max(ans,j-i+2+p);
					break;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
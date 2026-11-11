#include<bits/stdc++.h>
using namespace std;
int n,a[500005],sum[500005],cnt,flag1;
long long m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<n;i++)
	{
		if(n-i>cnt)
		{
			for(int j=i;j<=n;j++)
			{
				if(((sum[j]-sum[i-1]+m)/(j-i+1))>=a[j])
				{
					if((j-i+1)>=cnt)
					{
						cnt=j-i+1;
					}
				}
			}
		}
		else{
			cout<<cnt;
			return 0;
		}
	}
	cout<<cnt;
	return 0;
}

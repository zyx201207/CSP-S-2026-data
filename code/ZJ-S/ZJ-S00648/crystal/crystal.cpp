#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[205];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,maxn=-1,sum=0;
	cin>>n>>m;
	if(n<=16||n>5000)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		long long cha=a[2]-a[1],bei,flag=0,k=0,maxi;
		for(int i=1;i<=n;i++)
		{
			if(a[i+1]-a[i]!=0)
				flag=1;
		}
		if(flag==1)
		{
			sort(a+1,a+n+1);
			for(int i=-100;i<=100;i++)
			{
				k=0;
				sum=0;
				for(int j=n;j>=1;j--)
				{
					if(a[j]<=i&&sum+(i-a[j])<=m)
					{
						k++;
						sum=sum+(i-a[j]);
					}
				}
				if(maxn<k)
				{
					maxn=k;
					maxi=i;
				}
			}
		}
		else
		{
			for(int i=1;;i++)
			{
				bei=(i+1)*i/2;
				if(bei*cha>m)
				{
					cout<<i;
					return 0;
				}
			}
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+n+1);
		for(long long i=2;i<=n;i++)
		{
			sum=0;
			for(long long j=i-1;j>=1;j--)
			{
				sum+=(a[i]-a[j]);
				if(sum>m)
				{
					maxn=max(maxn,i-j);
					break;
				}
				if(j==1)
				{
					if(sum<=m)
						maxn=max(maxn,i-j+1);
					maxn=max(maxn,i-j);
				}
			}
		}
	}
	cout<<maxn;
	return 0;
}
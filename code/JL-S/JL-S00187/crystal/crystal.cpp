#include<bits/stdc++.h>
using namespace std;
long long s[500005],a[10005][10005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long c=1;
	long long n,m,sum=0,max=INT_MIN;
	cin>>n>>m;
	sort(s+1,s+n+1);
	for(long long i=1;i<=n;i++)
	{
		cin>>s[i];
		if(s[i]!=i) c=0;
	}
	if(c==1)
	{
		long long z;
		for(long long i=1;i<=n;i++)
		{
			sum=sum+i;
			if(sum>=m)
				break;
			else
				z=i;
		}
		cout<<z+1;
		return 0;
	}
	else if(n<=10000)
	{
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i;j<=n;j++)
			{
				a[i][j]=s[j]-s[i];
			}
		}
		for(long long i=1;i<=n;i++)
		{
			long long d=m;
			for(long long j=i;j>=1;j--)
			{
				d=d-a[j][i];
				if(d<0)break;
				else sum++;
			}
			if(sum>=max)
			{
				max=sum;
			}
			sum=0;
		}
		cout<<max<<endl;
		return 0;
	}
	else
	{
		long long ee=s[2]-s[1],z;
		for(int i=1;i<=n;i++)
		{
			sum=sum+i*ee;
			if(sum>=m)
				break;
			else
				z=i;
		}
		cout<<z+1;
		return 0;
	}
	return 0;
}

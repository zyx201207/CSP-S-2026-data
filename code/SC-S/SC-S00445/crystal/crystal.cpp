#include<bits/stdc++.h>
using namespace std;
long long n;
long long m;
long long a[5000005];
long long b[5000005];
long long ans[5000005];
long long num;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	ios::sync_with_stdio(false),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n>5000)
	{
		if(a[2]-a[1]==1)
		{
			long long p=0;
			for(long long i=1;i>0;i++)
			{
				p+=i;
				if(p>m)
				{
					num=i-1;
					i=-1;
				}
					
			}
			if(num>n)
				num==n;
			cout<<num;
			return 0;
		}
		else if(a[3]-a[2]==a[2]-a[1]&&a[5]-a[4]==a[4]-a[3])
		{
			long long p=0;
			for(long long i=1;i>0;i++)
			{
				p+=i*(a[2]-a[1]);
				if(p>m)
				{
					num=i-1;
				}
			}
			if(num>n)
				num=n;
			cout<<num;
			return 0;
		}
	}
	num=ans[1];
	long long cnt=0;//相同的数的个数 
	long long bj=0;//标记相同的数的第一个数的位置 
	for(long long i=1+ans[1];i<=n;i++)
	{
		if(a[i]==a[i+1])
		{
			cnt++;
			if(cnt==1)
			{
				bj=i;
			}
			continue;
		}
		if(cnt==0)
		{
			bj=i;
		}
		long long sum=0;
		for(int j=bj-1;j>=1;j--)
		{
			sum+=(a[i]-a[j]);
			if(sum>m)
			{
				j=0;
			}
			else if(sum==m)
			{
				ans[i]++;
				j=0;
			}
			else
			{
				ans[i]++;
			}
		}
		num=max(num,ans[i]+cnt+1);
		cnt=0;
	}
	cout<<num; 
	return 0;
}
#include<bits/stdc++.h>

using namespace std;

long long a[500005],b[500005];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,maxn=-1;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long l=1,r=1,now=0,nc=1,sum=0;
	while(l<=n&&r<=n)
	{
		if(now+(a[r+1]-a[r])*nc<=m)
		{
			long long j=2,sum=now;
			if(a[r+1]==a[r+j])
			{
				while(a[r+j]==a[r+1]&&r+j<=n)
				{
					j++;
				}
			}
			sum+=(a[r+1]-a[r])*nc;
			if(sum<=m)
			{
				r=r+j-1;
				if(r>n)
				{
					break;
				}
				now=sum;
				nc+=j-1;
				maxn=max(maxn,nc);
			}
			else
			{
				l+=1;
				nc-=1;
				now=sum-a[r]+a[l-1];
			}
		}
		else if(now+(a[r+1]-a[r])*nc>m)
		{
			l+=1;
			nc-=1;
			now=sum-a[r]+a[l-1];
		}
	}
	cout<<maxn;
	return 0;
}

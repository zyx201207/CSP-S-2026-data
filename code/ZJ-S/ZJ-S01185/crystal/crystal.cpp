#include<bits/stdc++.h>
using namespace std;
long long a[500007];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long l=1e12,r=-1e12,ans;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		l=min(a[i],l);
		r=max(a[i],r);
	}
	ans=r;
	long long c=0,cc=0;
	r+=(long long)(m/n);
	long long cnt=0,sna=ans;
	while(l<r)
	{
		c=0,cc=0;
		long long mid=(l+r)/2;
		for(int i=1;i<=n;i++)
		{
			if(a[i]<=mid)
			{
				c+=(mid-a[i]);
				cc++;
			}
		}
		if(c<=m)
		{
			cnt=max(cc,cnt);
		}
		
		if(c>=m)
		{
			r=mid;
			ans=mid;
			if(cc<cnt&&c<=m)
			{
				for(int i=sna;i<=mid;i++)
				{
					ans--;
					for(int j=1;j<=n;j++)
					{
						if(a[j]<=ans)
						{
							c+=(ans-a[j]);
							cc++;
						}
					}
					if(c<=m)
					{
						cnt=max(cc,cnt);
					}
				}
				break;
			}
			sna=ans;
		}
		else	
		{
			l=mid+1;
		}
	}
	cout<<cnt;
	return 0;
}
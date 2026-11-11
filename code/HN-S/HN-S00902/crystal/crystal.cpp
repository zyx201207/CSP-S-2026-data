#include<bits/stdc++.h>
using namespace std;
long long dp[5005][5005],n,m,a[500005],maxn=1,p,num=1,q,c;
long long cha(int x,int y)
{
	long long maxx=-1e18,sum=0;
	for(int i=x;i<=y;i++)
	{
		maxx=max(maxx,a[i]);
	}
	for(int i=x;i<=y;i++)
	{
		sum+=maxx-a[i];
		if(sum>m)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i>=2)
		{
			if(i==2)
			{
				c=a[i]-a[i-1];
				num++;
			}
			else
			{
				if(a[i]-a[i-1]==c&&q==1)
				{
					num++;
				}
				else
				{
					q=0;
				}
			}
		}
	}
	if(num==n)
	{
		maxn=0,q=1;
		while(maxn+q*c<=m)
		{
			maxn+=q*c;
			q++;
		}
		cout<<q;
		return 0;
	}
	for(int t=2;t<=n;t++)
	{
		for(int i=1;i+t-1<=n;i++)
		{
			int j=i+t-1;
			if(cha(i,j) && t>maxn)
			{
				maxn=t;
				break;
			}
		}
	}
	cout<<maxn;
	return 0;
} 

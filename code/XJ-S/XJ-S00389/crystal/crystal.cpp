#include<bits/stdc++.h>
using namespace std;
long long int a[100005],cost[100005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long int m,i,n,j,ans=-1,s,k;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(i=1;i<n;i++)
	{
		cost[i]=a[i+1]-a[i];
	}
	if(n<=5000)
	{	
		for(i=1;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				s=0;
				for(k=i;k<=j;k++)
				{
					s+=cost[k]*(k-i+1);
					if(s>m)
					{
						cout<<ans;
						return 0;
					}
				}
				if(s<=m&&j-i+2>ans)
				{
					ans=j-i+2;
				}
			}
		}
		cout<<ans;
		return 0;
	}
	else
	{
		if(cost[1]==1)
		{
			s=0;
			for(i=1;i<=n;i++)
			{
				s+=i;
				if(s>m)
				{
					cout<<i-1;
					return 0;
				}
			}
		} 
		else
		{
			s=0;
			for(i=1;i<=n;i++)
			{
				s+=cost[i]*i;
				if(s>m)
				{
					cout<<i;
					return 0;
				}
			}
		}
	}
	return 0;
}

//1
#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,a[510000];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int fA=0,fB=0,t=0;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=i) fA=1;
		if(i==2) t=a[i]-a[i-1];
		if(i>2 && a[i]-a[i-1]!=t) fB=1;
	}
	if(fA==0)
	{
		for(int i=1;i<=m;i++)
			if(m>=i)
			{
				m-=i;
				sum++;
			}
		cout<<sum+1;
		return 0;
	}
	if(fB==0)
	{
		while(m)
		{
			if(m>=t)
			{
				m-=t;
				sum++;
			}
			else break;
			if(sum==n-1) break;
		}
		cout<<sum+1;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		long long ans=m,cnt=0;
		for(int j=i-1;j>=1;j--)
			if(ans>=(a[i]-a[j]))
			{
				cnt++;
				ans-=(a[i]-a[j]);
			}
		sum=max(sum,cnt);
	}
	cout<<sum+1;
	return 0;
}
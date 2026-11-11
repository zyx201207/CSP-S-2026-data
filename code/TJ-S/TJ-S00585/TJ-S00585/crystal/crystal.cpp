#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],maxs=-1e18-1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--)
	{
		long long cnt=1,k=m;
		for(int j=i-1;j>=1;j--)
		{
			k-=(a[i]-a[j]);
			if(k>=0) cnt++;
			else break;
		}
		maxs=max(cnt,maxs);
		if(i<=maxs) 
		{
			cout<<maxs;
			return 0;
		}
	}
	return 0;
}

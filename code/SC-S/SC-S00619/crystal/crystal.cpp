#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=1,s[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=2;i<=n;i++)
	{
		s[i]=s[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	for(long long i=n;i>=2;i--)
	{
		long long l=1,r=i,gete;
		while(l<r)
		{
			long long mid=(l+r)/2;
			if(s[i]-s[mid]-(a[i]-a[mid])*(mid-1)<=m)
			{
				r=mid;
			}
			else l=mid+1;
		}
//		if(l==1)
//		{
//			ans=i;
//			break;
//		}
//		if(a[l]==a[l-1])l--;
//		cout<<i-l+1<<' '<<ans<<'\n';
		ans=max(ans,(long long)(i-l+1));
	}
	cout<<ans;
	return 0;
}
/*
5 2
-1 -1 -2 -2 -3
*/
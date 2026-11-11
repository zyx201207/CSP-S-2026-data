#include<bits/stdc++.h>
using namespace std;
long long n,m,inx,ans;
long long a[600007];
bool check(long long x)
{
	inx=1;
	long long sum=0;
	while(sum<=m&&a[inx]<x)
	{		
		sum+=(x-a[inx]);
		inx++;
	}
	while(a[inx]==x)
	{
		inx++;
	}
	if(sum>m)
	return false;
	ans=inx;
	return true;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long l=a[1],r=a[n];
	while(l<r)
	{
		long long mid=l+(r-l+1)/2;
//		cout<<mid<<" "<<l<<" "<<r<<" "<<endl;
		if(check(mid))
		{
			l=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<ans-1;
	return 0;
}

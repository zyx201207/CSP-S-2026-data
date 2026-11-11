#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fr(i,a,b) for(int i=a;i<=b;i++)
int a[500005];
int n,m,ans;

bool check(int x)
{
	int sum=0;
	fr(i,1,n)
	{
		if(a[i]<x)
			sum+=(x-a[i]);
	}
	return sum<=m;
}

signed main()
{
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
//	//二分答案
	cin>>n>>m;
	fr(i,1,n)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=a[1],r=a[n];
	while(l<=r)
	{
		int mid=(l+r)/2;//能量值变成mid
		if(check(mid))
		{
			l=mid+1;
			ans=mid;
		}
		else
			r=mid-1;
	}
//	cout <<ans;
	int sum=0;
	fr(i,1,n)
	{
		if(a[i]<=ans)
			sum++;
	}
	cout <<sum;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ch[500005],sum[500005],summ[500005],MAX=0;
bool check(long long w,long long x)
{
	if(sum[w]*x-(summ[w-1]-summ[w-x])<=m)
	{
		return 1;
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		ch[i]=a[i]-a[i-1];
	}
	for(int i=2;i<=n;i++)
	{
		sum[i]=sum[i-1]+ch[i];
	}
	for(int i=2;i<=n;i++)
	{
		summ[i]=summ[i-1]+sum[i];
	}
	for(int i=1;i<=n;i++)
	{
		long long l=1,r=i;
		while(l<=r)
		{
			long long mid=(l+r)/2;
			if(check(i,mid)==1)
			{
				MAX=max(MAX,mid+1);
				l=mid+1;
			}
			else
			{
				r=mid-1;
			}
		}
	}
	cout<<MAX;
	return 0;
}

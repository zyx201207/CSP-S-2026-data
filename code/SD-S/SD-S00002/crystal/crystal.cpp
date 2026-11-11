#include<iostream>
#include<algorithm>
using namespace std;
long long a[500005];
long long sum[500005];
bool check(int ans,long long m,int i)
{
	long long t=a[i]*ans;
	t-=(sum[i-1]-sum[i-ans-1]);
	return t<=m;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	sum[0]=0;
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	long long maxn=-1e18;
	for(int i=1;i<=n;i++)
	{
		long long l=0,r=i;
		while(l<r)
		{
			int mid=(l+r+1)/2;
			if(check(mid,m,i)&&i-mid>0)
			{
				l=mid;
			}
			else r=mid-1;
		}
		maxn=max(maxn,l+1);
	}
	cout<<maxn;
	return 0;
}
//rp++

#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;

long long a[N];
long long sum[N];
long long n,m;
long long cntans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+(a[i]-a[i-1])*(i-1);
	}
	long long cnt;
	cntans=0;
	for (int j=1;j<=n;j++)
	{
		cnt=0;
		long long l=j,r=n;
		while (l<=r)
		{
			long long mid=(l+r)/2;
			if (sum[mid]-sum[j]-(a[mid]-a[j])*(j-1)>m)
			{
				r=mid-1;
			}
			else
			{
				l=mid+1;
				cnt=mid-j+1;
			}
		}
		cntans=max(cnt,cntans);
	}
	cout<<cntans<<"\n";
	return 0;
}

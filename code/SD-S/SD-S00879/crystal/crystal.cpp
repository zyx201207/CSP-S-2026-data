#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
long long sum[N];
int n,m;
int idx;
bool check(int x)
{
	int fir=idx-x+1;
	int need=x*a[idx];
	if (fir<=0) return 0;
	if ((need-(sum[idx]-sum[fir-1]))<=m) return 1;
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	sum[0]=0;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	int maxn=0;
	for (int i=1;i<=n;i++)
	{
		int l=1,r=5e5;
		int ans=0;
		idx=i;
		while (l<=r)
		{
			int mid=(l+r)/2;
			if (check(mid))
			{
				l=mid+1;
				ans=max(ans,mid);
			}
			else r=mid-1;
		}
		maxn=max(maxn,ans);
    }
    cout<<maxn;
    return 0;
}

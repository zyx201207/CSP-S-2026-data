#include <bits/stdc++.h>
using namespace std;
long long a[500005],sum[500005],b[500005],bb[500005],ans[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1; i<= n; i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1; i<= n; i++)
	{
		if(i!=1)
		{
			b[i]=a[i]-a[i-1];
		}
		bb[i]=bb[i-1]+b[i];
	}
	int ii=1;
	for(int i = 1; i< n;)
	{
		int cnt=i-ii+1;
		while((1000000000000000000-sum[ii])/cnt>=b[i]&&(sum[ii]+b[i]*cnt<=m))
		{
			sum[ii]+=b[i]*cnt;
			i++;
			cnt++;
		}
		if(i>=n)
		{
			break;
		}
		cnt--;
		ans[ii]=i;
		ii++;
		sum[ii]=sum[ii-1]-(bb[i]-bb[ii]);
	}
	for(int i = ii; i<=n; i++)
	{
		ans[i]=n;
	}
	int maxn=0;
	for(int i = 1; i<= n; i++)
	{
		if(ans[i]-i+1>=maxn)
		{
			maxn=ans[i]-i+1;
		}
	}
	cout<<maxn;
	return 0;
}

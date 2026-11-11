#include<bits/stdc++.h>
using namespace std;
long long cnt,n,m,maxx=LLONG_MIN;
long long a[500005],sum[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool pd=false;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int ks=1;ks<n;ks++)
	{
		for(int i=ks;i<=n;i++)
		{
			cnt=(i-ks)*a[i]-(sum[i]-a[i]);
			if(cnt>m)
			{
				maxx=max((long long)i-ks,maxx);
				break;
			}
		}
	}
	cout<<maxx;
	return 0;
}

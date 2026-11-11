#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long qz[500010];
long long maxs=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	long long l=1,r=1;
	long long hf=0;
	while(r<=n)
	{
		while(hf>m)
		{
			hf-=(a[r]-a[l]);
			l++;
		}
		maxs=max(maxs,r-l+1);
		r++;
		hf+=(r-l)*(a[r]-a[r-1]);
	}
	cout<<maxs;
	return 0;
}


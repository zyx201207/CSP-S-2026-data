#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N];
int n,m;
bool check()
{
	for(int i=1;i<=n;i++) if(a[i]!=i) return 0;
	return 1;
}
bool check1()
{
	int k=a[2]-a[1];
	for(int i=2;i<n;i++) if(a[i+1]-a[i]!=k) return 0;
	return 1;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	if(check()||check1())
	{
		int i,sum=0;
		for(i=1;i<=n;i++)
		{
			sum+=a[i];
			if(sum>m) break;
		}
		printf("%lld",i);
	}
	else
	{
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		sort(a+1,a+1+n);
		for(int i=n;i>=1;i--)
		{
			int t=m;
			for(int j=i-1;j>=1;j--)
			{
				t-=(a[i]-a[j]);
				if(t<0) break;
			}
			if(t>=0) 
			{
				printf("%lld",i);
				return 0;
			}
		}
	}
	return 0;
}



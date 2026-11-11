#include <bits/stdc++.h>
using namespace std;
typedef long long i64;

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	i64 n, m;
	scanf("%lld%lld", &n, &m);
	vector<i64> a(n+10);
	for (i64 i=1; i<=n; ++i)
	{
		scanf("%lld", &a[i]);
	}
	
	if (n<=5000)
	{
		sort(a.begin()+1, a.begin()+n+1);
	
		i64 ans=0;
		for (i64 i=1; i<=n; ++i)
		{
			vector<i64> v(n+10);
			for(i64 j=i; j>=1; --j)
			{
				v[j] = v[j+1] + a[i]-a[j];
			}
			reverse(v.begin()+1, v.begin()+i+1);
			ans=max(ans, upper_bound(v.begin()+1, v.begin()+i+1, m)-v.begin()-1);
		}
		
		printf("%lld\n", ans);
	}
	else
	{
		i64 d1=a[2]-a[1];
		i64 d2=a[3]-a[2];
		if(d1==d2)
		{
			i64 d=d1;
			i64 num=m/d;
			i64 delta=1+8*num;
			double sqrt_delta=sqrt(double(delta));
			double ans=(sqrt_delta-1)/2;
			i64 ans_i=ans+1;
			printf("%lld\n", ans_i);
		}
	}
	return 0;
}

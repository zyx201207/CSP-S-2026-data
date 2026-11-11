#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
int n;
long long m,sum = 0,a[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	bool f = 1;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=3;i<=n;i++) f&=(a[i]-a[i-1])==(a[i-1]-a[i-2]);
	if(f&&n>5000)
	{
		printf("%d",(int)ceil(1.0*(m-a[1])/(a[2]-a[1])));
	}
	else
	{
		sort(a+1,a+n+1);
		int ans = -1e9;
		for(int i=1;i<=n;i++)
		{
			int cnt = 1,m2 = m;
			for(int j = i-1;j>=1;j--)
			{
				if(m2>=a[i]-a[j])
				{
					cnt++;
					m2 -= a[i]-a[j];
				}
			}
			ans = max(ans , cnt);
		}
		printf("%d",ans);
	}
	return 0;
 } 

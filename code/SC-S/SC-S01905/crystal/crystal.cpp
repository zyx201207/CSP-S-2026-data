#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int n;
long long m;
long long a[N];
long long dh[N];//dh[i] = hmax - h[i]

namespace Sub1//n^2
{
	long long pre[N];
	long long ans = 1ll;
	
	void Solve1()
	{
		pre[0] = 0ll;
		
		for(int i = 1; i <= n; i ++)
		{
			pre[i] = dh[i];
			pre[i] += pre[i - 1];
		}
		
		for(int l = 1; l <= n; l ++)
		{
			for(int r = l; r <= n; r ++)
			{
				long long len = (long long)r - (long long)l + 1ll;
				if(pre[r] - pre[l - 1] - len * (a[n] - a[r]) <= m)
				{
					ans = max(ans, len);
				}
			}
		}
		
		printf("%lld", ans);
		
		return;
	}
}

namespace SubAB
{
	void Solve2()
	{
		long long d = a[2] - a[1];
		int ans = 1;
		
		for(int i = 1; i <= n; i ++)
		{
			long long num = ((long long)i) * ((long long)i - 1ll) / 2ll;
			if(d * num <= m)
			{
				ans = i;
			}
		}
		
		printf("%d", ans);
		
		return;
	}
}

bool checkAB = true;

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	scanf("%d%lld", &n, &m);
	for(int i = 1; i <= n; i ++)
	{
		scanf("%lld", &a[i]);
	}
	
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i ++)
	{
		dh[i] = a[n] - a[i];
	}
	
	for(int i = 2; i <= n - 1; i ++)
	{
		if(a[i] + a[i] != a[i - 1] + a[i + 1])
		{
			checkAB = false;
			break;
		}
	}
	
	if(n <= 5000)
	{
		Sub1 :: Solve1();
	}
	else if(checkAB)
	{
		SubAB :: Solve2();
	}
	
	return 0;
}
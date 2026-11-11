#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e5 + 10;

int s[N];
int qian[N];

bool cmp(int a , int b)
{
	return a < b;
}

signed main()
{
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	
	int n , m;
	scanf("%lld %lld" , &n , &m);
	for(int i = 1 ; i <= n ; i++)
	{
		scanf("%lld" , &s[i]);
	}
	sort(s + 1 , s + n + 1 , cmp);
	for(int i = 1 ; i <= n ; i++)
	{
		qian[i] = qian[i - 1] + s[i];
	}
	int ans = 1;
	for(int i = 2 ; i <= n ; i++)
	{
		int l = 1;
		int r = i - 1;
		while(l < r)
		{
			int mid = (l + r) >> 1;
			if(qian[i - 1] - qian[mid - 1] + m >= (i - mid) * s[i])
			{
				r = mid;
			}
			else
			{
				l = mid + 1;
			}
		}
		if(r == i - 1)
		{
			if(s[i - 1] + m >= s[i])
			{
				ans = max(ans , 2LL);
			}
			else
			{
				continue;
			}
		}
		else
		{
			ans = max(ans , i - r + 1);
		}
	}
	printf("%lld\n" , ans);

	return 0;
}

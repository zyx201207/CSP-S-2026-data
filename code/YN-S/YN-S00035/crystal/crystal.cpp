// File Memory Longlong Calm

#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10; 

int n;
long long m, a[N], pre[N];

long long sum(int l, int r)
{
	return a[r] * (r - l + 1) - pre[r] + pre[l-1];
}

int A_bound(int pos)
{
	int l = 1, r = pos, ans = pos;
	while(l <= r)
	{
		int mid = (l + r) / 2;
		if(sum(mid, pos) <= m) r = mid - 1, ans = mid;
		else l = mid + 1;
	}
	return ans;
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	scanf("%d %lld", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) pre[i] = pre[i-1] + a[i];
	int ans = 0;
	for(int i = 1; i <= n; i++) 
	{
//		int res = 0;
//		long long lst = m;
//		for(int j = i; j >= 1; j--)
//		{
//			if(lst >= a[i] - a[j])
//			{
//				lst -= a[i] - a[j];
//				res++;
//			}
//		}
//		if(res != i - A_bound(i) + 1)
//		{
//			printf("ERROR %d %lld %d %d\n", i, a[i], res, i - A_bound(i) + 1);
////			return -1;
//		}
		ans = max(ans, i - A_bound(i) + 1);
	}
	
	printf("%d\n", ans);
	
	return 0;
}

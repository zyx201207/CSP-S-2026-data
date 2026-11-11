#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
const int N = 5e5 + 5;
ll m;
ll arr[N];
ll dp[N];

bool check(int x)
{
	for(int i = 1; i + x - 1 <= n; i++) // 区间起点
	{
		bool flag = true; // 默认此次可能 
		int j = i + x - 1; // 区间终点
		ll sum = 0;
		for(int k = i; k <= j; k++) // 问题主要出在这里，O(n^2)的时复它接受不了 
		{
			sum += arr[j] - arr[k];
			if(sum > m)
			{
				flag = false;
				break;
			}
		}
		if(flag) return true;
	}
	return false;
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	for(int i = 1; i <= n; i++)
	{
		cin>>arr[i];
	}
	sort(arr + 1, arr + n + 1);
	if(n <= 5000)
	{
		// 正常解决 
		int l = 1, r = n; // 最多几颗水晶被弄到同一个数值 
		while(l < r)
		{
			int mid = (l + r + 1) / 2;
			if(check(mid)) // 可行
			{
				l = mid; 
			}
			else
			{
				r = mid - 1;
			}
		}
		cout<<l;
	}
	else
	{
		// 拿特殊样例分
		/*
		注意到A是B的特殊情况，考虑B应该如何解决。
		用O(1)求出公差d
		注意到若答案至少为 x，则 m >= x(x-1)d/2
		即按0d 1d 3d 6d 10d...增长
		反正x最大就5e5，用不用二分查找都无所谓
		*/
		ll d = arr[2] - arr[1];
		for(ll x = n; x >= 1; x--)
		{
			if(m >= 1ll * x * (x - 1) / 2 * d)
			{
				cout<<x;
				return 0;
			}
		}
	}
	return 0;
}
/*
应该没问题了，用这个代码去交应该可以拿到1-9以及13-18的分数，也就是75分（啊？？？） 
*/

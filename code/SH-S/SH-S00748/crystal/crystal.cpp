#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5;

int n, m, ans = 1, a[N], sum[N]; // 答案总是 >= 1 的 

bool check (int l, int r)
{
	int now = sum[r] - sum[l - 1]; // 实际上的和 
	int trg = a[r] * (r - l + 1); // 想要的和 
	return (trg - now) <= m; // 需要的操作次数不超过 m
	// 因为前面均 <= a[r]，所以不会出现要变小的违规情况 
}

signed main()
{
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	// 输入 
	sort (a + 1, a + n + 1); // 从小到大排序 
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i]; // 前缀和 
	for (int R = 1; R <= n; R++) // 枚举统一变成的数 
	{
		int l = 1, r = R, L = R; // 二分左端点（从 1 ~ R），不会 > R，因为没办法变小 
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (check (mid, R))	L = mid, r = mid - 1; // 如果 OK，往更小的找 
			else	l = mid + 1;
		}
		ans = max (ans, R - L + 1); // 取最大值 
	}
	cout << ans;
	return 0;	
} 

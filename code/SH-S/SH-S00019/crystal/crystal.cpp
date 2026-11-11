#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename _Tp1, typename _Tp2> inline bool chkmx(_Tp1&x, const _Tp2&y) {return x < y && (x = y, 1);}
constexpr int N = 5e5+9;
int n,ans;
ll m,a[N],s[N];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + a[i];
	for (int r = 1; r <= n; ++r)
	{
		int low = 1,high = r,res = 1;
		while (low <= high)
		{
			int mid = (low + high) >> 1;
			if (a[r] * mid - (s[r] - s[r - mid]) <= m) res = mid,low = mid + 1;
			else high = mid - 1;
		}
		chkmx(ans, res);
	}
	printf("%d\n", ans);
	return 0;
}
/*
我们孤身闯入这世界里
找寻名为宝藏的通关奖励
跃过深渊里迷人的金币
最后发现 珍贵是我和你
*/
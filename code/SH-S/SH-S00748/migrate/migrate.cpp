#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6 + 5, INF = 1e16;

bool flagA;
int c, T, n, d, ans, x[N], dp[N], mn[N], sum[N];

int jump (int pos)
{
	int l = pos, r = n, res = pos;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (x[mid] - x[pos] <= d)	res = mid, l = mid + 1;
		else	r = mid - 1;
	}
	return res;
}

int get_ed (int st, int pos)
{
	int a = pos, b = pos - 1, c = pos - 2;
	int l = pos + 1, r = n, mx = pos + 1; // mx : b 吃到的最远 
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (x[mid] - x[a] <= d && x[mid] - x[b] <= d)	mx = mid, l = mid + 1;
		else	r = mid - 1;
	}
	l = pos + 1, r = n; int mn = pos + 1; // mn : c 吃不到的最近（没有 c 无所谓） 
	if (c >= st)
	{
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (x[mid] - x[c] > d)	mn = mid, r = mid - 1;
			else	r = mid - 1;
		}
	}
	if (mn > mx)	return 0; // b 能吃到的最远，c 也能吃到 
	else	return mx - mn + 1; // 否则这一段区间均可 
}

void solve1()
{
	for (int st = 1; st <= n; st++) // 枚举开头 
	{
		int l = st, r = st;
		for (int i = 1; i <= n; i++)
			dp[i] = 0, mn[i] = INF, sum[i] = 0; // 初始化 
		mn[st] = 0, dp[st] = 1, sum[st] = 1; // 开头位置 
		for (int R = st + 1; R <= n; R++)
		{
			while (x[R] - x[l] > d)	l++; r = l; // 第一个可以跳到的位置 
			while (mn[r] == mn[l])	r++; r--; // 以后一个步数最小的位置 
			mn[R] = (l == R) ? INF : mn[l] + 1; // 最小步数 
			dp[R] = sum[r] - sum[l - 1]; // 所有方案 
			sum[R] = sum[R - 1] + dp[R]; // 累加前缀和 
			ans += (dp[R] == 2);
		}
	}
	cout << ans << "\n";
}

void solve2()
{
	// 所有的情况是同构的 
	int l = 1, r = 1;
	for (int i = 1; i <= n; i++)
		dp[i] = 0, mn[i] = INF, sum[i] = 0; // 初始化 
	mn[1] = 0, dp[1] = 1, sum[1] = 1; // 开头位置 
	for (int R = 2; R <= n; R++)
	{
		while (l < R && x[R] - x[l] > d)	l++; r = max (r, l); // 第一个可以跳到的位置 
		while (r <= R && mn[r] == mn[l])	r++; r--; // 以后一个步数最小的位置 
		mn[R] = (l == R) ? INF : mn[l] + 1; // 最小步数 
		dp[R] = sum[r] - sum[l - 1]; // 所有方案 
		sum[R] = sum[R - 1] + dp[R]; // 累加前缀和 
		if (dp[R] == 2)	ans += n - R + 1; // st + R - 1 <= n -> st <= n - R + 1
	}
	cout << ans << "\n";
}

void solve3() // len <= 2 
{
	for (int st = 1; st <= n; st++)
	{
		int pos = jump (st); // 找到最远的点 
		if (pos - st < 2)	continue; // 只有一个，不可能双径 
		ans += get_ed (st, pos); // 获得答案 
	}
}

void clear()
{
	ans = 0;
	flagA = true;
}

void mian()
{
	clear();
	cin >> n >> d;
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i];
		if (i > 2 && x[i] - x[i - 1] != x[i - 1] - x[i - 2])	flagA = false;
	}
	if (flagA)	solve2(); // 性质 A -> 8pts 
	else if (c == 13 || c == 14)	solve3(); // 性质 B -> 8pts 
	else	solve1(); // 40pts
}

signed main()
{
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> c >> T;
	while (T--)	mian();
	return 0;	
} 

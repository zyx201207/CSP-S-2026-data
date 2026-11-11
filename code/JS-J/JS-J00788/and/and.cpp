#include <bits/stdc++.h>
using namespace std;
const int MN = 2e5+7;
int n, m, a[MN], ans = INT_MIN;
bool flag = true, all_less_4 = true;
int cnt0_4[5];
void dfs(int depth, int now_and, int this_i)
{
	if (depth == m)
	{
		ans = max(ans, now_and);
		return ;
	}
	for (int i = this_i + 1; i <= n - (m - depth) + 1; i ++)
	{
		bool f = false;
		if (now_and == INT_MAX)
		{
			now_and = a[i];
			f = true;
		}
		dfs(depth + 1, now_and & a[i], i);
		if (f)
		{
			now_and = INT_MAX;
		}
	}
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];
		int temp = log2(a[i] + 1);
		if (pow(2, temp) - 1 != a[i])
		{
			flag = false;
		}
		if (a[i] > 4)
		{
			all_less_4 = false;
		}
    }
	if (n <= 20 || m == 2)
	{
		dfs(0, INT_MAX, 0);
		cout << ans;
		return 0;
	}
	if (all_less_4)
	{
		for (int i = 1; i<= n; i++)
		{
			cnt0_4[a[i]] ++;
		}
		if (cnt0_4[4] >= m)
		{
			cout << 4;
			return 0;
		}
		if (cnt0_4[3] >= m)
		{
			cout << 3;
			return 0;
		}
		if (cnt0_4[3] + cnt0_4[2] >= m)
		{
			cout << 2;
			return 0;
		}
		if (cnt0_4[3] + cnt0_4[1] >= m)
		{
			cout << 1;
			return 0;
		}
		cout << 0;
		return 0;
	}
	if (m == 1)
	{
		for (int i = 1; i <= n; i ++)
		{
			ans = max(a[i], ans);
		}
		cout << ans << endl;
		return 0;
	}
	if (m == n)
	{
		ans = a[1];
		for (int i = 2; i <= n; i ++)
		{
			ans &= a[i];
		}
		cout << ans;
		return 0;
	}
	if (flag)
	{
		sort(a + 1, a + n + 1);
		ans = a[n - m + 1];
		cout << ans << endl;
		return 0;
	}
	if (m == n - 1)
	{
		for (int i = 1; i<= m; i ++)
		{
			int tans = (i == 1) ? a[2] : a[1];
			for (int j = 1; j <= n; j ++)
			{
				if (j == i)
				{
					continue;
				}
				tans &= a[j];
			}
			ans = max(ans, tans);
		}
		cout << ans;
		return 0;
	}
	
    return 0;
}
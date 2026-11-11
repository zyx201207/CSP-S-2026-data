#include <bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = 5e5 + 5;

// 每次操作把一个元素+1，进行至多m次操作，求最多能让几个元素的值相等

// 45 分：排序之后把元素之间的差给算出来，然后暴力便利每个下表能跑多远，max记录 
// 特殊性质： 应该没问题了 
// 前缀和？ 

int n, m;
int a[maxn], b[maxn]; // b: 差值数组 
int ans = 1;

bool special = true;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 2 ; i <= n ; i++)
	{
		b[i] = a[i] - a[i - 1];
		if (b[i] != b[i - 1])
		{
			special = false;
		}
//		cout << b[i] << " ";
	}
//	cout << "\n";
	if (!special)
	{
		bool t = false;
//		cout << "test\n";
		for (int i = 2 ; i <= n ; i++)
		{
			int sum = 0;
			for (int j = i ; j <= n ; j++)
			{
				sum += b[j] * (j - i + 1); 
				if (sum > m)
				{
					ans = max(ans, j - i + 1);
//					cout << ans << " " << i << " " << j << " " << sum << '\n';
					t = true;
					break;
				}
			}
		}
		if (!t) cout << n;
	else
//		cout << "\n";
		cout << ans;
	}
	else if (special)
	{
		bool t = false;
//		cout << "test2\n";
		int sum = 0;
		for (int i = 1 ; i <= n ; i++)
		{
			sum += b[i] * i; 
			if (sum > m)
			{
				ans = i;
				t = true;
//				cout << ans;
//				cout << ans << " " << i << '\n';
				break;
			}
		}
		if (!t) cout << n;
	else
//		cout << "\n";
		cout << ans;
	}
	else
	{
		cout << ans;
	}
	
	return 0;
}

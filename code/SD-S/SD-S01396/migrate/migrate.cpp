#include<bits/stdc++.h>
using namespace std;
template < typename T > void read(T &Read_)
{
	bool f = 0; char ch = getchar(); Read_ = 0;
	while(!isdigit(ch)) { f |= (ch == '-'); ch = getchar(); }
	while(isdigit(ch)) { Read_ = Read_ * 10 + ch - '0'; ch = getchar(); }
	if(f) { Read_ = -Read_; }
}
template < typename T > void print(T Print_)
{
	char st[25]; int top = 0;
	if(Print_ < 0) { putchar('-'); Print_ = -Print_; }
	do { st[++top] = Print_ % 10 + '0'; Print_ /= 10; } while(Print_);
	while(top) { putchar(st[top--]); }
}
/*
migrate
16:20 理解题意
16:40 暴力 O(n ^ 3) 统计 x -> y 的最短路径条数，cnt[i][j] > 2 直接判掉 
17:30 瞪眼样例感觉没有什么好的结论 
17:40 思考等差数列 
*/
long long n , d;
long long a[2000005];
void solve_1()
{
	read(n);
	read(d);
	for(int i = 1 ; i <= n ; i++)
	{
		read(a[i]);
	}
	if(n == 1)
	{
		print(0);
		putchar('\n');
		return ;
	}
	long long D = a[2] - a[1];
	if(D >= d)
	{
		print(0);
		putchar('\n');
		return ;
	}
	long long L = (2 * d) / D;
	print(max(0ll , n - L + 1));
	putchar('\n');
}
long long dp[305][305];
long long cnt[305][305];
void solve()
{
	read(n);
	read(d);
	for(int i = 0 ; i <= n ; i++)
	{
		for(int j = 0 ; j <= n ; j++)
		{
			dp[i][j] = 1e9;
			cnt[i][j] = 0;
		}
	}
	for(int i = 1 ; i <= n ; i++)
	{
		read(a[i]);
		cnt[i][i] = 1;
	}
	for(int L = 1 ; L <= n ; L++)
	{
		for(int i = 1 ; i <= n - L + 1 ; i++)
		{
			int j = i + L - 1;
			if(a[j] - a[i] <= d)
			{
				dp[i][j] = 1;
				cnt[i][j] = 1;
				continue;
			}
			for(int k = i + 1 ; k < j ; k++)
			{
				dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k][j]);
			}
			for(int k = i + 1 ; k < j ; k++)
			{
				if(dp[i][k] + dp[k][j] == dp[i][j])
				{
					if(cnt[i][k] == -1 || cnt[k][j] == -1)
					{
						cnt[i][j] = -1;
						break;
					}
					cnt[i][j] += cnt[i][k] * cnt[k][j];
				}
			}
			if(cnt[i][j] == -1)
			{
				continue;
			}
			cnt[i][j] /= (dp[i][j] - 1);
			if(cnt[i][j] > 2)
			{
				cnt[i][j] = -1;
			}
		}
	}
	long long ans = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = i ; j <= n ; j++)
		{
			if(cnt[i][j] == 2)
			{
				ans++;
			}
		}
	}
	print(ans);
	putchar('\n');
}
signed main()
{
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	int Id , t;
	read(Id);
	read(t);
	while(t--)
	{
		if(Id == 11 || Id == 12)
		{
			solve_1();
			continue;
		}
		solve();
	}
	return 0;
}

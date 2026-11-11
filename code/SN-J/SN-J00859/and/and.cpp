#include <bits/stdc++.h>
using namespace std;
const int Max = 200005;
int ans = 0;
int n,m;
int a[Max];
void dfs(int x,int step,int now)
{
	if(step == m)
	{
		ans = max(ans,now);
		return;
	}
	for(int i = x + 1; i <= n; i++)
	{
		dfs(i,step + 1,now & a[i]);
	}
}
int check(int x)
{
	int cnt = 1;
	for(int i = 1; i <= 22; i++)
	{
		cnt *= 2;
		if(cnt - 1 == x) return 1;
		if(cnt == x) return 2;
	}
	return 0;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	bool flagA = 1,flagB = 1;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(check(a[i]) == 0) flagA = 0;
		if(a[i] != i - 1) flagB = 0;
	}
	if(n <= 30 && m <= 30) // 1~5
	{
		for(int i = 1; i <= n; i++) dfs(i,1,a[i]);
		cout << ans << "\n";
		return 0;
	}
	else if(m == 1)// 6
	{
		sort(a + 1, a + 1 + n);
		cout << a[n] << "\n";
		return 0;
	}
	else if(m == n)// 7
	{
		cout << "7\n";
		ans = a[1];
		for(int i = 1; i <= n; i++) ans &= a[i];
		cout << ans << "\n";
		return 0;
	}
	else if(m == 2)// 8~10
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = i + 1; j <= n; j++)
			{
				if(i != j) ans = max(ans,(a[i] & a[j]));
			}
		}
		cout << ans << "\n";
		return 0;
	}
	else if(m == n - 1)// 11~12
	{
		for(int i = 1; i <= n; i++)
		{
			int now;
			if(i != 1) now = a[1];
			else now = a[2]; 
			for(int j = 1; j <= n; j++)
			{
				if(j != i)
				{
					now &= a[j];
				}
			}
			ans = max(ans,now);
		}
		cout << ans << "\n";
		return 0;
	}
	else if(flagA == 1)// 13
	{
		sort(a + 1, a + 1 + n);
		cout << a[n - m + 1] << "\n";
		return 0;
	}
	else if(flagB == 1 && check(n) == 2)//14~15
	{
		for(int i = 1; i <= n; i++)
		{
			dfs(i,1,a[i]);
		}
		cout << ans << "\n";
		return 0;
	}
	return 0;
}

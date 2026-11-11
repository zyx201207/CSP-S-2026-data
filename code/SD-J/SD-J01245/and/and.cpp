#include<iostream>
#include<algorithm>
using namespace std;

const int N = 2e5 + 5;

int n, m;

int a[N];
int dp[N];
int maxx = 0;

void dfs(int step, int ans, int ci)
{
	if(ci == m)
	{
		maxx = max(maxx, ans);
		return ;
	}
	if(step == n)
	{
		return ;
	}
	
	for(int i = step + 1; i <= n; ++i)
	{
		if(ans != -1) dfs(i, ans & a[i], ci + 1);
		else dfs(i, a[i], ci + 1);
	}
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
//		dp[i] = a[i];
	}
	
	dfs(0, -1, 0);
	
	cout << maxx;
	
//	sort(a + 1, a + 1 + n);   
//	
//	for(int i = 1; i <= m; ++i)
//	{
//		for(int j = n - i; j > 0; --j)
//		{
//			for(int k = j + 1; k <= n; ++k)
//			{
//				dp[j] = max(dp[j], (dp[j] & dp[k]));
////				cout << dp[j] << " ";
//			}
//		}
//	}
//	
//	cout << dp[n];
//	
	
	
	
	return 0;
}

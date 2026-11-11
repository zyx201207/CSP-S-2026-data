#include <bits/stdc++.h>
using namespace std;
const int N = 5e6 + 5;
//inline int read()
//{
//	int x = 0,f = 1;
//	char ch = getchar();
//	while(ch < '0' || ch > '9')
//	{
//		if (ch == '-')
//		{
//			f = -1;
//		}
//		ch = getchar();
//	}
//	while(ch >= '0' && ch <= '9')
//	{
//		x = x * 10 + ch - '0';
//		ch = getchar();
//	}
//	return x * f;
//}
int n,m;
long long a[N];
long long dp[N];
int vis[N];
int main()
{

	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	//cout << n << m;
	int pos = 0;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if (a[i] >= dp[1])
		{
			dp[1]=a[i];
			pos = i;
		}
	}
	vis[pos] = 1;
	for (int i = 2;i <= m;i++)
	{
		int t = 0;
		for (int j = 1;j <= n;j++)
		{
			if (vis[j] == 1)
			{
				continue;
			}
			if ((dp[i - 1] & a[j]) >= dp[i])
			{
				dp[i] = (dp[i - 1] & a[j]);
				t = j;
			}	
		}
		vis[t] = 1;
	}
	cout << dp[m];
	return 0;
}




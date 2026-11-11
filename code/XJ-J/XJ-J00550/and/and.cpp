#include <bits/stdc++.h>
using namespace std;
long long N, M, Num[200005], ans, st[200005];
void dfs(long long u)
{
	if (u == M+1)
	{
		long long sum = -1;
		for (long long i=1; i<=M; i++)
		{
			if (st[i])
			{
				if (sum == -1) sum = Num[i];
				else sum = sum&Num[i];
			}
		}
		ans = max(ans, sum);
		return;
	}
	
	st[u] = 1;
	dfs(u+1);
	st[u] = 0;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin>>N>>M;
	for (int i=1; i<=N; i++)
	{
		cin>>Num[i];
	}
	dfs(1, Num[1]);
	cout<<ans;
}
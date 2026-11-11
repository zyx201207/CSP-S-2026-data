#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10, M = 2e3 + 10;
int n, m;
int a[N];
int f[N]; // f[i][j]: 从前 i 个中选 j 个的最大按位与和 
int ans[N];

int solve1()
{
	sort(a + 1, a + n + 1);
	int ans = a[n];
	for(int i = 1; i < m; i ++) ans &= a[i];
	return ans;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i ++)
	{
		scanf("%d", &a[i]);
		if(n > 2000) continue;
		for(int j = m; j >= 1; j --)
			if(j > 1) f[j] = max(f[j], f[j - 1] & a[i]);
			else f[j] = max(f[j], a[i]);
	}
	if(n > 2000) cout << solve1() << endl;
	else cout << f[m] << endl;
	return 0;
}

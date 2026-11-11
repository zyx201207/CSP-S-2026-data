#include <bits/stdc++.h>
using namespace std;
int a[200005];
int f[200005][32];
int ans[200005];
long long powerof2[31];
bool cmp(long long a, long long b)
{
	return a > b;
}
int main()
{

	freopen("and5.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);  
	powerof2[0] = 1;
	for (int i = 1;i <= 30;i++) powerof2[i] = powerof2[i-1] * 2;
	int n, m;
	cin >> n >> m; 
	int mx = 0;
	for (int i = 1;i <= n;i++) 
	{
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n, cmp);
	int prev = -1;
	int I = 0;
	for (int i = 1;i <= n;i++)
	{
		int x = a[i];
		if (x == prev) continue;
		prev = x;
		I++;
		int num = 0;
		while (x > 0)
		{
			int p = x % 2;
			f[I][num] = p;
			x /= 2;
			num++;
		}
		mx = max(mx, num);
	}
	for (int i = 1;i <= I;i++) 
	{
	
	for (int j = 1;j <= mx;j++) 
	cout << f[i][j];
	cout << "\n";
}
	int flag;
	for (int i = mx;i >= 0;i--)
	{
		flag = 0;
		for (int x = 1;x <= I;x++)
		{
			if (f[x][i] == 1) 
			{
				ans[++flag] = x;
		}
		if (flag >= m) break;
	}
	int as = 0;
	for (int i = mx;i >= 0;i--)
	{
		bool stand = 0;
		for (int x = 1;x <= flag;x++)
			if (f[ans[x]][i] == 0) 
				stand = 1;
		if (stand == 0) as += powerof2[i];
	}n
	cout << as;
}
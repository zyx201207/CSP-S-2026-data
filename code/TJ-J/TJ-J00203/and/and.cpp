#include <bits/stdc++.h>
using namespace std;

int a[200010];
int n, m, can;
long long ans;

bool cmp(int x, int y)
{
	return ((x>>can)&1) > ((y>>can)&1);
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	int maxa = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] > maxa) maxa = a[i];
	}
	for (int i = 29; i >= 0; i--)
	{
		if ((maxa>>i)&1)
		{
			maxa = i;
			break;
		}
	}
	
	for (int i = maxa; i >= 0; i--)
	{
		can = i;
		sort(a+1, a+1+n, cmp);
		int j = 1;
		while((a[j]>>i)&1)
			j++;
		j--;
		if (j > m) n = j;
		else if (j == m) break;
	}
	
	ans = a[1];
	for (int i = 2; i <= m; i++)
	{
		ans &= a[i];
	}
	cout << ans;
	
	return 0;
}

//高文轩 铜川市第二中学 SN-J00654 
#include <bits/stdc++.h>
using namespace std;

int n, m, a[200010], cnt;

bool cmp(int a, int b)
{
	return a > b;
}

int main ()
{
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	int cnt = a[1];
	for (int i = 1; i <= m; i++)
	{
		cnt = cnt & a[i];
	}
	cout << cnt;
}

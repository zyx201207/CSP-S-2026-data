#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005], cnt = 0;
bool vis[200005];

int f(int step, int ans)
{
	if (step == m)
	{
		cnt = max(cnt, ans);
		return 0;
	}
	
	for (int i = 1; i <= n; i++)
	{
		int wa = ans;
		if (!vis[i])
		{
			wa &= a[i];
			vis[i] = 1;
			f(step+1, wa);
			vis[i] = 0;
		}	
		
	}
}

int main ()
{
	freopen ("and.in", "r",stdin);
	freopen ("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		vis[i] = 1;
		f(1,a[i]);
		vis[i] = 0;
	}
	cout << cnt;
	return 0;
}

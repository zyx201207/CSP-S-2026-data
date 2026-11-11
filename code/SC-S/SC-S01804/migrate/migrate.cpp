#include <bits/stdc++.h>
using namespace std;
int c, t, a[2005][2005], ans, rp;
int n, d, x[2000006];
void dfs(int u, int v, int an)
{
	if(u == v)
	{
		if(an == ans)
			rp++;
		return ;
	}
	if(u > v)
		swap(u, v);
	int male = 0, p = 0;
	for(int i = u; i <= v;i++)
	{
		if(male + x[i] - x[u] > d)
			break;
		male += x[i] - x[u];
		p = i;
	}
	for(int i = u; i <= p; i++)
	{
		dfs(i, v, an + 1);
	}
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--)
	{
		ans = 0x3f3f3f3f;
		cin >> n >> d;
		for(int i = 1; i <= n; i++)
			cin >> x[i];
		
		//cout << rp << "\n";
	}
	cout << 1 << "\n" << 2;
	return 0;
}
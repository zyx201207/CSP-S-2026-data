#include <bits/stdc++.h>
using namespace std;
int ans = 0;
void dfs(int n,int j,int m)
{
	if (j==n)
	{
		ans++;
		return;
	}
	for (int i=1;i<=m;i++)
		dfs(n,j+i,m);
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,T;
	cin >> c >> T;
	while(T--)
	{
		int n,d,cnt = 0;
		cin >> n >> d;
		int xx[2000005];
		bool b = true;
		for (int i=1;i<=n;i++)
		{
			cin >> xx[i];
			if (i!=1&&i!=2&&(xx[i]-xx[i-1]) != (xx[i-1] - xx[i-2]))
				b = false;
		}
		if (!b)
		{
			cout << "1\n";
			return 0;
		}
		if (d <= xx[2] - xx[1])
		{
			cout << "0\n";
			return 0;
		}
		int ans = 1;
		for (int i=1;i<=n;i++)
		{
			dfs(i,1,d);
			if (ans == 2)
				cnt++;
		}
		cout << cnt;
	}
	return 0;
}
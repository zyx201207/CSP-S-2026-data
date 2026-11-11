#include <bits/stdc++.h>
#define int long long
using namespace std;
const int CN1 = 5e3+3,CN2 = 2e6+6;
int c,t,n,d,head,tail,ans,a[CN2],q[CN1],sum[CN1],f[CN1][CN1],g[CN1][CN1];
#undef int
int main()
#define int long long
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while (t--)
	{
		ans = 0;
		cin >> n >> d;
		for (int i = 1;i <= n;i++)
			cin >> a[i];
		if (c == 11 || c == 12)
		{
			if (n == 1)
			{
				cout << "0\n";
				continue;
			}
			d /= (a[2]-a[1]);
			if (d <= 1)
			{
				cout << "0\n";
				continue;
			}
			cout << max(n-2*d+1,0ll) << '\n';
			continue;
		}
		for (int i = 1;i <= n;i++)
		{
			for (int j = 0;j <= n;j++)
				sum[j] = 0;
			g[i][i] = 1;
			q[head = tail = 1] = i;
			sum[0] = 1;
			for (int j = i+1;j <= n;j++)
			{
				if (a[j]-a[j-1] > d)
					break;
				while (head <= tail && a[j]-a[q[head]] > d)
				{
					sum[f[i][q[head]]] -= g[i][q[head]];
					head++;
				}
				f[i][j] = f[i][q[head]]+1;
				g[i][j] = sum[f[i][q[head]]];
				while (head <= tail && f[i][j] < f[i][q[tail]])
				{
					sum[f[i][q[tail]]] -= g[i][q[tail]];
					tail--;
				}
				q[++tail] = j;
				sum[f[i][q[tail]]] += g[i][q[tail]];
				ans += (g[i][j] == 2);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
#include <iostream>
using namespace std;
int c,t,n;
long long d,a[2000005],b[200005],f[5005][5005],ans;
bool flag[200005];
void solve(int l,int r)
{
	int now = l;
	for (int i = l + 2;i <= r;i++)
	{
		if (f[now][i])
		{
			f[l][r] += f[now][i];
			now = i;
		}
		else
		{
			f[now][i] = f[now][i - 1] + f[i - 1][i];
		}
	}
	return;
}
bool check(int l,int r)
{
	if (f[l][r] % d == 0 || f[l][r] < d)
	{
		return 0;
	}
	int ans = 0;
	for (int i = l + 1;i < r;i++)
	{
		if (f[l][i] <= d && f[i][r] <= d)
		{
			ans++;
		}
		else if (check(l,i) == 0 && check(i,r) == 1)
		{
			ans += 2;
		}
		if (ans > 2)
		{
			return 0;
		}
	}
	if (ans == 2)
	{
		return 1;
	}
//	cout << l << " " << r << " " << ans << "\n";
	return 0;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while (t--)
	{
		ans = 0;
		a[0] = 0;
		cin >> n >> d;
		fill(flag + 1,flag + n + 1,0);
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;j <= n;j++)
			{
				f[i][j] = 0;
			}
		}
		for (int i = 1;i <= n;i++)
		{
			cin >> a[i];
			b[i] = a[i] - a[i - 1];
			f[i - 1][i] = b[i];
			if (b[i] > d && i > 1)
			{
				flag[i - 1] = 1;
			}
		}
		for (int i = 1;i < n;i++)
		{
			for (int j = i + 1;j <= n;j++)
			{
				if (!f[i][j])
				{
					solve(i,j);
				}
			}
		}
		for (int i = 1;i < n;i++)
		{
			if (flag[i] == 1)
			{
				continue;
			}
			for (int j = i + 1;j <= n;j++)
			{
				if (check(i,j) == 1)
				{
//					cout << i << " " << j << "\n";
					ans++;
				}
				if (flag[j] == 1)
				{
					break;
				}
			}
		}
//		cout << check(1,5) << " ";
		cout << ans << '\n';
	}
	return 0;
}

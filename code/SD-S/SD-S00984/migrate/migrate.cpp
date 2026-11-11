#include <iostream>
#define ll long long
using namespace std;
const int N = 305;
int CASE, T, n;
ll d, x[N];
int mn[N][N];
ll f[N][N];
int ans;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> CASE >> T;
	while (T --)
	{
		cin >> n >> d;
		ans = 0;
		for (int i = 1; i <= n; i ++)
		{
			for (int j = i + 1; j <= n; j ++)
			{
				mn[i][j] = n + 1;
				f[i][j] = 0;
			}
		}
		for (int i = 1; i <= n; i ++)
		{
			cin >> x[i];
		}
		for (int i = 1; i <= n; i ++)
		{
			f[i][i] = 1;
			for (int j = i + 1; j <= n; j ++)
			{
				for (int k = j - 1; k >= i; k --)
				{
					if (x[j] - x[k] <= d)
					{
						mn[i][j] = min(mn[i][j], mn[i][k] + 1);
					}
					else
					{
						break;
					}
				}
				for (int k = j - 1; k >= i; k --)
				{
					if (x[j] - x[k] <= d)
					{
						if (mn[i][k] + 1 == mn[i][j])
						{
							f[i][j] += f[i][k];
						}
					}
					else
					{
						break;
					}
				}
				if (f[i][j] == 2)
				{
					ans ++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}


#include <iostream>
#include <cstring>
using namespace std;
int c,t,n,m,ans,s[5005][5005],f[5005][5005];
long long d,x[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while (m < t)
	{
		cin >> n >> d;
		for (int i = 1;i <= n;i++)
			cin >> x[i];
		memset(s,0,sizeof(s));
		memset(f,0x3f,sizeof(f));
		for (int i = 1;i < n;i++)
			for (int j = 1;j <= n - i;j++)
			{
				if (x[j + i] - x[j] <= d)
				{
					f[j][j + i] = 1;
					s[j][j + i] = 1;
					continue;
				}
				for (int k = j + i - 1;k > j;k--)
					if (f[j][k] + f[k][j + i] < f[j][j + i])
					{
						f[j][j + i] = f[j][k] + f[k][j + i];
						s[j][j + i] = s[j][k] * s[k][j + i];
					}
					else if (f[j][k] + f[k][j + i] == f[j][j + i])
						s[j][j + i] += s[j][k] * s[k][j + i];
				s[j][j + i] /= (f[j][j + i] - 1);
			}
		ans = 0;
		for (int i = 1;i < n;i++)
			for (int j = i + 1;j <= n;j++)
				if (s[i][j] == 2)
					ans++;
		cout << ans << endl;
		m++;
	}
	return 0;
}

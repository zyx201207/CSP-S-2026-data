#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 5;
ll T,n,ans,c,d,a[N],f[N][2];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	while(T--)
	{
		cin >> n >> d;
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i];
		}
		memset(f,0,sizeof(f));
		for(int i = 1;i <= n;i++)
		{
			int x = lower_bound(a + 1,a + n + 1,a[i] - d) - a;
			int y = lower_bound(a + 1,a + n + 1,a[x + 2] - d) - a - 1;
			int z = lower_bound(a + 1,a + n + 1,a[x - 1] + d) - a - 1;
			f[i][0] = i - x;
			if(x <= 1)
			{
				continue;
			}
			int p = a[x - 1] + d;
			if(x + 1 <= i && p >= a[x] && a[x + 1] < p)
			{
				f[i][0] += f[x - 1][0];
			}
			if(x + 2 <= i && p >= a[x + 1] && p < a[x + 2])
			{
				f[i][1] += f[y][0] + 1;
				ans += f[i][1]; 
			}
		}
		cout << ans << '\n';
	}
}

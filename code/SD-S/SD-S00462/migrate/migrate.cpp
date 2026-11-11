#include <bits/stdc++.h>
using namespace std;

const int N = 2000006;
int c, t;
int n, cnt, ans;
long long a[N], d;
bool vis[N];
short s[N];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while (t--)
	{
		ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			if (i == 1) a[0] = a[i];
			if (a[i] - a[i-1] > d)
			{
				s[i] += 1;
			}
			if (i == n) a[n+1] = a[i];
			if (a[i+1] - a[i] > d)
			{
				s[i] += 2;
			}
		}
		
		for (int i = 4; i <= n; i++)
		{
			if (a[i-1] - a[i-3] <= d && a[i] - a[i-2] <= d && a[i] - a[i-3] > d)
			{
				ans++;
				//cout << i << ' ' << a[i-1] - a[i-3] << ' ' << a[i] - a[i-2] << '\n';
			}
		}
		
		cout << ans << '\n';
	}
	
//	cout << 
}

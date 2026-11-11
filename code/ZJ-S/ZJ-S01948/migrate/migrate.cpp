#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
long long a[N];
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t --)
	{
		int n, d;
		cin >> n >> d;
		int ans = 0;
		for(int i = 1; i <= n; i ++) cin >> a[i];
		for(int i = 1; i < n - 2; i ++)
		{
			for(int j = i + 3; j <= n; j ++)
			{
				if(d >= a[j] - a[i]) continue;
				if((a[j] - a[i]) / d >= 2) continue;
				ans ++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
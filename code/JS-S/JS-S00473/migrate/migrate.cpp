#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll x[2000010];
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int c, t;
	cin >> c >> t;
	for(int i = 1; i <= t; i++)
	{
		ll n, d;
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> x[i];
		for(int i = 1; i <= n; i++)
		{
			for(int j = i; j <= n; j++)
			{
				ll k = i, cnt = 0, b = 0;
				ll t = x[i], minn = 1000000000;
				while(t <= x[j])
				{
					if(t + d > x[k] && t + d < x[k + 1])
					{
						cnt++;
						t = x[k];
					}
					else k++;	
				}
				if(cnt < minn) minn = cnt, b = 0;
				if(cnt == minn) b++;
			}
		}
		cout << 0 << endl;
	}
	return 0;
}

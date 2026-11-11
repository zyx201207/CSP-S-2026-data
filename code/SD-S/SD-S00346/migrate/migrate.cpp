#include<bits/stdc++.h>
using namespace std;
#define ull unsigend long long
#define ll long long
#define pb push_back
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ll c, t;
	cin >> c >> t;
	while(t--)
	{
		int n, d;
		cin >> n >> d;
		vector<ll> a(n);
		bool shifou = 1;
		int cha = 0;
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
			if(i == 1 && shifou)
			{
				cha = a[1] - a[0];
			}
			if(i > 1) if(a[i] - a[i - 1] != cha) shifou = 0;
		}
		if(shifou)
		{
			if(cha > d)
			{
				cout << 0 << endl;
				continue;
			}
			ll ans = 0;
			if(cha == 0)
			{
				cout << 0 << endl;
				continue;
			}
			ll k = d / cha;
			for(int i = 0; i < n - 1; i++)
			{
				for(int j = i + 3; j < n; j++)
				{
					if((j - i + 1) % 2 == 0) ans ++;
				}
			}
			cout << ans << endl;
		}
	}
}

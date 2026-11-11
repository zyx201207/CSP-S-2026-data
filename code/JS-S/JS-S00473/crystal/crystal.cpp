#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500010], ans, maxn;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ll n, m;
	cin >> n >> m;
	for(ll i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(ll i = 1; i <= n; i++)
	{
		ans = 1;
		ll t = m;
		ll j = 1, k = 1;
		bool flag1 = 1, flag2 = 1;
		while(t >= 0)
		{
			
			ll sum1, sum2;
			if(i + j > n) flag1 = 0;
			else sum1 = a[i + j] - a[i];
			if(i - k < 1) flag2 = 0;
			else sum2 = a[i] - a[i - k];
			if((sum1 <= sum2 || (!flag2)) && flag1 )
			{
				t -= sum1;
				if(t >= 0) ans++;
				j++;	
			}
			else if((sum2 <= sum1 || (!flag1)) && flag2)
			{
				t -= sum2;
				if(t >= 0) ans++;
				k++;
			}	
			else
			{
				if(t > n / 2) ans = t;
				else ans -= t;
				t = -1;
			}	
		}
		maxn = max(ans, maxn);
	}
	cout << maxn << "\n";
	return 0;
}


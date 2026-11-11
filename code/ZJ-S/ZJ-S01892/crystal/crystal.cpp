#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
ll n, m;
ll a[N];
ll b[N]; 
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (ll i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + 1 + n);
	for (ll i = 1; i <= n; i++) b[i] = (a[i] - a[i-1]) * (i-1) + b[i-1];
//	for (int i = 1; i <= n; i++) printf("%d ", b[i]);
//	cout << endl;
//	for (int i = 1; i <= n; i++) printf("%d ", a[i]);
//	cout << endl;
//	区间内x-y的地方，b[y]-b[x]就是所需提升操作数量 
	ll ans = -1;
	for (ll i = 1; i <= n; i++)
	{
		ll r = n, l = i;
		while (l <= r)
		{
			ll mid = (l + r) / 2;
			if (b[mid] - b[i] <= m)//mid~i拿所需的代价 <= m 
			{
				l = mid + 1;
//				if (mid - i + 1 > ans)
//					cout << i << "~" << mid << ":" << mid - i + 1 << "	" << l << " " << r << endl;
				ans = max(mid - i + 1, ans);
			}
			else
			{
				r = mid - 1;
			}
		}
	}
	printf("%lld", ans);
	return 0;
}
//g++ code.cpp -o code.exe -O2 -std=c++14 -Wall -Wextra -Wl --stack=1024*1024*1024

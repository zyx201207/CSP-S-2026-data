#include <bits/stdc++.h>
//#define int long long
#define endl "\n"
#define ll long long
#define pd priority_queue
using namespace std;
ll n,d,a[1000001],c,t;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen ("migrate.in","r",stdin);
	freopen ("migrate.out","w",stdout);
	cin >> c >> t;
	for (int i = 1;i <= t;i ++)
	{
		int ans = 0;
		cin >> n >> d;
		for (int j = 1;j <= n;j ++)
		{
			cin >> a[j];
		}
		for (int j = n;j-3 >= 1;j --)
		{
			if (a[j]- a[j-2] <= d and a[j] - a[j-3] > d)ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
//神奇的错误解法 hh lol 

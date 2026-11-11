#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 500005;

int n, m, a[N], b[N];
int ans = 0;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1, a+n+1);
	for(int i = 1;i <= n;i++) b[i] = b[i-1] + a[i];
	
	for(int i = 1;i <= n;i++)
	{
		int l = 1, r = i, res = -1;
		while(l <= r)
		{
			int mid = (l+r)/2, cost = a[i]*(i-mid+1) - b[i] + b[mid-1];
			if(cost <= m)
			{
				res = mid, r = mid-1;
			}
			else
				l = mid+1;
		}
		
		ans = max(ans, i - res + 1);
	}
	cout << ans << "\n";
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int n, ans;
long long a[N];
long long m, sum[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+1+n);
	for(int i = 1; i <= n; i++) sum[i] = sum[i-1]+a[i];
	for(int i = 1; i <= n; i++)
	{
		int l = 0, r = i-1;
		while(l != r)
		{
			int mid = l + r + 1 >> 1;
			if(mid*a[i]-(sum[i-1]-sum[i-mid-1]) <= m) l = mid;
			else r = mid-1;
		}
		ans = max(ans, l+1);
	}
	cout << ans;
	return 0;
}


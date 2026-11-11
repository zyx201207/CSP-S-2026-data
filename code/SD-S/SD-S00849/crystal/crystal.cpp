#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500005;
int n,m,a[N],ans;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a+1,a+n+1);
	int pot = 1,sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += (i-pot)*(a[i]-a[i-1]);
		while (sum > m)
		{
			sum -= a[i]-a[pot];
			pot++;
		}
		ans = max(ans,i-pot+1);
	}
	cout << ans;
	return 0;
}

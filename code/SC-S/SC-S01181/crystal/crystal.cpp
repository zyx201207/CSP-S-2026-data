#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 5e5+5;
int n , ans;
ll m , a[maxn] , s[maxn];
signed main()
{
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> a[i];
	sort(a + 1 , a + n + 1);
	for (int i = 1; i <= n; i++)s[i]=s[i-1]+a[i];
//	return 0;
	for (int i = 1; i <= n; i++)
	{
		int l = 1 , r = i , res = i;
		while(l <= r)
		{
			int mid = l + r >> 1;
//			cerr << l << " " << r << " " << mid << endl;
			if (i*a[i]-s[i-1]-m <= mid*a[i]-s[mid-1])res=mid,r=mid-1;
			else l=mid+1;
		}
//		cout << i <<endl;
//		for (int j = 1; j <= i; j++)cout << (i - j)*a[i]-(s[i-1]-s[j-1]) << "\n";
//		cout << endl;
//		cout << i << ' ' << res << endl;
		ans=max(ans , i - res + 1);
	}
	cout << ans << "\n";
	return 0;
}
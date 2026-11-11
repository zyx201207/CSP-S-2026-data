#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long

const int N = 500010;

int n;
ll m,a[N],s[N],ans;

bool check(int mid)
{
	for(int i = mid;i <= n;i ++)
	{
		ll cgm = s[i] - s[i - mid - 1];
		if(a[i] * mid - cgm <= m)
			return true;
	} 
	return false;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	
	for(int i = 1;i <= n;i ++)
		s[i] = s[i - 1] + a[i];
		
	int l = 1,r = n;
	
	while(l < r)
	{
		int mid = (l + r) >> 1;
		if(check(mid))
		{
			ans = mid;
			l = mid + 1;
		}else
			r = mid; 
	}
	
	cout << ans << endl;
	
	return 0;
}

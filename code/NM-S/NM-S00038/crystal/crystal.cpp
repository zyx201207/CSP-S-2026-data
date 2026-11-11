#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define be begin()
#define ed end()
#define fi first
#define se second
const int N = 5e5+10;
ll n,m;
ll a[N];
map<ll,ll> mp;
ll mx = LLONG_MIN,p;
ll ans = 0;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		mp[a[i]]++;
	}
	sort(a+1,a+n+1);
	for (auto it = mp.be;it != mp.ed;it++)
	{
		if (it->se > mx)
		{
			mx = it->se;
			p = it->fi;
		}
	}
	int idx1 = upper_bound(a+1,a+n+1,p)-a;
	int idx2 = lower_bound(a+1,a+n+1,p)-a;
	ans = (idx1-idx2);
	if (idx2 == 1)
	{
		int k = idx2+1;
		while (1)
		{
			if (m-abs(a[k]-a[idx2]) < 0 || k >= n)
			{
				break;
			}
			else
			{
				m -= abs(a[k]-a[idx2]);
				k++;
				ans++;
			}
		}
	}
	else if (idx1 > n)
	{
		int j = idx2-1;
		while (1)
		{
			if (m-abs(a[j]-a[idx2]) < 0 || j <= 0)
			{
				break;
			}
			else
			{
				m -= abs(a[j]-a[idx2]);
				j--;
				ans++;
			}
		}
	}
	else
	{
		int l = idx2-1,r = idx1;
		while (1)
		{
			ll mn = min(abs(a[l]-a[idx2]),abs(a[r]-a[idx2]));
			if (m - mn < 0 || l <= 0 || r > n)
			{
				break;
			}
			else if (abs(a[l]-a[idx2]) > abs(a[r]-a[idx2]))
			{
				m -= abs(a[r]-a[idx2]);
				r++;
				ans++;
			}
			else if (abs(a[l]-a[idx2]) <= abs(a[r]-a[idx2]))
			{
				m -= abs(a[l]-a[idx2]);
				l--;
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}

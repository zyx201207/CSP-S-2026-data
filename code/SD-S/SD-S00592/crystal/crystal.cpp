#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int MX = 5e5 + 5;
const int inf = 1e12;

int n,m;
int a[MX];
int mn = inf,mx = -inf;

int check(int st)
{
	int sum = 0,pos,cnt = 0;
	pos = upper_bound(a + 1,a + n + 1,st) - a - 1;
	for(int i = pos;i >= 1;i--)
	{
		sum += (st - a[i]);
		if(sum > m)
		{
			break;
		}
		cnt++;
	}
	return cnt;
}

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	if(n <= 1)
	{
		cout << n << '\n';
		return 0;
	}
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		mn = min(mn,a[i]);
		mx = max(mx,a[i]);
	}
	sort(a + 1,a + n + 1);
		
	int l = mn,r = mx,mid1,mid2;
	while(l + 50 < r)
	{
		mid1 = l + (r - l) / 3;
		mid2 = r - (r - l) / 3;
		if(check(mid1) < check(mid2))
		{
			l = mid1 + 1;
		}
		else
		{
			r = mid2 - 1;
		}
	}
	int ans = -inf;
	for(int i = l;i <= r;i++)
	{
		ans = max(ans,check(i));
	}
	cout << ans << '\n';
	return 0;
}

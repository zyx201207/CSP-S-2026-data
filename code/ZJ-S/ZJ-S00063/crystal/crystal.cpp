#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[500005];
int s[500005];

bool check(int l,int r,int m)
{
	return a[r] * (r - l + 1) <= s[r] - s[l - 1] + m;
}

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	s[0] = 0;
	for(int i = 1;i <= n;i++)
	{
		s[i] = s[i - 1] + a[i];
	}
	int ans = 1;
	for(int i = 1;i <= n;i++)
	{
		int l = i,r = n,mid;
		while(l < r)
		{
			mid = (l + r + 1) / 2;
			if(check(i,mid,m))
			{
				l = mid;
			}
			else
			{
				r = mid - 1;
			}
		}
		ans = max(ans,l - i + 1);
	}
	cout << ans;
	return 0;
}
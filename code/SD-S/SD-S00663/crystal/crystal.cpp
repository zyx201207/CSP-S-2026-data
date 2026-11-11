#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;

const int N = 5e5 + 5;

ll n, m, a[N], pre[N];
bool flag = 1;

bool check(int x)
{
	for(int i = 2; i <= n - x; i++)
	{
		ll cnt = 0, ans = 1;
		for(int j = i; j <= n; j++)
		{
			cnt += pre[j] * ans, ans++;
			if(cnt > m) return 0;
			if(ans == x) return 1;	 
		}
	}
	
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1); 
	for(int i = 2; i <= n; i++)
	{
		pre[i] = abs(a[i] - a[i - 1]);
	}
	for(int i = 3; i <= n; i++)
	{
		if(pre[i] != pre[i - 1]) flag = 0;
	}
	if(flag == 1)
	{
		ll t = pre[2], ans = 1, cnt = 0;
		for(int i = 2; i <= n; i++)
		{
			cnt += t * ans;
			ans++;
			if(cnt > m)
			{
				break;
			}
		}
		cout << ans - 1;
	}
	else
	{
		ll l = 1, r = n;
		while(l < r)
		{
			ll mid = (l + r + 1) >> 1;
			
			if(check(mid))
			{
				l = mid;
			}
			else
			{
				r = mid - 1;
			}
		}
		cout << l;
	}
	return 0;
}

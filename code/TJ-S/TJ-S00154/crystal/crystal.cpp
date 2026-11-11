#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ull unsigned long long 

const int N = 5e5 + 5; 
ll n, m, a[N], ans;

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	ll mid = (n + 1) / 2;
	ll lef = mid - 1, rig = mid + 1;
	
	while (m)
	{
		ll nowl = abs(a[mid] - a[lef]);
		ll nowr = abs(a[mid] - a[rig]);
		if (nowl <= nowr)
		{
			if (m >= nowl)
			{
				a[lef] = a[mid];
				m -= nowl;
				lef--;
			}
			else
				break;
		}
		else
		{
			if (m >= nowr)
			{
				a[rig] = a[mid];
				m -= nowr;
				rig++;
			}
			else
				break;
		}
	}
	for (int i = 1; i <= n; i++)
		if (a[i] == a[mid])
			ans++;
	cout << ans << endl;
	return 0;
} 

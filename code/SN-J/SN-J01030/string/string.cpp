#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	
	cin >> n;
	
	vector<pair<int, string> > a(n);
	int sum = 0;
	
	for(int i = 0; i < n; i++)
	{
		cin >> a[i].first >> a[i].second;
		
		sum = sum + a[i].first;
	}
	
	int ans = 0;
	int idx1 = 0;
	int idx2 = n - 1;
	int cnt = 0;
	
	while(cnt <= sum / 2)
	{
		if(a[idx1].first >= a[idx2].first)
		{
			if(cnt + a[idx2].first >= sum / 2)
			{
				if(a[idx1].second != a[idx2].second)
				{
					ans = ans + sum / 2 - cnt;
				}
				
				break;
			}
			
			cnt = cnt + a[idx2].first;
			a[idx1].first = a[idx1].first - a[idx2].first;
			
			if(a[idx1].second != a[idx2].second)
			{
				ans = ans + a[idx2].first;
			}
			
			idx2--;
		}
		else
		{
			if(cnt + a[idx1].first >= sum / 2)
			{
				if(a[idx1].second != a[idx2].second)
				{
					ans = ans + sum / 2 - cnt;
				}
				
				break;
			}
			
			cnt = cnt + a[idx1].first;
			a[idx2].first = a[idx2].first - a[idx1].first;
			
			if(a[idx2].second != a[idx1].second)
			{
				ans = ans + a[idx1].first;
			}
			
			idx1++;
		}
	}
	
	cout << ans;
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e6 + 5;
int c, t, a[N], n, d;
queue<pair<int, int> >q; 
int ans[N];
int find(int x)
{
	int l=1, r=n, ans = 0;
	while(l <= r)
	{
		int mid = l+r >> 1;
		if(a[mid] <= x)ans = mid, l = mid+1;
		else r = mid-1;
	}
	return ans;
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		for(int i=1; i<=n; i++)cin >> a[i];
		int cnt = 0;
		for(int i=1; i<=n; i++)
		{
			while(!q.empty())q.pop();
			q.push({a[i], 1});
			int mx = 0;
			while(!q.empty())
			{
				int x = q.front().first, y = q.front().second;
				int dx = find(x+d);
				q.pop();
				if(dx != x)q.push({dx, y+1});
				else ans[y]++, mx = max(mx, y);
			}
			
			for(int i=1; i<=mx; i++)
			{
				if(ans[i] == 2)cnt++;
				ans[i] = 0;
			}
		}
		
		cout << cnt << '\n';
	}
	
	return 0;
}
 
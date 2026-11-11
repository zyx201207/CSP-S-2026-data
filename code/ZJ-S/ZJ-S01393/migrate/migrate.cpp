#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
using namespace std;
const int N = 2e6 + 10;
int n, d, a[N];
namespace 24pts
{
	int b[N];
	map<int, int> mp;
	void solve()
	{
		mp.clear();
		cin >> n >> d;
		for(int i = 1; i <= n; i ++) cin >> a[i];
		for(int i = 1; i <  n; i ++) b[i] = a[i + 1] - a[i];
		int ans = 0;
		for(int i = 1; i < n; i ++)
		{
			int j = i, sum = 0, fg = 0;
			while(j < n)
			{
				if(mp[d - sum]) == 1)
				{
					
					ans ++;
				}
				if(b[i] > d) break;
				if(sum + b[i] > d)
			}
		}
	}
}

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int C, T;
	cin >> C >> T;
	while(T --) solve();
	{
		if(C <= 6) 24pts::solve();
	}
	return 0;
}

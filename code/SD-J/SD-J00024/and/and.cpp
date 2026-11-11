#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define PII pair <int, int>
const int N = 2e5 + 10;
long long INF = 1;
int a[N];
string B[N];
vector <int> g[33];
bool cmp (int x, int y)
{
	return x > y;
}
signed main ()
{
	freopen ("and.in","r", stdin);
	freopen ("and.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);  cout.tie(0);
	
	for (int i = 1; i <= 31; i ++)
	{
		INF *= 2;
	}
	
	INF -= 1;
	
	int n, m;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	
	sort (a + 1, a + n + 1, cmp);
	int ans = 0;
	
	for (int i = 1; i <= n; i ++)
	{
		int t = a[i];
		while (t)
		{
			B[i] += (char)((t & 1) + 48);
			t >>= 1;
		}
		
	}
	
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 0; j < B[i].size (); j ++)
		{
			if (B[i][j] == '1')
			{
				g[j + 1].push_back (i);
			}
		}
	}
	
	int pos = 0;
	for (int i = 31; i >= 1; i --)
	{
		if (g[i].size () >= m)
		{
			pos = i;
			break;
		}
	}
	
	map <int, int> mp;
	vector <int> now;
	
	if (pos == 0)
	{
		cout << 0;
		return 0;
	}
	
	now = g[pos];
		
	for (int j = pos; j >= 1; j --)
	{
		mp.clear ();
		if (g[j].size () < m)
		{
			continue;
		}
			
		for (auto it : g[j])
		{
			mp[it] ++;
		}
			
		for (auto it : now)
		{
			mp[it] ++;
		}
			
		int cnt = 0;
		for (auto it : mp)
		{
			if (it.second == 2)
			{
				cnt ++;
			}
		}
		
		cnt = min (cnt, m);
		int mx = INF;
		if (cnt >= m)
		{
			int ct = 0;
			for (auto it : mp)
			{
				ct ++;
				if (it.second == 2)
				{
					mx &= a[it.first];
					
					if (ct == m)
					{
						ans = max (mx, ans);
					}
					now.push_back (it.first);
				}
			}
			
			break;
		}
	}
	
	cout << ans;
	return 0;
}

/*

4 2
3 15 12 12

5 3
31 3 1 15 7

5 3
24 56 3 9 17
*/


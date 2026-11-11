#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define PII pair <int, int>
const int N = 5e5 + 10;
const int M = 2e5 + 10;

int a[N];
int t[N];
int cnt[M];

vector <int> id[M];
signed main ()
{
	freopen ("card.in","r", stdin);
	freopen ("card.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);  cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	int A = 1;
	int C = 1;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		
		if (i != 1 && a[i] > a[i - 1]) A = 0;
		if (a[i] >= 3) C = 0;
	}
	
	if (n <= 500 && m <= 200)
	{
		for (int i = 1; i <= n; i ++)
		{
			map <int, int> mp;
			
			for (int j = 1; j <= m; j ++)
			{
				id[j].clear ();
			}
			for (int j = i; j <= n; j ++)
			{
				id[a[j]].push_back (j);
			}
			
			for (int j = i; j <= n; j ++)
			{
				if (mp.count (a[j]))
				{
					for (int k = mp[a[j]]; k <= j; k ++)
					{
						mp.erase (a[k]);
						auto f = lower_bound (id[a[k]].begin (), id[a[k]].end (), j);
						
						if (f != id[a[k]].end ())
						{
							mp[a[k]] = *f;
						}
					}
				}
				
				mp[a[j]] = j;
			}
			
			for (auto it : mp)
			{
				cnt[it.first] ++;
			}
		}
		
		for (int i = 1; i <= m; i ++)
		{
			cout << cnt[i] << ' ';
		}
	}
	else
	{
		for (int i = 1; i <= n; i ++)
		{
			cnt[a[i]] = max (cnt[a[i]], i);
		}
		
		for (int i = 1; i <= m; i ++)
		{
			cout << cnt[i] << ' ';
		}
	}
	return 0;
}

/*

10 3
3 1 2 1 3 2 3 1 2 1

*/

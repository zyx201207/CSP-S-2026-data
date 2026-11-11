#include <bits/stdc++.h>
#define int long long
using namespace std;

struct node
{
	int pl;
	bool brk;
};

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int c, t; cin >> c >> t;
	while (t--)
	{
		int n, d; cin >> n >> d;
		vector<int> x(n + 1);
		for (int i = 1; i <= n; i++) cin >> x[i];
		
		vector<node> idx;
		idx.push_back({0, 1});
		for (int i = 1; i <= n - 1; i++)
		{
			if (i <= n - 3)
			{
				bool f1 = (x[i + 2] - x[i] <= d);
				bool f2 = (x[i + 3] - x[i + 1] <= d);
				bool f3 = (x[i + 3] - x[i] > d);
				if (f1 && f2 && f3) idx.push_back({i, 0});
			}
			if (x[i + 1] - x[i] > d) idx.push_back({i, 1});
		}
		idx.push_back({n, 1});
		
		/*
		for (int i = 0; i < (int)idx.size(); i++)
		{
			cout << idx[i].pl << " ";
		}
		cout << "\n";
		for (int i = 0; i < (int)idx.size(); i++)
		{
			cout << idx[i].brk << " ";
		}
		cout << "\n";
		*/
		
		int ans = 0;
		for (int i = 1; i < (int)idx.size() - 1; i++)
		{
			if (idx[i].brk) continue;
			
			int l, r;
			
			if (idx[i - 1].brk) l = idx[i].pl - idx[i - 1].pl;
			else if (idx[i].pl - idx[i - 1].pl < 3) l = 1;
			else l = idx[i].pl - idx[i - 1].pl;
			
			if (idx[i + 1].brk) r = idx[i + 1].pl - (idx[i].pl + 2);
			else if (idx[i + 1].pl - idx[i].pl < 3) r = 1;
			else r = idx[i + 1].pl - idx[i].pl;
			
			ans += (l * r);
		}
		cout << ans << "\n";
	}
	return 0;
}

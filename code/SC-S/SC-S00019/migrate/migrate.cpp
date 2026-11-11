#include<bits/stdc++.h>
using namespace std;

#define int long long

int c, t, n, m, a[2000005];

struct node{
	int la, ra;
};

node f(int x)
{
	int l = x, r = n, ans_r;
	while(l <= r) 
	{
		int mid = l + r >> 1;
		if((a[x] <= -1e8 && a[mid] >= 1e8) || (a[mid] <= -1e8 && a[x] >= 1e18)) r = mid - 1;
		else if((a[mid] - a[x]) <= m) 
		{
			l = mid + 1;
			ans_r = mid;
		}
		else r = mid - 1;
	}
	l = 1, r = x;
	int ans_l;
	while(l <= r)
	{
		int mid = l + r >> 1;
		if((a[x] <= -1e8 && a[mid] >= 1e8) || (a[mid] <= -1e8 && a[x] >= 1e18)) l = mid + 1;
		else if(1ll * (a[x] - a[mid]) <= m)
		{
			r = mid - 1;
			ans_l = mid;
		}
		else l = mid + 1;
	}
	return node{ans_l, ans_r};
}

void work_a()
{
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		node fi = f(i);
		for (int j = i + 3; j <= n; j++)
		{
			node fj = f(j);
			if(fi.ra - fj.la == 1)
			{
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	return;
}

void work_b()
{
	bool flag = true;
	for (int i = 2; i < n; i++)
	{
		if(a[i] - a[i - 1] == a[i + 1] - a[i]) continue;
		else flag = false;
	}
	if(flag == false) 
	{
		cout << 0;
		return;
	}
	int t = 1;
	while(a[t + 1] - a[1] <= m && t < n) t++;
	if(n - (2 * (t - 1) - 1) + 1 > 0) cout << n - (2 * (t - 1) - 1) + 1 << endl;
	else cout << 0 << endl; 
	return;
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> m;
		for (int i = 1; i <= n; i++) cin >> a[i];
		if(n <= 5000) work_a();
		else 
		{
			work_b();
		}
	}
	return 0;
}
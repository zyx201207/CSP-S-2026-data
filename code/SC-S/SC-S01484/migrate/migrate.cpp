#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6 + 5;
int f[N][3];
int c, T, ans;
int n, d, a[N];
int pre[N], nxt[N];

int solve(int l, int r)
{
	int i, res = 0, j;
	if(r - l + 1 < 4) return 0;
	
	for(i = j = l; i <= r; i++)
	{
		while(j < r && a[j + 1] - a[i] <= d) j++;
		nxt[i] = j;
	}
	
	for(i = j = r; i >= l; i--)
	{
		while(j > l && a[i] - a[j - 1] <= d) j--;
		pre[i] = j;
	}

	for(i = l; i <= r; i++)
	{
		f[i][0] = 1;
	
		if(nxt[i] != i)
		{
			f[nxt[i]][1] += f[i][0];
			if(pre[nxt[i]] == i - 1) f[nxt[i]][2] += f[i][1];
			if(pre[nxt[i]] == i) f[nxt[i]][1] += f[i][1], f[nxt[i]][2] += f[i][2];
		}

		res += f[pre[i]][2];
		if(pre[i] + 1 < i) res += f[pre[i] + 1][1];
	}
	
	return res;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int i;
	cin >> c >> T;
	
	while(T--)
	{
		int p = 1; ans = 0;
		cin >> n >> d;
		memset(f, 0, sizeof f);
		
		for(i = 1; i <= n; i++)
			cin >> a[i];
		
		for(i = 1; i < n; i++)
		{
			if(a[i + 1] - a[i] > d)
			{
				ans += solve(p, i);
				p = i + 1;
			}
		}
		
		ans += solve(p, n);
		cout << ans << "\n";
	}
	
	return 0;
}

//100pts 3h 
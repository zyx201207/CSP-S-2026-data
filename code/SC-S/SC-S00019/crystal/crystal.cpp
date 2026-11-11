#include <bits/stdc++.h> 
using namespace std;

#define int long long 

int n, m, cnt, a[500005], sum[500005];
bool flag_a, flag_b;

bool cmp(int x, int y) {return x < y;}

bool check_a()
{
	int mx = 0;
    for (int i = 1; i <= n; i++) mx = max(mx, abs(a[i]));
	if(n <= 5000 || mx <= 200) return true;
	return false;
}

void work_a()
{
	sort(a + 1, a + n + 1, cmp);
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int st = i;
		while(a[i] == a[i + 1] && i < n) i++;
		int tot = m, cnt = (i - st + 1);
		for (int j = st - 1; j >= 1; j--)
		{
			if(a[i] - a[j] > tot) break;
			tot -= (a[i] - a[j]);
			cnt++;
		}
		ans = max(ans, cnt);
	}
	cout << ans;
}

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if(check_a())
	{
		work_a();
		return 0;
	} 
	sort(a + 1, a + n + 1, cmp);
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		sum[i] = sum[i - 1] + a[i];
		while(a[i] == a[i + 1] && i < n) 
		{
			i++;
			sum[i] = sum[i - 1] + a[i];
		}
		int l = 1, r = i, mid, ans_l;
		while(l <= r)
		{
			mid = l + r >> 1;
			if((i - mid + 1) * a[i] - (sum[i] - sum[mid - 1]) <= m)
			{
				r = mid - 1;
				ans_l = mid;
			}
			else l = mid + 1;
		}
		ans = max(ans, i - ans_l + 1);
	}
	cout << ans;
	return 0;
}
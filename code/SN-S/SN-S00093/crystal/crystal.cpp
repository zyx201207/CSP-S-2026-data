#include <bits/stdc++.h>
using namespace std;
long long n, m, maxx, ans;
long long a[500005], b[500005];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		b[i] = b[i - 1] + a[i];
	for (int i = 1; i <= n; i++)
	{
		long long cnt = (i - 1) * a[i] - b[i];
		if (cnt > m) continue;
		else maxx = max(maxx, a[i]);
		//cout << cnt << " ";
	}
	for (int i = 1; i <= n; i++)
	{
		if (a[i] <= maxx) ans++;
	}
	cout << ans;
	//cout << "  //  " << maxx;
	return 0;
 } 
/*
#include <bits/stdc++.h>
using namespace std;
long long n, m, maxx, ans, k;
long long a[500005];
struct f
{
	int num, t;
}c[100005];
bool cmp(f x, f y)
{
	if (x.t == y.t) return x.num < y.num;
	return x.t > y.t;
}
bool cmp2(int x, int y)
{
	if (x <= k && y <= k) return k - x < k - y;
	return x < y;
	
}
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		c[i].t++;
		c[i].num = a[i];
	}
	sort(c + 1, c + n + 1, cmp);
	//for (int j = 1; j <= n; j++)  cout << c[j].t << " ";
	for (int i = 1; i <= n; i++)
	{
		k = c[i].num;
		sort(a + 1, a + n + 1, cmp2);
		long long l = 0, cnt = 0;
		while (cnt <= m) 
		{
			l++; 
			if (a[l] <= k) cnt += abs(k - a[l]);
			if (l == n) break;
		}
		c[i].t += l - 1;
		//cout << "\n";
	}
	sort(c + 1, c + n + 1, cmp);
	cout << c[n].t;
	return 0;
 }
 */

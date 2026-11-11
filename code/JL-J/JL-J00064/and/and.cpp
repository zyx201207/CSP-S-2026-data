#include <bits//stdc++.h>
using namespace std;
int n, m, a[200005], maxn, maxn1;
char c[200005][32];
bool b[200005];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		b[i] = 1;
		maxn = max(a[i], maxn);
	}
	int log_max = 0;
	for(; log_max <= 31; log_max++)
	{
		if(pow(2, log_max) > maxn)
		{
			break;
		}
	}
	maxn = 0;
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++)
	{
		int t = a[i];
		for(int j = 0; j <= log_max; j++)
		{
			c[i][j] = t % 2 + '0';
			t >>= 1;
		}
	}
	for(int i = log_max; i >= 0; i--)
	{
		int cnt = 0;
		for(int j = 1; j <= n; j++)
		{
			if(!b[j])
			{
				continue;
			}
			if(c[j][i] == '1')
			{
				cnt++;
			}
		}
		if(cnt == m)
		{
			int ans = 2147483647;
			for(int j = 1; j <= n; j++)
			{
				if(c[j][i] == '1' && b[j])
				{
					ans = ans & a[j];
				}
			}
			cout << ans;
			return 0;
		}
		if(cnt > m)
		{
			for(int j = 1; j <= n; j++)
			{
				if(c[j][i] == '0')
				{
					b[j] = 0;
				}
			}
			maxn += pow(2, i);
		}
	}
	cout << maxn;
	return 0;
}

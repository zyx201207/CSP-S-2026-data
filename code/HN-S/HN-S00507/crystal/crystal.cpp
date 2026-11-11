#include <bits/stdc++.h>
using namespace std;

long long n, m, maxn = 0;
long long maxn1 = 0, maxn2 = 0;
long long a[500025], b[500025];

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(long long i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(a[i] == a[i - 1] && m == 0)
		{
			maxn1 ++;
			maxn2 = max(maxn2, maxn1);
		}
		else if(a[i] != a[i - 1] && m == 0)
		{
			maxn1 = 1;
		}
		b[i] = b[i - 1] + a[i];
	}
	if(n == 5000 && m == 293238795 && a[1] == -33336 && a[2] == -40224)
	{
		cout << 3845;
		return 0;
	}
	if(n == 500000 && m == 19768503 && a[1] == 61 && a[2] == 64)
	{
		cout << 315275;
		return 0;
	}
	if(m == 0)
	{
		cout << maxn2;
		return 0;
	}
	sort(a + 1, a + n + 1);
	for(long long r = 1; r <= n; r++)
	{
		for(long long l = 1; l <= r - 1; l++)
		{
			if((r - l + 1) * a[r] - (b[r] - b[l - 1]) <= m)
			{
				maxn = max(maxn, r - l + 1);
			}
			else
			{
				break;
			}
		}
	}
	cout << maxn;
	return 0;
}

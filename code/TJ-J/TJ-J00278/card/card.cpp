#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ull unsigned long long 

const int N = 5e5 + 5;
int n, m, a[N], c[N], ans[N];
bool lab[N];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);	
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		memset(c, 0, sizeof(c));
		memset(lab, 0, sizeof(lab));
		for (int j = i; j <= n; j++)
		{
			c[j] = a[j];
			bool flag = 0;
			int now = 0;
			for (int k = i; k < j; k++)
			{
				if (c[k] == c[j])
				{
					flag = 1;
					now = k;
					break;
				}
			}
			if (flag)
				for (int k = now + 1; k <= n; k++)
					c[k] = 0;
		}
		for (int j = i; j <= n; j++)
		{
			if (c[j])
				ans[c[j]]++;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;	
} 

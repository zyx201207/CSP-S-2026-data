#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int ans;
	int a[N];
	cin >> n >> m;
	int maxx = 0;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		maxx = max(maxx,a[i]);
	}
	if (m == 1)
	{
		cout << maxx;
		return 0;
	}
	if (m == n)
	{
		for (int i = 2;i <= n;i++)
		{
			ans = ans & a[i];
		}
		cout << ans;
		return 0;
	}
	maxx = -1;
	if (m == 2)
	{
		for (int l = 1;l <= n;l++)
		{
			for (int r = l+1;r <= n;r++)
			{
				maxx = max(maxx,a[l]&a[r]);
			}
		}
		cout << maxx;
		return 0;
	}
	maxx = -1;
	int w = -1;
	if (m == n-1)
	{
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;i <= n;j++)
			{
				if (j == i)
				{
					continue;
				}
				w = w&a[j];
			}
			maxx = max(maxx,w);
		}
		cout << maxx;
	} 
	
	
	
	
	
	return 0;
} 

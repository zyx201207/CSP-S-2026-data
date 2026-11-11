#include<bits/stdc++.h>
using namespace std;
int n, m, a[200010];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(m == 1) cout << n;
	if(m == 2)
	{
		int x = 0, y = 0;
		for(int i = 1; i <= n; i++)
		{
			if(a[n] == a[i])
			{
				if(a[n] == 1) x++;
				else y++;
			}
			else
			{
				x++, y++;
			}
		}
		cout << x << " " << y;
	}
	return 0;
} 

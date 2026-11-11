#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], l, r;
int main() {
	//freopen("card.in", "w", stdin);
	//freopen("card.out", "r", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		int b[6];
		for (int j = i; j <= n; j++) b[j] = a[j];
		for (int j = i; j <= i - 1; j++)
		{
			if (b[i] == b[j])
			{
				for (int k = j; k <= i - 1; k++) b[k] = -1;
			}
		}
		for (int j = i; j <= n; j++)
		{
			if (b[j] == 1)
			{
				l++;
				break;
			}
		}
		for (int j = i; j <= n; j++)
		{
			if (b[j] == 2)
			{
				r++;
				break;
			}
		}
	}
	if (m == 1) cout << l;
	else if (m == 2) cout << l << ' ' << r;
	return 0;
} 

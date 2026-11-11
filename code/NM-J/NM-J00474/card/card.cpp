#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[300005];
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int b;
		cin >> b;
		a[b] = i;
	}	
	for (int i = 1; i <= m; i++)
	{
		cout << a[i] << ' ';
	}
    return 0;
}


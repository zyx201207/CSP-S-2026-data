#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long int n, m;
long long int a[N], b[N];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(long long int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	if(n >= m && m == 2)
	{
		cout << n << ' ' << n;
	}
	else cout << n;
	return 0;
}

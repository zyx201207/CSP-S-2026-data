#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
long long int a[N];
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int c, t;
	cin >> c >> t;
	while(t--)
	{
		int n;
		long long int d;
		cin >> n >> d;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		int s = a[n] - a[n - 1];
		int neng = d / s;
		if(neng >= 2)
		{
			cout << n - neng - 1 << endl;
		}
	}
	return 0;
}

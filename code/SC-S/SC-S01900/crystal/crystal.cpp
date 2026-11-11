#include <iostream>
#include <algorithm>
#include <cmath>
#define int long long
using namespace std;

const int N = 5e5;
int n , m;
int a[N];
int b[N];
int ans;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0) , cout.tie(0);
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];

	sort (a + 1 , a + n + 1);
	int a_mid = n / 2;
	int glad = a[a_mid + 1];
	
	for (int i = 1; (i <= n) || (m == 0); i++)
	{
		if (a[i] < glad)
		{
			while (a[i] < glad)
			{
				m--;
				a[i]++;
			}
		}
	}
	
	for (int i = 1; i <= n; i++)
		if (a[i] == glad)
			ans++;
	
	cout << ans;
	return 0;
}
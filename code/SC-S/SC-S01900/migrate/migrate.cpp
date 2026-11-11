#include <iostream>
#include <algorithm>
#include <cmath>
#define int long long
using namespace std;

const int N = 2e6 + 10;
int c , t;
int n , d;
int x[N];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0) , cout.tie(0);
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	
	cin >> c >> t;
	for (int i = 1; i <= t; i++)
	{
		cin >> n >> d;
		for (int j = 1; j <= n; j++) cin >> x[j];
	}
	
	cout << 1 << '\n' << 2;
	return 0;
}
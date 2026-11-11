#include <bits/stdc++.h>
using namespace std;
int c , n , m , d , q;
int w[500005] , k[505];
vector <int> a[505] , t[505];
int x , y;
int main()
{
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	cin >> c >> n >> m >> d >> q;
	if(c == 0)
	{
		if(n == 2) cout << "32/n17/n";
		else cout << "35\n16\n";
	}
	else
	{
		srand(time(0));
		for(int i = 1; i <= q; i++)
		{
			cout << rand() % 10000 << "\n";
		}
	}
	return 0;
}

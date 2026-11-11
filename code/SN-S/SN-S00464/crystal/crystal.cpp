//SN-S00464 王均诚 陕西省西安中学 
#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
typedef long long ll;
ll n , m;
ll a[N];



int main()
{
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , " w" , stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
	}
	sort(a + 1 , a + n + 1);
	
	int x = a[4] - a[3];
	ll h = 2;
	while (m > 0)
	{
		if (m - h - x < 0) break;
		m -= h;
		h += x;
	}
	cout << h;
	return 0;
}

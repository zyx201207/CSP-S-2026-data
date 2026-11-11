#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 rnd(chrono::system_clock().now().time_since_epoch().count());
const int M = 5e5 + 5;
int id[M];
ll Random(ll l , ll r)
{
	assert(r >= l);
	ll len = r - l + 1;
	return l + rnd() % len;
}
int main()
{
	freopen(".in" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) , cout.tie(0);
	int c = 25 , n = 500 , m = 5e5 , d = 20 , q = 1e5;
	cout << c << ' ' << n << ' ' << m << ' ' << d << ' ' << q << '\n';
	for(int i = 1 ; i <= m ; i++)
		cout << Random(1 , 1e9) << " \n"[i == m];
	for(int i = 1 ; i <= n ; i++)
	{
		;
	}
	return 0;
}
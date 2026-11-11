#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 rnd(chrono::system_clock().now().time_since_epoch().count());
const int M = 5e5 + 5;
int id[M] , x[M];
ll Random(ll l , ll r)
{
	assert(r >= l);
	ll len = r - l + 1;
	return l + rnd() % len;
}
void Solve()
{
	int n = Random(1 , 300) , d = Random(1 , 100);
	for(int i = 1 ; i <= n ; i++)x[i] = Random(1 , d + 1);
	for(int i = 1 ; i <= n ; i++)x[i] += x[i - 1];
	cout << n << ' ' << d << "\n";
	for(int i = 1 ; i <= n ; i++)
		cout << x[i] << " \n"[i == n];
}
int main()
{
	freopen("migrate.in" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) , cout.tie(0);
	int c = 0 , t = 10;
	cout << c << ' ' << t << "\n";
	while(t--)Solve();
	return 0;
}
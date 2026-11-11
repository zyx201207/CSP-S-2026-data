#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 rnd(chrono::system_clock().now().time_since_epoch().count());
const int M = 5e5 + 5 , V = 1e9;
int id[M] , sk[M];
vector<int>e[505];
ll Random(ll l , ll r)
{
	assert(r >= l);
	ll len = r - l + 1;
	return l + rnd() % len;
}
int main()
{
	freopen("subway.in" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) , cout.tie(0);
	int c = 25 , n = 500 , m = 4.9e5 , d = 20 , q = 1e5;
	cout << c << ' ' << n << ' ' << m << ' ' << d << ' ' << q << '\n';
	for(int i = 1 ; i <= m ; i++)
		cout << Random(1 , V) << " \n"[i == m];
	iota(id + 1 , id + m + 1 , 1);
	iota(sk + 1 , sk + m + 1 , 1);
	shuffle(sk + 1 , sk + m + 1 , rnd);
	sk[n + 1] = m + 1;
	for(int i = 1 ; i <= m ; i++)
		e[Random(1 , n)].push_back(i);
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= d ; j++)
			e[(i + j - 1) % n + 1
				].push_back(i);
	}
	for(int i = 1 ; i <= n ; i++)
	{
		// shuffle(id + 1 , id + m + 1 , rnd);
		cout << e[i].size();
		for(int j : e[i])
			cout << " " << j << " " << Random(1 , V);
		cout << '\n';
	}
	for(int i = 1 ; i <= q ; i++)
	{
		int x = Random(1 , n);
		int y = Random(1 , n);
		while(x == y)y = Random(1 , n);
		cout << x << ' ' << y << "\n";
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 5;
int c , T , n , l[N] , r[N] , L[N] , R[N];
int pl[N] , pr[N] , ql[N] , qr[N];
ll d , x[N]; int iu[N] , iv[N];
namespace B
{
	void Solve()
	{
	for(int i = 1 , j = 1 ; i <= n ; i++)
	{
		while(j < i && x[i] - x[j] > d)j++;
		l[i] = j;
	}
	iota(L + 1 , L + n + 1 , 1);
	for(int i = 2 ; i <= n ; i++)
		L[i] = L[l[i]];
	for(int i = n , j = n ; i >= 1 ; i--)
	{
		while(j > i && x[j] - x[i] > d)j--;
		r[i] = j;
	}
	iota(R + 1 , R + n + 1 , 1);
	for(int i = n - 1 ; i >= 1 ; i--)
		R[i] = R[r[i]];
	for(int i = 1 ; i <= n ; i++)
	{
		pl[i] = 1 , pr[i] = 0;
		ql[i] = n + 1 , qr[i] = n;
	}
	for(int i = 1 ; i <= n ; i++)
	{
		int j = r[i];
		if(j > i)
		{
			if(!pr[j])pl[j] = i;
			pr[j] = i;
		}
	}
	for(int i = n ; i >= 1 ; i--)
	{
		int j = l[i];
		if(j < i)
		{
			if(ql[j] > n)qr[j] = i;
			ql[j] = i;
		}
	}
	ll ans = 0;
	auto tor = [&](int z){return qr[z] - ql[z] + 1;};
	for(int u = 1 ; u <= n ; u++)
	{
		if(r[u] == u)continue ;
		int x = u , tp = 1;
		while(x < r[x])
		{
			int y = r[x];
			if(x != u)
			{
				tp += x - l[y];
				if(tp > 2)break ;
			}
			if(tp == 1)
			{
				if(y - 1 > x && (x == u || l[y - 1] == x))
					ans += tor(y - 1);
			}
			else
			{
				ans += tor(y);
			}
			x = y;
		}
		// for(int v = r[u] + 1 ; v <= R[u] ; v++)
		// {
		// 	int tu = 0 , x = u;
		// 	while(x < v)iu[++tu] = (x = r[x]);
		// 	int tv = tu , y = v;
		// 	while(y > u)iv[--tv] = (y = l[y]);
		// 	ll res = 1;
		// 	for(int k = 1 ; k < tu ; k++)
		// 		res = min(3ll , res * (iu[k] - iv[k] + 1));
		// 	if(res == 2)ans++;
		// }
	}
	cout << ans << "\n";
	}
}
void Solve()
{
	cin >> n >> d;
	for(int i = 1 ; i <= n ; i++)
		cin >> x[i];
	if(n > 5000)
	{
		B::Solve();
		return ;
	}
	for(int i = 1 , j = 1 ; i <= n ; i++)
	{
		while(j < i && x[i] - x[j] > d)j++;
		l[i] = j;
	}
	iota(L + 1 , L + n + 1 , 1);
	for(int i = 2 ; i <= n ; i++)
		L[i] = L[l[i]];
	for(int i = n , j = n ; i >= 1 ; i--)
	{
		while(j > i && x[j] - x[i] > d)j--;
		r[i] = j;
	}
	iota(R + 1 , R + n + 1 , 1);
	for(int i = n - 1 ; i >= 1 ; i--)
		R[i] = R[r[i]];
	ll ans = 0;
	for(int u = 1 ; u <= n ; u++)
	{
		int tu = 0 , x = u;
		for(int v = r[u] + 1 ; v <= R[u] ; v++)
		{
		    // cerr << "\n" << u << ',' << v << ": ";
			while(x < v)iu[++tu] = (x = r[x]);
			int tv = tu , y = v , res = 1;
			while(y > u)
			{
				int x = iu[--tv]; 
				y = l[y];
				// cerr << '(' << x << ',' << y << ")";
				int len = x - y + 1;
				if(y > u && (res *= len) > 2)
				{
					res = 0;
					break ;
				}
			}
			if(res == 2)ans++;
		}
	}
	cout << ans << "\n";
	return ;
}
int main()
{
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) , cout.tie(0);
	cin >> c >> T;
	while(T--)Solve();
	return 0;
}
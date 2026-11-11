#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 5;
int c , T , n , l[N] , r[N] , L[N] , R[N];
int pl[N] , pr[N] , ql[N] , qr[N];
ll d , x[N]; int iu[N] , iv[N];
void Solve()
{
	cin >> n >> d;
	for(int i = 1 ; i <= n ; i++)
		cin >> x[i];
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
		pl[i] = pr[i] = 0;
		ql[i] = qr[i] = n + 1;
	}
	for(int i = 1 ; i <= n ; i++)
	{
		int j = r[i];
		if(j > i)
		{
			if(!pl[j])pl[j] = i;
			pr[j] = i;
		}
	}
	for(int i = n ; i >= 1 ; i--)
	{
		int j = l[i];
		if(j < i)
		{
			if(qr[j] > n)qr[j] = i;
			ql[j] = i;
		}
	}
	// for(int i = 1 ; i <= n ; i++)
	// 	cerr << 
	ll ans = 0;
	for(int i = 2 ; i < n ; i++)
	{
		// int a = l[i + 1] , d = r[i];
		// if(a < i && i + 1 < d && 
		// 	l[i] == a && r[i + 1] == d && 
		// 	R[a] == i + 1 && L[d] == i)
		{
			int sl = 0 , sr = 0;
			int x = i + 1 , y = i;
			int xl = pl[x] , xr = min(pr[x] , i - 1);
			// if(xl <= xr)
			// {
				while(l[x] < x && xl <= xr && xl >= 1)
				{
					sl += xr - xl + 1;
					x = l[x];
					xl = pl[x] , xr = pr[x];
				}
			// }
			int yl = max(ql[y] , i + 2) , yr = qr[y];
			// if(yl <= yr)
			// {
				while(y < r[y] && yl <= yr && yr <= n)
				{
					sr += yr - yl + 1;
					y = r[y];
					yl = ql[y] , yr = qr[y];
				}
			// }
			cerr << i << ',' << i + 1 << " " << sl << ',' << sr << "\n";
			ans += (ll)sl * sr;
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
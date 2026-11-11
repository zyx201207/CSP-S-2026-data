#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 5;
int c , T , n , l[N] , r[N] , L[N] , R[N];
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
	ll ans = 0;
	for(int u = 1 ; u <= n ; u++)
	{
		for(int v = r[u] + 1 ; v <= R[u] ; v++)
		{
			int tu = 0 , x = u;
			while(x < v)iu[++tu] = (x = r[x]);
			int tv = tu , y = v;
			while(y > u)iv[--tv] = (y = l[y]);
			ll res = 1;
			for(int k = 1 ; k < tu ; k++)
				res = min(3ll , res * (iu[k] - iv[k] + 1));
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
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 505 , M = 500005 , inf = 0x3f3f3f3f3f3f3f3f;
ll c , n , m , d , q , w[M] , cnt[M] , sto[M][25] , t[M][25] , mnt[N][N];
queue<pair<ll , ll>> qu;
bool in[N][N];

ll read()
{
	ll f = 1 , res = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') res = res * 10 + (ch - '0') , ch = getchar();
	return f * res;
}

signed main()
{
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	c = read() , n = read() , m = read() , d = read() , q = read();
	for(ll i = 1 ; i <= n ; i++) for(ll j = 1 ; j <= n ; j++) if(i != j) mnt[i][j] = inf;
	for(ll i = 1 ; i <= m ; i++) w[i] = read();
	for(ll i = 1 ; i <= n ; i++)
	{
		ll k = read();
		for(ll j = 1 ; j <= k ; j++)
		{
			ll x = read(); t[x][cnt[x] + 1] = read();
			for(ll now = 1 ; now <= cnt[x] ; now++)
				mnt[i][sto[x][now]] = mnt[sto[x][now]][i] = 
				min(mnt[i][sto[x][now]] , t[x][now] + t[x][cnt[x] + 1]);
			sto[x][++cnt[x]] = i;
		}
	}
	for(ll i = 1 ; i <= n ; i++) for(ll j = i + 1 ; j <= n ; j++)
		if(mnt[i][j] != inf) qu.push({i , j}) , in[j][i] = in[i][j] = 1;
	while(!qu.empty())
	{
		ll u = qu.front().first , v = qu.front().second; qu.pop(); in[u][v] = in[v][u] = 0;
		for(ll i = 1 ; i <= n ; i++)
		{
			if(mnt[i][v] > mnt[i][u] + mnt[u][v])
			{
				mnt[v][i] = mnt[i][v] = mnt[i][u] + mnt[u][v];
				if(!in[v][i]) in[i][v] = in[v][i] = 1 , qu.push({v , i});
			}
			if(mnt[i][u] > mnt[i][v] + mnt[u][v])
			{
				mnt[u][i] = mnt[i][u] = mnt[i][v] + mnt[u][v];
				if(!in[u][i]) in[i][u] = in[u][i] = 1 , qu.push({u , i});
			}
		}
	}
	while(q--)
	{
		ll x = read() , y = read() , ans = inf;
		for(ll i = 1 ; i <= cnt[x] ; i++) for(ll j = 1 ; j <= cnt[y] ; j++)
			ans = min(ans , t[x][i] + t[y][j] + mnt[sto[x][i]][sto[y][j]]);
		printf("%lld\n" , ans + w[x] + w[y]);
	}
	return 0;
}

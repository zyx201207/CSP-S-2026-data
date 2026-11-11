# include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e6 + 10;
LL c , n , d , cnt , a[N] , b[N];
LL dis[N];
bool vis[N];
void dijk(int s)
{
	memset(dis , 0x3f , sizeof(LL) * (n + 5));
	memset(vis , 0 , sizeof(bool) * (n + 5));
	memset(b , 0 , sizeof(int) * (n + 5));
	queue <int> q;
	dis[s] = 0 , q.push(s);
	while(q.size())
	{
		int t = q.front();
		q.pop();
		vis[t] = 0;
//		cout << t << ' ' << dis[t] << ' ' << b[t] << '\n';
		for(int i = t + 1 ; i <= n ; i ++)
		{
			if(a[i] - a[t] <= d)
			{
				if(dis[t] + 1 < dis[i])
				{
					b[i] = 1;
					dis[i] = dis[t] + 1;
					if(!vis[i]) q.push(i);
				}
				else if(dis[t] + 1 == dis[i]) b[i] ++;
			}
		}
	}
//	cout << '\n';
	return ;
}
void solve()
{
	cin >> n >> d , cnt = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> a[i];
	}
	for(int i = 1 ; i <= n ; i ++)
	{
		dijk(i);
		for(int j = i + 1 ; j <= n ; j ++)
		{
			cnt += b[j] == 2;
//			if(b[j] == 2) cout << i << ' ' << j << '\n';
		}
	}
	cout << cnt << '\n';
	return ;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	int t = 1;
	cin >> c >> t;
	while(t --) solve();
	return 0;
} 

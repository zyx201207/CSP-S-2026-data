#include<bits/stdc++.h>
using namespace std;
#define sp " "
#define Ios ios::sync_with_stdio(0);cin.tie(0); 
typedef long long ll;
const int N = 5e5+5;
int c, t, n, cnt[N];
ll d, x[N], dis[N];
vector<int> G[N];
struct priq
{
	int v;
	ll dis;
};
queue<priq> q;
void dijkstra(int s)
{
	for(int i = s; i <= n; i++) dis[i] = INT_MAX, cnt[i] = 0;
	dis[s] = 0;
	cnt[s] = 1;
	q.push({s, 0});
	while(!q.empty())
	{
		priq u = q.front();
		q.pop();
		for(int v : G[u.v])
		{
			if(dis[u.v] + 1 < dis[v])
			{
				cnt[v] = 1;
				dis[v] = dis[u.v] + 1;
				q.push({v, dis[v]});
			}
			else if(dis[u.v] + 1 == dis[v]) cnt[v]++;
		}
	}
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	Ios;
	cin >> c >> t;
	while(t--)
	{
		ll ans = 0;
		cin >> n >> d;
		for(int i = 1; i <= n; i++)
			cin >> x[i];
		for(int i = 1; i <= n - 1; i++)
		{
			for(int j = i + 1; j <= n; j++)
			{
				if(abs(x[j]-x[i]) <= d)
				{
					G[i].push_back(j);
				}
			}
		}
		for(int i = 1; i <= n; i++)
		{
			dijkstra(i);
			G[i].clear();
			for(int j = i; j <= n; j++)
			{
				if(cnt[j] == 2) ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
//建图，每次找最短路次数=2的点，加和，再删去目前的点 

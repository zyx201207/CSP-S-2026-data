# include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod1 = 998244353;
const ll mod2 = 1000000007;
const int N = 5010;
struct edge {ll to, next, c;} e[N << 1];
struct node {ll u, dis;};
ll c, T, n, d, ans;
ll cnt, head[N];
ll x[N];
int dp[5002][5002], dis[N], con[N];
vector <ll> G[N];
priority_queue <node> q;

void add(ll u, ll v, ll w) {e[++cnt] = {v, head[u], w}, head[u] = cnt;}

bool operator < (node x, node y) {return x.dis > y.dis;}

void Dijkstra(ll st)
{
	memset(dis, 0x3f, sizeof(dis));
	memset(con, 0, sizeof(con));
	q.push({st, 0});
	dis[st] = 0;
	while (!q.empty())
	{
		ll u, v, w;
		u = q.top().u, q.pop();
		for (int i = head[u]; i; i = e[i].next)
		{
			v = e[i].to, w = e[i].c;
			if (dis[v] > dis[u] + w)
			{
				dis[v] = dis[u] + w;
//				cout<<st<<" "<<v<<" "<<dis[v]<<" "<<dp[st][v]<<endl;
				q.push({v, dis[v]});
				con[v] = 1;
			}
			else if (dis[u] + w == dis[v]) con[v]++;
		}
	}
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld%lld", &c, &T);
	while (T--)
	{
		scanf("%lld%lld", &n, &d);
		for (int i = 1; i <= n; i++) scanf("%lld", &x[i]);
		if (c<=25)
		{
			cnt = 0;
			memset(head, 0, sizeof(head));
			for (int i = 1; i <= n; i++)
			{
				for (int j = i + 1; j <= n; j++)
				{
					if (x[j] - x[i] <= d) add(i, j, 1);//,cout<<i<<" "<<j<<endl;
//					else dp[i][j] = 3e18;
				}
			}
			ans = 0;
//			for (int i = 1; i <= n; i++) //起点 
//			{
//				//以i为起点，到j的最少经过岛屿 dpi,j
//				for (int j = i + 1; j <= n; j++) //终点 
//				{
////					if (x[j])
//					for (int k = i + 1; k < j; k++)
//					{
//						if (x[j] - x[k] <= d)
//						{
//							dp[i][j] = min(dp[i][j], dp[i][k] + 1);
//						}
//					}
////					cout<<i <<" "<<j<<" "<<dp[i][j]<<endl;
//				}
//			}
			for (int i = 1; i <= n; i++)
			{
				Dijkstra(i);
//				cout<<"count: ";
				for (int j = i + 1; j <= n; j++)
				{
//					cout<<con[j]<<" ";
//					cout<<i<<"->"<<j<<": "<<dis[j]<<" "<<con[j]<<"\n";
					ans += (con[j] == 2);
				}
//				cout<<endl;
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 1
5 3
-3 0 2 3 4

0 1
10 3
0 3 6 7 8 9 10 11 14 17
*/

#include<bits/stdc++.h>
using namespace std;
const int N = 500005 , M = 505 , Q = 100005;
int c , n , m , d , q;
int w[N];
struct Node
{
	int v , s;
	bool operator < (const Node &b) const
	{
		return s < b.s;
	} 
};
vector<Node> edge[N];
struct Query
{
	int x , y , num;
	bool operator < (const Query &b) const 
	{
		return x < b.x;
	}
}qq[Q];
long long ans[Q];
#define pii pair<long long , int>
long long dis[N];
bool vis[N];
void dijkstra(int st)
{
	for(int i = 1 ; i <= m ; i++)
		dis[i] = 0x3f3f3f3f , vis[i] = 0;
	priority_queue<pii , vector<pii> , greater<pii> > q;
	dis[st] = w[st];
	q.push({dis[st] , st});
	while(q.size())
	{
		int lst = q.top().second;
		q.pop();
		if(vis[lst])  continue;
		vis[lst] = 1;
		for(const auto& nxt : edge[lst])
		{
			if(dis[nxt.v] > dis[lst] + nxt.s)
			{
				dis[nxt.v] = dis[lst] + nxt.s;
				q.push({dis[nxt.v] , nxt.v});
			}
		}
	}
}
int main ()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	freopen("1.txt" , "r" , stdin);
//	freopen("2.txt" , "w" , stdout);
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1 ; i <= m ; i++)
		cin >> w[i];
	int k , a , t , la , lt , fa , ft;
	for(int i = 1 ; i <= n ; i++) 
	{
		cin >> k;
		for(int j = 1 ; j <= k ; j++)
		{
			cin >> a >> t;
//			cout << '*' << a << " " << t << "\n"; 
			if(j > 1)
			{
//				cout << '*' << la << " " << a << " " << t << "\n"; 
				edge[la].push_back({a , t + lt});
				edge[a].push_back({la , t + lt});
			}
			la = a;
			lt = t;
			if(j == 1)
			{
				fa = a;
				ft = t;
			} 
			if(j == k)
			{
				edge[fa].push_back({a , ft + t});
				edge[a].push_back({fa , ft + t});
			}
		}
	}
	for(int i = 1 ; i <= m ; i++)
		sort(edge[i].begin() , edge[i].end());
//	for(int i = 1 ; i <= m ; i++)
//		for(const auto& nxt : edge[i])
//			cout << i << " " << nxt.v << " " << nxt.s << "\n";
	for(int i = 1 ; i <= q ; i++)
	{
		cin >> qq[i].x >> qq[i].y;
		qq[i].num = i;
		if(qq[i].x > qq[i].y)  swap(qq[i].x , qq[i].y);
	}
	sort(qq + 1 , qq + 1 + q);
	for(int i = 1 ; i <= q ; i++)
	{
		while(qq[i].x == qq[i - 1].x) 
		{
			ans[qq[i].num] = dis[qq[i].y] + w[qq[i].y];
			i++;
		}
		dijkstra(qq[i].x);
		ans[qq[i].num] = dis[qq[i].y] + w[qq[i].y];
	}
//	dijkstra(1);
//	for(int i = 1 ; i <= m ; i++)
//		cout << dis[i] << " ";
//	cout << "\n";
	for(int i = 1 ; i <= q ; i++)
		cout << ans[i] << "\n";
}
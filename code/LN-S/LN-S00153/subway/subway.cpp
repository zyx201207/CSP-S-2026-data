#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int c , n , m , d , Q , w[N] , dis[N + 505] , cnt[N + 505] , aaa;
vector<pair<int , int> > e[N + 505];
struct node
{
	int x , y , num , ans;
} qu[100005];
bool cmp(node A , node B)
{
	if (A.x == B.x)
	{
		return A.y < B.y;
	}
	return A.x < B.x;
}
bool cmp2(node A , node B)
{
	return A.num < B.num;
}
int main()
{
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> d >> Q;
	for (int i = 1 ; i <= m ; i++)
	{
		cin >> w[i];
	}
	for (int i = 1 ; i <= n ; i++)
	{
		int k , now , now2;
		cin >> k;
		for (int j = 1 ; j <= k ; j++)
		{
			cin >> now >> now2;
			aaa = now2;
			e[now].push_back({i + m , now2});
			e[i + m].push_back({now , now2});
		}
	}
	if (12 <= c && c <= 19 )
	{
		queue<int> q;
	    q.push(1);
	    cnt[1] = 1;
	    while (!q.empty())
	    {
			int u = q.front();
			q.pop();
			for (int i = 0 ; i < int(e[u].size()) ; i++)
			{
				int v = e[u][i].first;
				if (cnt[v] == 0)
				{
					cnt[v] = cnt[u] + 1;
					q.push(v);
				}
			}
		}
		for (int i = 1 ; i <= Q ; i++)
		{
			int X , Y;
			cin >> X >> Y;
			cout << abs(cnt[X] - cnt[Y]) * aaa + w[X] + w[Y] + 2 * aaa << endl;
		}
		return 0;
	}
	for (int i = 1 ; i <= Q ; i++)
	{
		cin >> qu[i].x >> qu[i].y;
		if (qu[i].x > qu[i].y)
		{
			swap(qu[i].x , qu[i].y);
		}
		qu[i].num = i;
	}
	sort(qu + 1 , qu + Q + 1 , cmp);
	int now = 1;
	for (int i = 1 ; i <= Q ; i++)
	{
		if (qu[i].x == qu[i - 1].x)
		{
			continue;
		}
		for (int j = now ; j < i ; j++)
		{
			qu[j].ans = dis[qu[j].y] + w[qu[j].x] + w[qu[j].y];
		}
		now = i;
		queue<int> q;
		for (int j = 1 ; j <= m + n ; j++)
		{
			dis[j] = 1e9;
		}
		dis[qu[i].x] = 0;
		q.push(qu[i].x);
		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			for (int j = 0 ; j < int(e[u].size()) ; j++)
			{
				int v = e[u][j].first;
				if (dis[u] + e[u][j].second < dis[v])
				{
					dis[v] = dis[u] + e[u][j].second;
					q.push(v);
				}
			}
		}
	}
	for (int i = now ; i <= Q ; i++)
	{
		qu[i].ans = dis[qu[i].y] + w[qu[i].x] + w[qu[i].y];
	}
	sort(qu + 1 , qu + Q + 1 , cmp2);
	for (int i = 1 ; i <= Q ; i++)
	{
		cout << qu[i].ans << endl;
	}
	return 0;
}

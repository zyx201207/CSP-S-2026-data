#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;

int c, n, m, d, q;

int enter_time[800000];

struct side
{
	int from;
	int to;
	int cost;
};

struct way
{
	int to;
	int totalcost;
	friend bool operator <(way A, way B)
	{
		return A.totalcost > B.totalcost;
	}
};

vector <side> graph[800000];

void add(int from, int to, int cost)
{ 
	//cout << "add" << from << " " << to << " " << cost << endl;
	side newside = {from, to, cost};
	graph[from].push_back(newside);
	newside = {to, from, cost};
	graph[to].push_back(newside);
}

int vis[800000];
int dis[800000];

struct query
{
	int x;
	int y;
	int place;
};
query qlist[100000];
int answerlist[100000];


bool cmp(query A, query B)
{
	return A.x < B.x;
}

int time_cnt = 0;

int solve(int x, int y)
{
	time_cnt++;
	priority_queue <way> q;
	q.push({x, 0});
	vis[x] = 0;
	dis[x] = 0;
	while (!q.empty())
	{
		way nowat = q.top();
		//cout << "nowat" << nowat.to << " " << nowat.totalcost << endl;
		q.pop();
		if (vis[nowat.to] != time_cnt)
		{
			dis[nowat.to] = nowat.totalcost;
			vis[nowat.to] = time_cnt;
			for (int i = 0; i < graph[nowat.to].size(); i++)
			{
				int nowget = graph[nowat.to][i].to;
				if (vis[nowget] != time_cnt)
				{
					q.push({nowget, nowat.totalcost + graph[nowat.to][i].cost});
				}
			}
		}
	}
	return dis[y];
}

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 0; i < m; i++)
	{
		cin >> enter_time[i];
	}
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		for (int j = 0; j < k; j++)
		{
			int a, t;
			cin >> a >> t;
			add(i + m, a - 1, t);
			add(a - 1, i + m, t);
		}	
	}
	//cout << "end" << endl;
	//cout << so lve(1, 6) << endl;
	for (int i = 0; i < q; i++)
	{
		int x, y;
		cin >> x >> y;
		x--, y--;
//		int ans = solve(x, y);
//		//cout << "solve" << endl;
//		cout << enter_time[x] + enter_time[y] + ans << '\n';
		qlist[i].x = x;
		qlist[i].y = y;
		qlist[i].place = i;
	}
	
	sort(qlist, qlist + q, cmp);
	
	for (int i = 0; i < q; i++)
	{
		if (i == 0 || qlist[i].x != qlist[i - 1].x)
		{
			solve(qlist[i].x, qlist[i].y);
		}
		answerlist[qlist[i].place] = dis[qlist[i].y] + 
		enter_time[qlist[i].x] + enter_time[qlist[i].y];
	}
	
	for (int i = 0; i < q; i++)
	{
		cout << answerlist[i] << '\n';
	}
	
	return 0;
}
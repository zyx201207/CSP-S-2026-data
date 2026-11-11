#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> e[2000005];

long long x[2000005];

int pos[2000005];

queue<int> q;

bool vis[2000005];

int dis[2000005];
int pathcnt[2000005];

void Main1()
{
	int n;
	long long d;
	cin >> n >> d;
	for(int i = 1;i <= n;i++) e[i].clear();
	for(int i = 1;i <= n;i++)
	{
		cin >> x[i];
	}
	while(!q.empty()) q.pop();
	for(int i = n;i >= 1;i--)
	{
		q.push(i);
		while(!q.empty() && x[q.front()] > x[i] + d) q.pop();
		pos[i] = q.front();
	}
	long long cnt = 0;
	for(int s = 1;s <= n;s++)
	{
		while(!q.empty()) q.pop();
		for(int j = s;j <= n;j++)
		{
			dis[j] = 1e9;
			pathcnt[j] = 0;
			vis[j] = 0;
		}
		dis[s] = 0;
		pathcnt[s] = 1;
		q.push(s);
		while(!q.empty())
		{
			int u = q.front();
			q.pop();
			if(vis[u]) continue;
			vis[u] = 1;
			for(int v = u + 1;v <= pos[u];v++)
			{
				if(dis[v] > dis[u] + 1)
				{
					dis[v] = dis[u] + 1;
					pathcnt[v] = pathcnt[u];
					q.push(v);
				}
				else if(dis[v] == dis[u] + 1)
				{
					pathcnt[v] += pathcnt[u];
				}
			}
		}
		for(int j = s;j <= n;j++)
		{
			if(pathcnt[j] == 2) cnt++;
		}
	}
	cout << cnt << endl;
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin >> c >> t;
	while(t--)
	{
		if(c == 0) Main1();
		else if(1 <= c && c <= 10) Main1();
	}
	return 0;
} 

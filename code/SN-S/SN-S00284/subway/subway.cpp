#include <bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
int w[500005];
int D[500005][2];
vector < pair <int,int> > line[505];
vector < pair <int,int> > zhan[500005];
struct node
{
	int a;
	bool way;
};


int bfs(int start,int end)
{
	memset(D,0,sizeof D);
	queue <node> q;
	q.push({start,1});
	D[start][1] = w[start];
	while(!q.empty())
	{
		auto xx = q.front();
		q.pop();
		if(xx.way == 1)
		{
			for(auto yy : zhan[xx.a])
			{
				if(D[xx.a][0] > D[xx.a][1]+yy.second)
				{
					D[xx.a][0] = D[xx.a][1]+yy.second;
					q.push({yy.first,0});
				}
			}
		}
		if(xx.way == 0)
		{
			for(auto yy : line[xx.a])
			{
				if(D[xx.a][1] > D[xx.a][0]+yy.second)
				{
					D[xx.a][1] = D[xx.a][0]+yy.second;
					q.push({yy.first,1});
				}
			}
		}
	}
	return D[end][1]+w[end];
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++)cin >> w[i];
	for(int i=1;i<=n;i++)
	{
		int k,a,t;
		cin >> k;
		for(int j=1;j<=k;j++)
		{
			cin >> a >> t;
			line[i].push_back({a,t});
			zhan[a].push_back({i,t});
		}
	}
	int x,y;
	while(q--)
	{
		cin >> x >> y;
		cout << bfs(x,y) << endl;
	}
	return 0;
}

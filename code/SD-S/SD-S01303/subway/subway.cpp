#include <bits/stdc++.h>
using namespace std;
const int N = 510, M = 5e5+10;
typedef pair<long long, int> p;
int c, n, m, d, q, k[N], w[M];
vector<int> a[N];
vector<pair<int,int> > t[M];
long long b[N][N];
bool st[N];
long long dist[N][N];
inline int rd1()
{
	int x = 0; int f = 1; char c = getchar();
	while(c<'0'||c>'9') f-=2*(c=='-'), c=getchar();
	while(c>='0'&&c<='9') x=x*10+c-'0', c=getchar();
	return x*f;
}
inline long long rd2()
{
	long long x = 0; int f = 1; char c = getchar();
	while(c<'0'||c>'9') f-=2*(c=='-'), c=getchar();
	while(c>='0'&&c<='9') x=x*10+c-'0', c=getchar();
	return x*f;
}
inline void wrt(long long x)
{
	if(x<0) x=-x, putchar('-');
	if(x>9) wrt(x/10);
	putchar('0'+x%10);
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) w[i]=rd1();
	for(int i = 1; i <= n; i++)
	{
		k[i]=rd1();
		for(int j = 1; j <= k[i]; j++)
		{
			int x, y;
			x=rd1(), y=rd1();
			a[i].push_back(x);
			t[x].push_back(make_pair(i, y));
		}
	}
	memset(b, 0x3f3f3f3f3f3f3f3f, sizeof(b));
	for(int i = 1 ; i <= m; i++)
	{
		for(int j = 0; j < t[i].size(); j++)
		{
			for(int k = j+1; k < t[i].size(); k++)
			{
				int val = t[i][j].second + t[i][k].second;
				if(b[t[i][j].first][t[i][k].first]>val)
					b[t[i][j].first][t[i][k].first] = b[t[i][k].first][t[i][j].first] = val;
			}
		}
	}
	memset(dist, 0x3f3f3f3f3f3f3f3f, sizeof(dist));
	for(int i = 1; i <= n; i++)
	{
		priority_queue<p, vector<p>, greater<p> > q;
		q.push({0, i});
		dist[i][i] = 0;
		st[i] = 1;
		while(q.size())
		{
			int tp = q.top().second;
			st[tp] = 0;
			q.pop();
			for(int j = 1; j <= n; j++)
			{
				if(dist[i][j] > dist[i][tp]+b[tp][j])
				{
					dist[i][j] = dist[i][tp]+b[tp][j];
					if(!st[j]) q.push({dist[i][j], j}), st[j] = 1;
				}
			}
		}
	}
	int cnt = 0;
	while(q--)
	{
		int x, y;
		cin >> x >> y;
		long long ans = 0x3f3f3f3f3f3f3f3f;
		cnt++;
		for(int j = 0; j < t[x].size(); j++)
		{
			for(int k = 0; k < t[y].size(); k++)
			{
				ans = min(ans, 0ll+w[x] + w[y] + t[x][j].second + t[y][k].second + dist[t[x][j].first][t[y][k].first]);
			}
		}
		wrt(ans);
		putchar('\n');
	}
	return 0;
}


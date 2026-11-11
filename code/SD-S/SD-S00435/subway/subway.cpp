#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 5;
inline int read()
{
	int x = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if (ch == '-')
		{
			f = -1;
		}
		ch = getchar();
	}
	while(ch >= '0' && ch <='9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
int c,n,m,d,q;
struct edge{
	int to,w;
};
struct ac{
	int a,t;
};
ac s[N][N];
int k[N];
vector <edge> g[N];
int w[N];
int ans;
int dis[N][N];
int main()
{
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i =1;i <= m;i++)
	{
		cin >> w[i];
	}
	for (int i = 1;i <= n;i++)
	{
		cin >> k[i];
		for (int j = 1;j<= k[i];j++)
		{
			cin >> s[i][j].a >> s[i][j].t;
		}
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j < k[i];j++)
		{
			g[s[i][j].a].push_back({s[i][j + 1].a,s[i][j].t});
		}
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			for (int k = 1;k <= n;k++)
			{
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j] + w[i] + w[j]);
			}
		}
	}
	while(q--)
	{
		int l,r;
		cin >> l >> r;
		cout << dis[l][r] << endl;
	}
	return 0;
}


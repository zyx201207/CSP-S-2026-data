#include <bits/stdc++.h>
#define int long long
using namespace std;
int w[500005],k[505],z = 0;
//vector <int> v[505];
map <int,int> p,e;
map <pair <int,int>,int> t;
void dfs(int x,int y)
{
	if (x == y)
	{
		return ;
	}
	z += t[{e[x],e[y]}];
	z += w[x];
	z += w[y];
	dfs(p[x],y);
}
signed main()
{
	freopen("subwy.in","r",stdin);
	freopen("subwy.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	int a = -1,b = -1;
	for (int i = 1;i <= n;i++)
	{
		cin >> k[i];
		for (int j = 1;j <= k[i];j++)
		{
			int x,y;
			cin >> x >> y;
			if (a == -1)
			{
				a = x;
			}
			else
			{
				b = x;
			}
			e[x] = i;
			t[{i,j}] = y;
		}
		p[a] = b;
		p[b] = a;
		a = b = -1;
	}
	while (q--)
	{
		z = 0;
		int x,y;
		cin >> x >> y;
		dfs(x,y);
		z += w[x] + w[y];
		cout << z << endl;
	}
	return 0;
}
//从一条线路的站台先走到站厅，再从站厅走到另一条线路的站台
/*
0
2
5
20
2
4
1
9
2
5
3
1
5
2
7
4
6
3
2
3
3
4
5
7
1
3
1
2
*/


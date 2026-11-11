#include <bits/stdc++.h>
using namespace std;
long long c , n , m , d , q;
bool vis[550];
queue<int> qu;
struct Node
{
	int v;
}line[10000][600];
int line1[10000]; //duo shao zhan
int line2[10000][600]; // fen bie wei na ji ge
int zhan1[600]; // duo shao xian;
int zhan2[600][10000]; // fen bie wei na ji ge;
int w[600];
long long a[600];
void dfs(int ed , int li , int t)
{
	if (qu.empty())
	{
		return;
	}
	int XZ = qu.front();
	int xz;
	qu.pop();
	for (int i = 1;i <= zhan1[XZ];i++)
	{
		xz = zhan2[XZ][i];
		if (xz != li)
		{
			t += line[xz][XZ].v;
		}
		for (int j = 1;j <= line1[xz];j++)
		{
			if (!vis[line2[xz][j]])
			{
				qu.push(line2[xz][j]);
				vis[line2[xz][j]] = 1;
				t += line[xz][line2[xz][j]].v;
				a[XZ] = min(t , a[XZ]);
				dfs(ed , xz , t);
				vis[line2[xz][j]] = 0;
			}
		}
	}
}
int main()
{
	freopen("subway.in" , "r" ,stdin);
	freopen("suway.out" , "w" ,stdout);
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	int k;
	for (int o = 1;o <= n;o++)
	{
		cin >> k;
		for (int i = 1;i <= k;i++)
		{
			int aj , at;
			cin >> aj >> at;
			line[o][aj].v = at;
			line1[o]++;
			line2[o][i] = aj;
			zhan1[aj]++;
			zhan2[aj][zhan1[aj]] = o;
		}
	}
	int start , end;
	for (int i = 1;i <= q;i++)
	{
		memset(vis , 0 , m + 1);
		cin >> start >> end;
		qu.push(start);
		vis[start] = 1;
		a[start] = w[start];
		dfs(end , 0 , w[start]);
		cout << a[end] << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

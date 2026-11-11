#include <bits/stdc++.h>
using namespace std;
int x = 0x3f;
/*void Record()
int Findway(int s0, int e0)
{
	if (c[s0][e0] == 0)
		return c[s0][e0];//如果已经在同一条线路上，直接返回0 
	
	queue<int>f1, f2, f3, f4;
	int flag = 1;
	vector<long long>f3r[500005], f4r[500005];
	memset(f3r, 0, sizeof(f3r));
	memset(f4r, 0, sizeof(f4r));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k[i]; j++)
		{
			if (s0 == a[i][j])//标记起点在某条线路的某个位置 
			f1.push_back(i);
			f2.push_back(j);
			if (e0 == a[i][j])//标记终点在某条线路的某个位置
			f3r[flag] = i;
			f4r[flag] = i;
			flag++;
		}
	}

	while (!f1.empty())
	{
		for (int i = 1; i <= f3r.length(); i++)
		{
			for (int j = 1; i <= m; j++)
				x = min(x, Findway(s0, j) + Findway(j, e0) + t[f1.head()][f2.head()] + t[f3r[i][f2.head()])
		}
	}
}*/
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c, n, m, d, q, start[100005], end[100005];
	cin >> c >> n >> m >> d >> q;
	long long w[500005], a[500000005][500000005], t[500000005][500000005], k[500005];
	/*vector<long long>c[1e9+7][1e9+7];
	memset(c, 0x3f, sizeof(c));*/
	for (int i = 1; i <= n; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++)
		{
			cin >> a[i][j] >> t[i][j];
		}
	}
	
	for (int i = 1; i <= q; i++)
	{
		cin >> start[i] >> end[i];
	}
	/*for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k[i]; j++)
		{
			for (int l = j + 1; l <= k[i]; l++)
			{
				c[a[j]][a[l]] = 0;
				c[a[l]][a[j]] = 0;
			}
		}
	}//初始化所有在同一条线路上的两点之间耗时为0 */
	return 0;
	
 } 

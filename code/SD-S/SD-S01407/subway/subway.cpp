#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define V 500//虚拟点的数量
#define P 500000//真实点的数量 
#define D 20//与真实点相连的最多虚拟点数量 
using namespace std;
int c,n,m,d,q;//c表示测试点编号,n表示有多少个虚拟点
//m表示有多少个实际点，d表示一个实际点最多连多少个虚拟点
//q表示有多少个疑问 
//dis应开long long 
int w[P + 10];//w表示要额外加上的数dis=min_dist+w[s]+w[t] 
int tmp_k;//k表示有该虚拟点和哪些真实点相连 
int tmp_a;//a表示i是多少 
int tmp_t;//t表示i链接p的边权 
int st,en,diss;//diss是临时取min 
int dist[V + 10][V + 10];//表示虚拟点之间的距离 
pair<int,int> bk[P + 10][D + 5];//表示每个真实点和那些虚拟点相连 
int sum[P + 10],tmp;//表示每个真实点和多少个虚拟点相连 
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q; 
	for (int i = 1;i <= m;i++) cin >> w[i];
	for (int i = 1;i <= n;i++)
	{
		cin >> tmp_k;
		for (int j = 1;j <= tmp_k;j++)
		{
			cin >> tmp_a >> tmp_t;
			bk[tmp_a][++sum[tmp_a]] = {i,tmp_t};
		}
	}
	for (int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) dist[i][j] = inf;
	for (int i = 1;i <= m;i++)
	{
		for (int l = 1;l <= sum[i];i++)
		{
			for (int r = 1;r <= sum[i];r++)
			{
				if (bk[i][l].first == bk[i][r].first) dist[bk[i][l].first][bk[i][r].first] = 0;
				else
				{
					dist[bk[i][l].first][bk[i][r].first] = min(dist[bk[i][l].first][bk[i][r].first],bk[i][l].second + bk[i][r].second);
					dist[bk[i][r].first][bk[i][l].first] = min(dist[bk[i][r].first][bk[i][l].first],bk[i][l].second + bk[i][r].second);
				}
			}
		}
	}
	for (int mid = 1;mid <= n;mid++)//Floyd 
	{
		for (int l = 1;l <= n;l++)
		{
			for (int r = 1;r <= n;r++)
			{
				dist[l][r] = min(dist[l][mid] + dist[mid][r],dist[l][r]);
			}
		}
	}
	while (q--)
	{
		cin >> st >> en;
		diss = inf,tmp = 0;
		if (st == en)
		{
			cout << 0 << '\n';
			continue;
		}
		for (int l = 1;l <= sum[st];l++)//枚举所有和st相连的虚拟点 
		{
			for (int r = 1;r <= sum[en];r++)//枚举所有和en相连的虚拟点 
			{
				if (dist[bk[st][l].first][bk[en][r].first] < diss)
				{
					diss = dist[bk[st][l].first][bk[en][r].first];
					tmp = bk[st][l].second + bk[en][r].second;
				}
			}
		}
		cout << w[st] + diss + tmp + w[en] << '\n';
	}
	return 0;
}

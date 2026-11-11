//杨云帆 陕西省西安中学 SN-S00325 
#include<bits/stdc++.h>
using namespace std;

long long sum_time = 0x3f3f3f3f;
long long ttime = 0;
int c;//编号 
int n;//地铁线路数 
int m;//地铁站数 
int d;//每个站几条线 
int q;//出行计划数 
int xr, yr;
vector<int> w;//每个地铁站的地铁口到站厅 时间 
vector<int> k;//第 i 个地铁线路经过的地铁站数 
vector< vector<int> > a;//第 i 条线路经过的第 j 个地铁站 
vector< vector<int> > t;//示从该地铁站的站厅走到第 i 条线路的站台需要的时间 
vector< vector<int> > p;//每一个地铁站有哪d条地铁 
vector<bool> vis;//每个地铁站走没走过 

void dfs(int x)//x为当前的站 
{
	if(x == yr)
	{
		sum_time = min(sum_time, ttime);
		return;
	}
	//当前在站厅 
	for (int i = 0; i < d; i ++)//这个站里的每一条地铁  第p[x][i]条 
	{
		ttime += t[p[x][i]][x];//到站台 
		if (ttime >= sum_time)
		{
			ttime -= t[p[x][i]][x];
			return;
		}
		for (int j = i; j <= k[p[x][i]]; j ++)
		{
			int nx = a[p[x][i]][j];//去到的下一站 
			if (vis[nx] == false)
			{
				vis[nx] = true;
				ttime += t[p[x][i]][nx];//到下一站站厅 
				dfs(nx);
				ttime -= t[p[x][i]][nx];//回到上一站站台 
				vis[nx] = false;
			}
		}
		ttime -= t[p[x][i]][x];//回到当前站站厅 
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	w.resize(m+1);
	k.resize(n+1);
	a.resize(n+1);
	t.resize(n+1);
	p.resize(m+1);
	
	for (int i = 1; i <= m; i ++)cin >> w[i];
	for (int i = 1; i <= n; i ++)//第i条地铁 
	{
		cin >> k[i];
		a[i].resize(k[i] + 1);
		t[i].resize(k[i] + 1);
		for (int j = 1; j <= k[i]; j ++)
		{
			cin >> a[i][j] >> t[i][j];
			p[a[i][j]].push_back(i); 
		}
	}
	
	while (q --)
	{
		sum_time = 0x3f3f3f3f;//每一条线路确定时时间的最小值（只考虑换乘） 
		ttime = 0;
		cin >> xr >> yr;
		dfs(xr);
		sum_time += (w[xr] + w[yr]); 
		cout << sum_time << '\n';
	}
	return 0;
}

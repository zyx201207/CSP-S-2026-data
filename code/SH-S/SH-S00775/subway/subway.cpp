#include <bits/stdc++.h>
using namespace std;
long long read()
{
	char c;
	c = getchar();
	while(!(c >= '0' && c <= '9'))
	{
		c = getchar();
	}
	long long ret = 0;
	ret = c - '0';
	c = getchar();
	while(c >= '0' && c <= '9')
	{
		ret = ret * 10 + c - '0';
		c = getchar();
	}
	return ret;
}
int c,n,m,d,q;
const int N = 5e5 + 7;
int ch[N];
int w[N];
struct node
{
	int id;
	int num;
};
vector <node> a[N];
set <int> st[N];
long long mp[1010][1010];
long long dis[1010][1010];
bool vis[1010];
bool flag[1010];
long long dij(int s,int e)
{
	dis[s][s] = 0;
	flag[s] = 0;
	for(int t = 1;t <= n;t++) if(t != s) 
	{
		dis[s][t] = 1e18;
		flag[t] = 0;
	}
	for(int t = 1;t <= n + 1;t++)
	{
		long long minn = 1e18;
		int pos = -1;
		for(int i = 1;i <= n;i++)
		{
			if(!flag[i])
			{
				//cout << minn << " " << dis[s][i] << endl;
				if(dis[s][i] < minn)
				{
					minn = dis[s][i];
					pos = i;
				}
			}
		}
		if(pos == -1) break;
		//cout << pos << endl;
		flag[pos] = 1;
		for(int i = 1;i <= n;i++)
		{
			if(dis[s][pos] + mp[pos][i] < dis[s][i])
			{
				//cout << dis[s][pos] << " " << mp[pos][i] << " " << dis[s][i] << endl;
				dis[s][i] = dis[s][pos] + mp[pos][i];
			}
		}
	} 
	return dis[s][e];
} 
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin >> c >> n >> m >> d >> q;
	for(int t = 1;t <= m;t++)
	{
		w[t] = read();
	}
	for(int t = 1;t <= n;t++)
	{
		int k;
		k = read();
		for(int i = 1;i <= k;i++)
		{
			int x,y;
			x = read();
			y = read();
			st[t].insert(x);
			a[x].push_back({t,y});
			ch[x]++;
		}
		for(int i = 1;i <= n;i++)
		{
			mp[t][i] = 1e18;
		 } 
	}
	for(int t = 1;t <= m;t++)
	{
		int sz = (int)a[t].size();
		for(int i = 0;i < sz;i++)
		{
			for(int j = i + 1;j < sz;j++)
			{
				int x = a[t][i].id;
				int y = a[t][j].id;
				int wx = a[t][i].num,wy = a[t][j].num;
				//cout << wx << " " << wy << " " << mp[x][y] << endl;
				if(wx + wy < mp[x][y])
				{
					mp[x][y] = wx + wy;
					mp[y][x] = wx + wy;
				}
			}
		} 
	}
	for(int t = 1;t <= n;t++)
	{
		mp[t][t] = 0;
	}
	while(q--)
	{
		int s,e;
		s = read();
		e = read(); 
		long long ret = 1e18;
		for(int t = 0;t < (int)a[s].size();t++)
		{
			for(int i = 0;i < (int)a[e].size();i++)
			{
				int ss = a[s][t].id;
				int ee = a[e][i].id;
				//cout << ss << " " << ee << endl; 
				long long path;
				if(!vis[ss])
				{
					path = dij(ss,ee);
					vis[ss] = 1;
				}
				else path = dis[ss][ee];
				//cout << path << endl;
				path += a[s][t].num + a[e][i].num;
				if(ret > path)
				{
					ret = path;
				}
			}
		}
		ret += w[s] + w[e];
		cout << ret << endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/

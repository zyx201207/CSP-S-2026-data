#include <bits/stdc++.h>
//#define int long long
using namespace std;

struct Stu
{
	int id;
	long long length;
	
	bool operator<(const Stu &y)const
	{
		return this->length < y.length;
	}
	
	bool operator>(const Stu &y)const
	{
		return this->length > y.length;
	}
};
vector <Stu> a[501];//edge subway
vector <long long> zht[500001][2];//subway station:id,length
priority_queue <Stu,vector <Stu>,greater <Stu> > qu;
long long dis[501][501];
long long w[500001];
bool flag[501];

inline int read()
{
	int op = 1;
	int rsum = 0;
	char ch = getchar();
	while(ch != '-'&&(ch < '0'||ch > '9'))
	{
		ch = getchar();
	}
	while(ch == '-')
	{
		ch = getchar(),op = -op;
	}
	while(ch >= '0'&&ch <= '9')
	{
		rsum = rsum*10+(ch-'0'),ch = getchar();
	}
	return rsum*op;
}

//#undef int
int main()
{
//#define int long long
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	c = read();
	n = read();
	m = read();
	d = read();
	q = read();
	for(int i = 1;i <= m;i++)
	{
		w[i] = read();
	}
	for(int i = 1;i <= n;i++)
	{
		int k;
		k = read();
		for(int j = 1;j <= k;j++)
		{
			long long id,t;
			id = read();
			t = read();
			for(int ij = 0;ij < zht[id][0].size();ij++)
			{
				int u = zht[id][0][ij];
				int v = zht[id][1][ij];
				a[i].push_back({u,t+v});
				a[u].push_back({i,t+v});
			}
			zht[id][0].push_back(i);
			zht[id][1].push_back(t);
		}
	}
	for(int i = 1;i <= n;i++)
	{
		while(!qu.empty())
		{
			qu.pop();
		}
		for(int j = 1;j <= n;j++)
		{
			dis[i][j] = 1e18;
			flag[j] = false;
		}
		dis[i][i] = 0;
		qu.push({i,0});
		while(!qu.empty())
		{
			int id = qu.top().id;
			qu.pop();
			if(flag[id] == true)
			{
				continue;
			}
			flag[id] = true;
			for(int k = 0;k < a[id].size();k++)
			{
				int u = a[id][k].id;
				int v = a[id][k].length;
				if(dis[i][u] > dis[i][id]+v)
				{
					dis[i][u] = dis[i][id]+v;
					qu.push({u,dis[i][u]});
				}
			}
		}
	}
	while(q--)
	{
		int l,r;
		l = read();
		r = read();
		long long minn = 1e18;
		for(int i = 0;i < zht[l][0].size();i++)
		{
			int idl = zht[l][0][i];
			for(int j = 0;j < zht[r][0].size();j++)
			{
				int idr = zht[r][0][j];
				minn = min(minn,dis[idl][idr]+zht[l][1][i]+zht[r][1][j]);
			}
		}
		printf("%lld\n",minn+w[l]+w[r]);
	}
	return 0;
}

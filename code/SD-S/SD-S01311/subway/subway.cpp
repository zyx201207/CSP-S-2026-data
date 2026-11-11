#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long f[505][505];

int W[505][500005];

struct edge
{
	int v;
	long long w;
};

vector<edge> e[500005];

int w[500005];

int readi()
{
	int x = 0,f = 1;
	char c = getchar();
	while(!isdigit(c))
	{
		if(c == '-') f = -1;
		c = getchar();
	}
	while(isdigit(c))
	{
		x = x * 10 + c - 48;
		c = getchar();
	}
	return x * f;
}

long long readll()
{
	long long x = 0,f = 1;
	char c = getchar();
	while(!isdigit(c))
	{
		if(c == '-') f = -1;
		c = getchar();
	}
	while(isdigit(c))
	{
		x = x * 10 + c - 48;
		c = getchar();
	}
	return x * f;
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	c = readi();
	n = readi();
	m = readi();
	d = readi();
	q = readi();
	for(int i = 1;i <= m;i++)
	{
		w[i] = readi();
	}
	for(int i = 1;i <= n;i++)
	{
		int K;
		K = readi();
		for(int j = 1;j <= K;j++)
		{
			int A,T;
			A = readi();
			T = readi();
			W[i][A] = T;
			e[A].push_back((edge){i,T});
		}
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			if(i != j) f[i][j] = 1e18;
		}
	}
	for(int i = 1;i <= m;i++)
	{
		int R = e[i].size();
		for(int j = 0;j < R;j++)
		{
			for(int k = j + 1;k < R;k++)
			{
				f[e[i][j].v][e[i][k].v] = min(f[e[i][j].v][e[i][k].v],e[i][j].w + e[i][k].w);
				f[e[i][k].v][e[i][j].v] = min(f[e[i][k].v][e[i][j].v],e[i][j].w + e[i][k].w);
			}
		}
	}
	for(int k = 1;k <= n;k++)
	{
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= n;j++)
			{
				f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
			}
		}
	}
	while(q--)
	{
		int x,y;
		x = readi();
		y = readi();
		long long res = 9e18;
		int R1 = e[x].size();
		int R2 = e[y].size();
		for(int i = 0;i < R1;i++)
		{
			for(int j = 0;j < R2;j++)
			{
				res = min(res,w[x] + w[y] + f[e[x][i].v][e[y][j].v] + W[e[x][i].v][x] + W[e[y][j].v][y]);
//				cout << w[x] << " " << w[y] << " " << e[x][i].v << " " << e[y][j].v << " " << f[e[x][i].v][e[y][j].v] << " " << W[e[x][i].v][x] << " " << W[e[y][j].v][y] << endl;
			}
		}
		cout << res << '\n';
	}
	return 0;
} 

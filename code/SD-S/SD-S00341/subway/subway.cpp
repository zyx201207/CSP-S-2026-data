#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 3;
const int M = 1e4 + 3;
const int X = 505;
int w[N];
int p[M][3];
int h = 0;
vector<pair<int,int>> g[X];
int sum = 1e18;
int x,y;
void sou(int xx,int y,int u)
{
	for(int i = 0;i < g[xx].size();i++)
	{
		
		if(g[xx][i].first == y)
		{
			u += g[xx][i].second;
			sum = min(sum,u);
			return;
		}
		u += g[xx][g[xx][i].first].second;
		sou(g[xx][i].first,y,u + g[g[xx][i].first][g[xx][i].first].second);
	}
	return;
}
int read()
{
	int x = 0,fs = 1;
	char c = getchar();
	while(c < '0' || c > '9')
	{
		if(c == '-')
		{
			fs = -1;
		}
		c = getchar();
	}
	while(c >= '0' && c <= '9')
	{
		x = x * 10 + (c - '0');
		c = getchar();
	}
	return x * fs;
}
signed main()
{
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
			p[j][1] = read();
			
			p[j][2] = read(); 
			g[i].push_back({p[j][1],p[j][2]});
		}
	}
	if(c <= 6)
	{
		int T;
		T = read();
		sum = 0;
		while(T--)
		{

			
			x = read();
			y = read();
			sou(x,y,0);
			sum += w[x];
			sum += w[y];
			sum += g[1][1].second;
			cout << sum << "\n";
		}
	}
	else if(c <= 25)
	{
		int T;
		T = read();
		while(T--)
		{
			sum = 0;
			int x,y;
			sum += w[x];
			sum += h;
			x = read();
			y = read();
			sum += h;
			sum += w[y];
			cout << sum << "\n";
		}
		
	}
	return 0;
}


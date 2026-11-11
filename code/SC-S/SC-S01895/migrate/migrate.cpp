#include <bits/stdc++.h>
#define int long long
using namespace std;
using namespace chrono;

namespace FASTIO
{
	void read(int &x)
	{
		x = 0;
		int f = 1;
		char c = getchar();
		while(!('0' <= c && c <= '9'))
		{
			if('-' == c)
				f = -1;
			c = getchar();
		}
		while('0' <= c && c <= '9')
		{
			x = (x << 3) + (x << 1) + (c ^ '0');
			c = getchar();
		}
		x *= f;
	}
	void write(int x)
	{
		if(x < 0)
		{
			putchar('-');
			x = -x;
		}
		if(x >= 10)
			write(x / 10);
		putchar(x % 10 + '0');
	}
}

int coust, Time;
const int N = 2e6 + 5;
int n;
int X[N];
int Dis;
void INPUT()
{
	FASTIO::read(n);
	FASTIO::read(Dis);
	for(int i = 1; i <= n; i ++)
		FASTIO::read(X[i]);
}

vector <int> G[N];
void PREPAR()
{
	for(int i = 1; i <= n; i ++)
	{
		G[i].clear();
		for(int j = i + 1; j <= n; j ++)
		{
			if(X[j] - X[i] > Dis)
				break;
			G[i].push_back(j);
		}
//		for(auto j : G[i])//
//			printf("%lld -> %lld\n", i, j);//
	}
}

const int INF = 0x3f3f3f3f3f3f3f3f;
int dis[N], way[N];
int inq[N];
queue <int> Q;
int Ans;
void GETANS()
{
	Ans = 0;
	for(int st = 1; st <= n; st ++)
	{
		for(int i = 1; i <= n; i ++)
		{
			dis[i] = INF;
			way[i] = 0;
			inq[i] = 0;
		}
		while(Q.size())
			Q.pop();
		
		dis[st] = 0;
		way[st] = 1;
		inq[st] = 1;
		Q.push(st);
		while(Q.size())
		{
			int u = Q.front();
			Q.pop();
			
			for(auto v : G[u])
			{
				if(!inq[v])
				{
					dis[v] = dis[u] + 1;
					way[v] = way[u];
					inq[v] = 1;
					Q.push(v);
				}
				else if(dis[v] == dis[u] + 1)
				{
					way[v] += way[u];
				}
			}
		}
		
		for(int i = 1; i <= n; i ++)
		{
//			printf("%lld --> %lld : %lld, %lld\n", st, i, dis[i], way[i]);//
			if(2 == way[i])
			{
				Ans ++;
			}
		}
	}
}

void OUTPUT()
{
	cout << Ans << "\n";
}

signed main()
{
//	freopen("migrate3.in", "r", stdin);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	FASTIO::read(coust);
	FASTIO::read(Time);
	while(Time --)
	{
		INPUT();
		PREPAR();
		GETANS();
		OUTPUT();
	}
	
	return 0;
}
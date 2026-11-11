#include <bits/stdc++.h>
using namespace std;
int rt,T,n,d;
bool c[5005][5005];
int line[5005][5005];
int value[5005][5055];
vector<int> l(n+1);
bool isin(vector<int> tk,int x)
{
	for (int i = 0;i < tk.size();i++)
	{
		if (tk[i] == x)
		{
			return true;
		}
	}
	return false;
}
void dfsa(int beg,int now,int to,vector<int> rl)
{
	if (now == to)
	{
		int m = rl.size();
		value[beg][to] = value[to][beg] = min(value[beg][to],m);
		rl.clear();
	} 
	else
	{
		rl.push_back(now);
		for (int i = 1;i <= n;i++)
		{
			if (c[now][i] == true && !isin(rl,i))
			{
				dfsa(beg,i,to,rl);
			}
		}
	}
	return;
}
void dfsb(int beg,int now,int to,vector<int> rl)
{
	if (now == to)
	{
		if ((rl.size()) == value[beg][to])
		{
			line[beg][to]++;
			line[to][beg]++;
		}
	} 
	else
	{
		rl.push_back(now);
		for (int i = 1;i <= n;i++)
		{
			if (i == now)
			{
				continue;
			}
			if (c[now][i] == true && !isin(rl,i))
			{
				dfsb(beg,i,to,rl);
			}
		}
	}
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdin);
	scanf("%d%d",&rt,&T);
	while (T--)
	{
		int ans = 0;
		scanf("%d%d",&n,&d);
		for (int i = 0;i <= n;i++)
		{
			for (int j = 0;j <= n;j++)
			{
				c[i][j] = c[j][i] = false;
				line[i][j] = line[j][i] = 0;
				value[i][j] = value[j][i] = 0x3f3f3f3f;
			}
		}
		for (int i = 1;i <= n;i++)
		{
			scanf("%d",&l[i]);
		}
		for (int i = 1;i <= n;i++)
		{
			for (int j = i+1;j <= n;j++)
			{
				if (abs(l[i]-l[j]) <= d)
				{
					c[i][j] = c[j][i] = true;
				}
			}
		}
		for (int i = 1;i <= n;i++)
		{
			for (int j = (i+1);j <= n;j++)
			{
				vector<int> use;
				use.clear();
				dfsa(i,i,j,use);
				use.clear();
				dfsb(i,i,j,use);
			}
		}
		for (int i = 1;i <= n;i++)
		{
			for (int j = (i+1);j <= n;j++)
			{
				if (line[i][j] == 2 || line[j][i] == 2)
				{
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

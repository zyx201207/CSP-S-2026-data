#include <bits/stdc++.h>
#define fir first
#define sec second
using namespace std;
int rt,n,m,d,q;
int tmh[1000];
vector< vector< pair<int,int> > > line(n+10,vector< pair<int,int> > ());
int ans = 0x3f3f3f3f;
int isin(vector< pair<int, int> > tk,int x)
{
	for (int i = 0;i < tk.size();i++)
	{
		if (x == tk[i].first)
		{
			return i;
		}
	}
	return -1;
}
bool check(vector<int> tk,int x)
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
void dfs(int now,int beg,int to,vector<int> use,int dj)
{
	use.push_back(now);
	if (now == to)
	{
		ans = min(ans,dj);
		use.clear();
		return;
	}
	else
	{
		for (int i = 1;i <= n;i++)
		{
			bool flag = false;
			int best = 0x3f3f3f3f;
			int bestuse = 0;
			for (int j = 1;j <= n;j++)
			{
				int c = isin(line[j],i);
				int d = isin(line[j],now);
				if (c != -1 && d != -1 && !check(use,i));
				{
					flag = true;
					if (best > (line[j][c].sec += line[j][d].sec))
					{
						best = (line[j][c].sec += line[j][d].sec);
						bestuse = i;
					}
				}
			}
			if (flag)
			{
				dfs(bestuse,beg,to,use,best+dj);
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&rt,&n,&m,&d,&q);
	for (int i = 1;i <= m;i++)
	{
		scanf("%d",&tmh[i]);
	}
	int a,b;
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&rt);
		for (int j = 0;j < rt;i++)
		{
			scanf("%d%d",&a,&b);
			line[i].push_back(make_pair(a,b));
		}
	}
	while (q--)
	{
		scanf("%d%d",&a,&b);
		ans = 0x3f3f3f3f;
		vector<int> use;
		dfs(a,a,b,use,0);
		ans += tmh[a];
		ans += tmh[b];
		printf("%d\n",ans);
	}
	return 0;
 } 
 /* 

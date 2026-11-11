#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,k,shu,shu1,shu2,ans = 0;
vector<long long> w,x,y,a[505],t[505],rs[500005];
int sz[500005];
struct Node
{
	long long pos,time,rail;
};
vector<Node> st[500005];
void dfs(int x1,int x2,int v)
{
	for (int i = 1;i <= sz[x1];i++)
	{
		if (i == x2) 
		{
			ans += (w[i] + st[x1][i].time);
			return;
		}
		if (v != st[x1][i].rail) ans += (st[x1][i].time + t[v][i]);
		dfs(i,x2,st[x1][i].rail);
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++) 
	{
		cin >> shu;
		w.push_back(shu);
	}
	for (int i = 1;i <= n;i++)
	{
		cin >> k;
		for (int j = 1;j <= k;j++) 
		{
			cin >> shu1 >> shu2;
			a[k].push_back(shu1),t[k].push_back(shu2);
		}
		for (int j = 1;j <= k;j++)
		{
			if (j - 1 > 0) 
			{
				Node x1;
				x1.pos = a[k][j-1],x1.time = t[k][j-1],x1.rail = i;
				st[a[k][j]].push_back(x1);
				sz[a[k][j]]++;
				rs[a[k][j]].push_back(i);
			}
			if (j + 1 < n+1) 
			{
				Node x2;
				x2.pos = a[k][j+1],x2.time = t[k][j+1],x2.rail = i;
				st[a[k][j]].push_back(x2);
				sz[a[k][j]]++;
				rs[a[k][j]].push_back(i);
			}
		}
	}
	long long shu3 = 0,shu4 = 0;
	for (int i = 1;i <= q;i++)
	{
		cin >> shu3;
		x.push_back(shu3);
	}
	for (int i = 1;i <= q;i++)
	{
		cin >> shu4;
		y.push_back(shu4);
	}
	for (int i = 1;i <= q;i++)
	{
		long long cnt = 0;
		for (int j = 1;j <= rs[i].size();j++)
		{
			ans = 0;
			dfs(x[i],y[i],rs[i][j]);
			cnt = max(cnt,ans);
		}
		cout << cnt << endl;
	}
	return 0;	
} 

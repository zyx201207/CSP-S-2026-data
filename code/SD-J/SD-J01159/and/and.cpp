#include <bits/stdc++.h>
#define int long long
using namespace std;
struct v
{
	int a,c;
}x[200005];
bool p(v x,v y)
{
	return x.c > y.c;
}
int n,m,z = 0;
void dfs(int u,int c,string s)
{
	if (c > m)
	{
		return ; 
	}
	if (u == n && c != m)
	{
		return ;
	}
	if (u == n && c == m)
	{
		int xx = -1;
		for (int i = 0;i < s.size();i++)
		{
			if (s[i] == '1')
			{
				if (xx == -1)
				{
					xx = x[i + 1].a;
				}
				else
				{
					xx = xx & x[i + 1].a;
				}
			}
		}
		z = max(z,xx);
		return ;
	}
	dfs(u + 1,c + 1,s + '1');
	dfs(u + 1,c,s + '0');
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int mx = -1;
	for (int i = 1;i <= n;i++)
	{
		cin >> x[i].a;
		mx = max(mx,x[i].a);
		int y = x[i].a;
		while (y)
		{
			if (y & 1)
			{
				x[i].c++;
			}
			y /= 2;
		}
	}
	if (m == 1)
	{
		cout << mx;
		return 0;
	}
	int xx = x[1].a;
	for (int i = 2;i <= n;i++)
	{
		xx = xx & x[i].a;
	}
	if (m == n)
	{
		cout << xx;
		return 0;
	}
	int xxx = 0;
	for (int i = 1;i <= n;i++)
	{
		for (int j = i + 1;j <= n;j++)
		{
			xxx = max(xxx,x[i].a & x[j].a);
		}
	}
	if (m == 2)
	{
		cout << xxx;
		return 0;
	}
	if (n <= 20)
	{
		dfs(0,0,"");
		cout << z;
		return 0;
	}
	sort(x + 1,x + n + 1,p);
	int z = x[1].a;
	for (int i = 2;i <= m;i++)
	{
		z = z & x[i].a;
	}
	cout << z;
	return 0;
}

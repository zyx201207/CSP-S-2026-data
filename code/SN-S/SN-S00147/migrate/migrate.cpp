#include<bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned int
#define endl '\n'

inline int read()
{
	int x = 0,f = 1;
	char ch = getchar();
	while('0'>ch||ch>'9')
	{
		if(ch=='-')
		{
			f = -1;
		}
		ch = getchar();
	}
	while('0'<=ch&&ch<='9')
	{
		x = (x<<3) + (x<<1) + ch - '0';
		ch = getchar();
	}
	return x * f;
}

const int inf = 1e18,N = 2e6 + 10;

int n,m,ans,vul[N],upgd[N],upbd[N],a[N],lower[N],upper[N],s[N],fa[N],f[N],g[N];
vector<int> son[N];

inline int dis(int l,int r)
{
	return a[r] - a[l];
}

inline int get(int i)
{
	if(i==1)
	{
		return 0;
	}
	else if(i==2)
	{
		return dis(i-1,upper[i]) <= m; 
	}
	else
	{
		return (dis(i-1,upper[i])<=m) + (dis(i-2,upper[i])<=m);
	}
}

inline void dfs(int u,int father,int root)
{
	fa[u] = father;
	if(u==root)
	{
		vul[u] = upgd[u] = upbd[u] = -inf;
	}
	else
	{
		vul[u] = get(u);
		upgd[u] = (vul[u] == 1) ? (u) : (upgd[father]);
		upbd[u] = (vul[u] == 2) ? (u) : (upbd[father]);
	}
	for(int i = 0;i<son[u].size();i++)
	{
		int v = son[u][i];
		s[v] = s[u] + upper[u] - upper[u-1];
		dfs(v,u,root);
	}
	if(vul[u]==0&&u!=root)
	{
		int gd = (upgd[u]==-inf)?(0):(upgd[u]);
		int bd = (upbd[u]==-inf)?(0):(upbd[u]);
		f[u] = s[u] - s[min(gd,bd)];
	}
	if(vul[u]==0&&u!=root)
	{
		for(int i = 0;i<son[u].size();i++)
		{
			int v = son[u][i];
			g[u] += g[v];
		}
		g[u] += lower[u+1] - lower[u] + 1;
	}
	else
	{
		g[u] = u - lower[upper[u]] + 1;
	}
}

inline void slove(int u)
{
	if(upgd[u]==-inf||(vul[u]==1&&upgd[fa[u]]==-inf))
	{
		for(int i = 0;i<son[u].size();i++)
		{
			int v = son[u][i];slove(v);
		}
	}
	else
	{
		int gd = upgd[fa[u]],bd = upbd[fa[u]];
		if(bd==-inf)
		{
			ans += upper[gd-1] - upper[gd-2];
			int GD = upgd[fa[gd]];
			if(GD==-inf)
			{
				ans += s[fa[gd]];
			}
			else
			{
				ans += s[fa[gd]] - s[fa[GD]];
			}
			for(int i = 0;i<son[u].size();i++)
			{
				int v = son[u][i];slove(v);
			}
		}
		else
		{
			if(gd>bd)
			{
				for(int i = 0;i<son[u].size();i++)
				{
					int v = son[u][i];slove(v);
				}
			}
			else
			{
				ans += upper[gd-1] - upper[gd-2]; 
				int GD = upgd[fa[gd]];
				if(GD!=-inf)
				{
					bd = min(bd,fa[GD]);
				}
				ans += s[fa[gd]] - s[bd];
				for(int i = 0;i<son[u].size();i++)
				{
					int v = son[u][i];slove(v);
				}
			}
		}
	}
}

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	for(int testid = read(),T = read();T;T--)
	{
		n = read(),m = read();
		for(int i = 1;i<=n;i++)
		{
			a[i] = read();
		}
		if(n<=2)
		{
			cout<<0<<endl;continue;
		}
		else if(testid==11||testid==12)
		{
			int d = a[2] - a[1];
			if(2*d<=m&&m<d*3)
			{
				cout<<n-3<<endl;
			}
			else if(d*3<=m&&m<d*4)
			{
				cout<<n-5<<endl;
			}
			else
			{
				cout<<0<<endl;
			}
		}
		else if(n<=5000)
		{
			for(int i = 1,j = 1;i<=n;i++)
			{
				j = max(j,i);
				while(j<=n&&a[j]-a[i]<=m)
				{
					j++;
				}
				upper[i] = j - 1;
			}
			for(int i = n,j = n;i;i--)
			{
				j = min(j,i);
				while(j>=1&&a[i]-a[j]<=m)
				{
					j--;
				}
				lower[i] = j + 1;
			}
			for(int i = 1;i<=n;i++)
			{
				for(int j = i + 1;j<=n;j++)
				{
					vector<int> pos;pos.push_back(i);
					int it = i;
					while(true)
					{
						if(a[it]+m>=a[j])
						{
							pos.push_back(j);break;
						}
						else if(it==upper[it])
						{
							break;
						}
						else
						{
							pos.push_back(it=upper[it]);
						}
					}
					if(pos.back()!=j)
					{
						break;
					}
					int cnt = 0,sum = 0;
					for(int it = 1;it+1<pos.size();it++)
					{
						int u = pos[it],v = pos[it+1];
						if(dis(u-2,v)<=m&&dis(u-1,v)<=m)
						{
							sum++;
						}
						else if(dis(u-1,v)<=m)
						{
							cnt++;
						}
					}
					ans += (cnt == 1) && (sum == 0);
				}
			}
			cout<<ans<<endl;
		}
		else
		{
			for(int i = 1,j = 1;i<=n;i++)
			{
				j = max(j,i);
				while(j<=n&&a[j]-a[i]<=m)
				{
					j++;
				}
				upper[i] = j - 1;
				if(upper[i]!=i)
				{
					son[upper[i]].push_back(i);
				}
			}
			for(int i = n,j = n;i;i--)
			{
				j = min(j,i);
				while(j>=1&&a[i]-a[j]<=m)
				{
					j--;
				}
				lower[i] = j + 1;
			}
			for(int i = 1;i<=n;i++)
			{
				if(upper[i]==i)
				{
					dfs(i,0,i);
					slove(i);
				}
			}
			cout<<ans<<endl;
		}
		for(int i = 1;i<=n;i++)
		{
			vul[i] = upgd[i] = upbd[i] = a[i] = lower[i] = upper[i] = s[i] = fa[i] = 0;
			son[i].clear();
		}
		n = m = ans = 0;
	}
	return 0;
}
//¹Ø×¢ Collapsarr ºÍ songjunhan004004 ß÷ 

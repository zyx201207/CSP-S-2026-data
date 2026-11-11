#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int c,n,m,d,q;//m地铁口 5e5，n地铁线 500 
int /*rd[230][maxn],ll[maxn][230],*/cnt[maxn],k1[505];
vector<int> rd[505];
vector<int> ll[maxn];
vector<int> t[505];
int st,to1;
long long w[maxn]/*,t[230][maxn]*/,minn;
bool vis[maxn];
void dfs(int now,long long s)
{
	if(now == to1)
	{
		if(s < minn) minn = s;
		return;
	}
	vis[now] = 1;
	for(int i = 0; i < cnt[now]; i++)
	{
		int x = ll[now][i];
		long long y = 0;
		for(int j = 0; j < k1[x]; j++)
		{
			if(rd[x][j] == now)
			{
				y = t[x][j];
				break;
			}
		}
		for(int j = 0; j < k1[x]; j++)
			if(vis[rd[x][j]] == 0) dfs(rd[x][j],s + y + t[x][j]);
	}
	vis[now] = 0;
	return;
}
void calc()
{
	for(int i = 0; i < cnt[st]; i++)
	{
		for(int j = 0; j < cnt[to1]; j++)
		{
			if(ll[st][i] == ll[to1][j])
			{
				int x = ll[st][i];
				long long y = 0,z = 0;
				for(int k = 0; k < k1[x]; k++)
				{
					if(rd[x][k] == st)
					{
						y = t[x][k];
						break;
					}
				}
				for(int k = 0; k < k1[x]; k++)
				{
					if(rd[x][k] == to1)
					{
						z = t[x][k];
						break;
					}
				}
				cout << w[st] + y + z + w[to1] << endl;
				return;
			}
		}
	}//if not?
	dfs(st,w[st] + w[to1]);
	cout << minn << endl;
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)	cin >> w[i];
	for(int i = 1; i <= n; i++)
	{
		cin >> k1[i];
		for(int j = 1; j <= k1[i]; j++)
		{
			int a,b;
			cin >> a >> b;
			rd[i].push_back(a);
			t[i].push_back(b);
			cnt[a]++;
			ll[a].push_back(i);
		}
	}
	while(q--)
	{
		minn = 1e18;
		memset(vis,0,sizeof(vis));
		cin >> st >> to1;
		calc();
	}
	return 0; 
}//60-80

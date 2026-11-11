#include<bits/stdc++.h>
using namespace std;
struct node{
	int id;
	long long x;
	bool operator < (const node & cnt)const{
		return x > cnt.x;
	}
};
const int N = 505,M = 1005;
long long w[M],b[N][M];
int a[N][M];
long long mp[M][M],dis[M][M];
vector<node>s[M];
priority_queue<node>pq;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int C,n,m,d,q;
	scanf("%d%d%d%d%d",&C,&n,&m,&d,&q);
	for (int i = 1;i <= m;i++)
	{
		scanf("%lld",&w[i]);
	}
	for (int i = 1;i <= n;i++)
	{
		int k;
		scanf("%d",&k);
		for (int j = 1;j <= k;j++)
		{
			scanf("%d%lld",&a[i][j],&b[i][j]);
		}
		for (int j = 1;j <= k;j++)
		{
			for (int j1 = j+1;j1 <= k;j1++)
			{
				if(!mp[a[i][j]][a[i][j1]]||b[i][j]+b[i][j1]<mp[a[i][j]][a[i][j1]])
				{
					mp[a[i][j]][a[i][j1]]=b[i][j]+b[i][j1];
				}
				if(!mp[a[i][j1]][a[i][j]]||b[i][j]+b[i][j1]<mp[a[i][j1]][a[i][j]])
				{
					mp[a[i][j1]][a[i][j]]=b[i][j]+b[i][j1];
				}
			}
		}
	}
	for (int i = 1;i <= m;i++)
	{
		for (int j = 1;j <= m;j++)
		{
			if(mp[i][j])
			{
				s[i].push_back({j,mp[i][j]});
			}
		}
	}
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		if(dis[l][r])
		{
			printf("%lld\n",dis[l][r]+w[l]+w[r]);
			continue;
		}
		pq.push({l,0});
		while (!pq.empty())
		{
			node t = pq.top();pq.pop();
			if(t.x > dis[l][t.id])continue;
			int u = t.id;
			int sz = s[u].size();
			for (int i = 0;i < sz;i++)
			{
				int v = s[u][i].id;
				if(v == l)continue;
				if(dis[l][v]==0||dis[l][u]+s[u][i].x < dis[l][v])
				{
					dis[l][v]=dis[l][u]+s[u][i].x;
					pq.push({v,dis[l][v]});
				}
			}
		}
		printf("%lld\n",dis[l][r]+w[l]+w[r]);
	}
	return 0;
}
#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 500086;
int c,n,m,d,Q;
vector<vector<pair<int,int> > >a;//a[i].[id,t]
bool l[505][N];
int w[N];
int vis[N];
int vid[505];
int lk[505][N];
ll ct[505];
queue<int> q;
queue<int> q2;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&Q);
	for(int i = 1; i <=m;i++)
	{
		scanf("%d",&w[i]);
	}
	int k;
	a.resize(m+1);
	for(int i = 1; i <=n;i++)
	{
		scanf("%d",&k);
		for(int j = 1;j <=k;j++)
		{
			int b,c;
			scanf("%d%d",&b,&c);
			a[b].push_back({i,c});//b站点c时间i几号线 
			l[i][b]=1;
			lk[i][b]=c;
		}
	}
	int x,y;
	while(Q--)
	{
		memset(ct,0x3f,sizeof ct);
		scanf("%d%d",&x,&y);
		ct[x]=0;
		int kid = a[x][1].first;
		q.push(x);
		vis[x]=1;
		
		//cout << '?';
		while(!q.empty())
		{
			int u = q.front();
			q.pop();
			for(int i = 1; i <=n;i++)
			{
				if(l[i][u])
				{
					q2.push(i);
				}
			}
			int fid = q2.front();
			for(auto v:a[u])
			{
				int sid=v.first;//i
				int cost = v.second;
				if(ct[sid]>ct[fid]+lk[fid][u]+cost)
				{
					ct[sid] = ct[fid]+lk[fid][u]+cost;
					if(!vis[k])
					{
						q.push(k);
						vis[k]=1;
					}
				}
			}
		}
		ll minn=1e10;
		for(auto i:a[y])
		{
			minn = min(minn,ct[i.first]);
		}
		printf("%d\n",w[x]+w[y]);//?
	}	
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/

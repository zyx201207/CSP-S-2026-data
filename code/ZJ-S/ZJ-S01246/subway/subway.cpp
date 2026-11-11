#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+100;
int n,m,d,q,c;
int w[N],a[505][505],t[N][505],dd[N];
bool vis[N];
vector<node> v[N];
priority_queue<int> q;
struct node{
	int u,w;
};
bool cmp(node a,node b)
{
	return a.w>b.w;
}
int abc(int x,int y)
{
	memset(dd,0x3f,sizeof(dd));
	memset(vis,0,sizeof(vis));
	q.push({x,0});
	dis[x]=0;
	while(!q.empty())
	{
		node s=q.top().u;
		int 
		if(!vis[s])
		{
			
		}
	}
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		for(int j=1;j<=x;j++)
		{
			cin>>a[i][j]>>t[a[i][j]][i];
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(t[i][j])
			{
				for(int k=j+1;k<=n;k++)
				{
					if(t[i][k])
					{
						v[i+(j-1)*m].push_back(i+(k-1)*m,t[i][k]+t[i][j]);
						v[i+(k-1)*m].push_back(j+(k-1)*m);
					}
				}
			}
		}
	}
	return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+100;
int n,m,d,q;
int w[N];
int a[505][505];
vector<int> v[N];
struct node{
	int u,k;
};
queue<node> q[N];
void bfs(int x)
{
	q.push({vis,0});
	f[x][x]=1;
	while(!q.empty())
	{
		int u=q.front()
		int dis=q.front().k;
		q.pop();
		for(int i=0;i<v[u].size();i++)
		{
			int v2=v[u][i];
			if(vis[x])
			{
				if(l[x][v2]==dis+1)
				{
					f[x][v2]++;
					f[v2][x]++;
				}
				continue;
			}
			dis[x][v2]=dis+1;
			vis[v]=true;
			f[x][v2]=f[v2][x]=f[x][u];
			q.push({v2,dis+1});
		}
	} 
}
signed main()
{
	int 
	return 0;
}

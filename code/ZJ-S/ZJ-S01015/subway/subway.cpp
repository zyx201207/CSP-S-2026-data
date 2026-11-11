#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500010];
vector<int> maps[501000];
vector<int> worth[501000];
bool vis[505000];
long long dfs(int to,int now)
{
	long long ans=1000000000000;
	if(to==now)
	{
		return 0;
	}
	else
	{
		for(int i=0;i<maps[now].size();i++)
		{
			int j=maps[now][i];
			if(vis[j]==true)
			{
				continue;
			}
			vis[j]=true;
			ans=min(ans,worth[now][i]+dfs(to,j));
			vis[j]=false;
		}
		return ans;
	}
}
void ans1()
{
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		for(int i=1;i<=m+n;i++)
		{
			vis[i]=false;
		}
		vis[x]=true;
		printf("%lld\n",dfs(y,x)+w[x]+w[y]);
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			int a,t;
			scanf("%d%d",&a,&t);
			maps[a].push_back(m+i);
			worth[a].push_back(t);
			maps[m+i].push_back(a);
			worth[m+i].push_back(t);
		}
	}
	ans1();
	return 0;
}

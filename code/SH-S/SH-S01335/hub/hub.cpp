#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int N=1001000;
int n,k;
struct Edge
{
	int u,v;
};
Edge edge[N];
vector <int> G[N];
int b_u=0,b_v=0;
int dp[N],ko[N];
int deg[N];
int req[3];
int tmp_deg[N];
inline int max(int a,int b)
{
	return (a > b) ? a : b;
}
inline int min(int a,int b)
{
	return (a < b) ? a : b;
}
int check(int cut_edge)
{
	for(int i=1;i<=n;i++)
	{
		dp[i]=0;ko[i]=0;
		tmp_deg[i]=deg[i];
	}
	b_u=edge[cut_edge].u;
	b_v=edge[cut_edge].v;
	queue <int> que;
	int del=0;
	for(int i=1;i<=n;i++)
	{
		if(tmp_deg[i]==1)
		{
			que.push(i);
			dp[i]=1;
		}
	}
	int ans=0;
	while(!que.empty() && del<n-k)
	{
		int u=que.front();
		que.pop();
		del++;
		ko[u]=1;
		ans=max(ans,dp[u]);
		for(int i=0;i<G[u].size();i++)
		{
			int v=G[u][i];
			if(ko[v]==0 && !((v==b_v && u==b_u) || (v==b_u && u==b_v)))
			{
				tmp_deg[v]--;
				dp[v]=max(dp[v],dp[u]+1);
				if(tmp_deg[v]==1)
				{
					que.push(v);
				}
			}
		}
	}
	return ans;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int tc,T;
	scanf("%d%d",&tc,&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
		{
			G[i].clear();
			dp[i]=0;ko[i]=0;
			deg[i]=0;
		}
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			edge[i].u=u;
			edge[i].v=v;
			G[u].push_back(v);
			G[v].push_back(u);
			deg[u]++;deg[v]++;
		}
		if(tc<=12)
		{
			int answer=n;
			for(int i=1;i<n;i++)
			{
				deg[edge[i].u]--;
				deg[edge[i].v]--;
				answer=min(answer,check(i));
				deg[edge[i].u]++;
				deg[edge[i].v]++;
			}
			printf("%d\n",answer);
		}
		else if(tc==13 || tc==14)
		{
			int m=n/2;
			if(k==n)
			{
				printf("0\n");
			}
			else if(k>=m)
			{
				printf("1\n");
			}
			else
			{
				int tmp=(m-k+3)/4;
				printf("%d\n",1+tmp);
			}
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}

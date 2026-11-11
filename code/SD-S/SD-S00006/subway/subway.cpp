#include<bits/stdc++.h>
using namespace std;
const int M=5e4+5;
const int N=505;
struct Node{
	int id,st,step;
	bool operator<(const Node &x) const
	{
		return step>x.step;
	}
};
priority_queue<Node> q;
int t[N][M],dis[N][M];
vector<int> edge[M];
vector<int> edge2[M];
int c,m,d,n,Q,w[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&Q);
	for(int i=1;i<=m;i++)
		scanf("%d",w+i);
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			int u;
			scanf("%d",&u);
			scanf("%d",&t[i][u]);
			edge[u].push_back(i);
			edge2[i].push_back(u);
		}
	}
	while(Q--)
	{
		memset(dis,0x3f,sizeof(dis)); 
		int s,e;
		scanf("%d%d",&s,&e);
		for(int i=1;i<=n;i++)
		{
			if(t[i][s])
			{
				dis[i][s]=t[i][s];
				q.push({i,s,t[i][s]});
			}
				
		}	
		while(!q.empty())
		{
			int id=q.top().id;
			int station=q.top().st;
			int st=q.top().step;
			if(station==e)
			{
				printf("%d\n",st+w[s]+w[e]);
				break;
			}
			q.pop();
			for(int h=0;h<edge[station].size();h++)
			{
				int i=edge[station][h];
				if(st+t[i][station]<dis[i][station])
				{
					dis[i][station]=st+t[i][station];
					q.push({i,station,st+t[i][station]});
				}
			}
			for(int h=0;h<edge2[id].size();h++)
			{
				int i=edge2[id][h];
				if(st+t[id][i]<dis[id][i])
				{
					dis[id][i]=st+t[id][i];
					q.push({id,i,st+t[id][i]});
				}
			}
		}
	}
	return 0;
}

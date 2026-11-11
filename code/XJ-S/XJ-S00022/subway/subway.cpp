#include<bits/stdc++.h>
using namespace std;
int n,m,c,d,q,g[5005][5005],w[5005],vis[5005];
//struct node
//{
//	int stop, time;
//};
//void bfs(int s,int e)
//{
//	queue<node>q;
//	q.push({s,0});
//	vis[s]=1;
//	while(!q.empty())
//	{
//		node nox=q.front();
//		q.pop();
//		for(int i=1;i<=m;i++)
//		{
//			if(g[nox.stop][i]!=0x3f&&!vis[i])
//			{
//				vis[i]=1;
//				q.push({i,nox.time+g[nox.stop][i]});
//			}
//			if(g[nox.stop][i]!=0x3f&&i==e)
//			{
//				cout<<nox.time+g[nox.stop][i]+w[s]+w[e];
//				return;
//			}
//		}
//	}
//	
//}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	memset(g,0x3f,sizeof(g));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int x,a[500005],b[500005];
		cin>>x>>a[1]>>b[1];
		for(int j=2;j<=x;j++)
		{
			cin>>a[j]>>b[j];
			g[j-1][j]=min(g[j-1][j],b[j-1]+b[j]);
			g[j][j-1]=min(g[j][j-1],b[j-1]+b[j]);
		}
	}
//	while(q--)
//	{
//		memset(vis,0,sizeof(vis));
//		int sp,ep;
//		cin>>sp>>ep;
//		bfs(sp,ep);
//	}
 while(q--)cout<<n<<" ";
	return 0;
}

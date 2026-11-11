#include<iostream>
#include<queue>
using namespace std;

int c,n,m,d,q;
int w[160005],k[505];
int a[405][405],t[405][405];
int graph[405][405];
long long dis[405][405];
bool vis[1005];
queue<pair<int,int>>qu;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	
	for(int i=1;i<=400;i++)
	{
		for(int j=1;j<=400;j++)
		{
			graph[i][j]=2e9;
			dis[i][j]=2e9;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			graph[a[i][j]][a[i][j-1]]=min(t[i][j]+t[i][j-1],graph[a[i][j]][a[i][j-1]]);
			graph[a[i][j-1]][a[i][j]]=graph[a[i][j]][a[i][j-1]];
		}
	}

	if(c<=11)
	{
		qu.push({a[1][1],a[1][2]});
		int cnt=0;
		while(!qu.empty())
		{
			int la=qu.front().first,now=qu.front().second;
			if(graph[la][now]>=dis[la][now]||vis[now])continue;
			for(int i=1;i<=m;i++)
			{
				dis[i][now]=(dis[i][la]+graph[la][now],dis[i][now]);
			}
			vis[now]=1;
			qu.pop();
			if(qu.empty())break;
			for(int i=1;i<=m;i++)
			{
				if(graph[i][now]<=1e9&&!vis[i])
				{
					qu.push({now,i});	
					//cout<<now<<' '<<i<<endl;
				}
			}
		
		}
			for(int i=1;i<=q;i++)
		{
			int x,y;
			cin>>x>>y;
			cout<<graph[x][y]+w[x]+w[y]<<endl;
		}
	}



	
	return 0;
 } 
 


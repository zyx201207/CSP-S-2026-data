#include<bits/stdc++.h>
using namespace std;
long long w[500001],k[501];
vector<long long>a[501],t[501],road[500001],visit,far;
int bfs(int x,int y)
{
	int ans+=w[x]+w[y];
	far[x]=0;
	visit[x]=1;
	queue<long long>qu;
	qu.push(x);
	while(qu.size())
	{
		int nx=qu.front();
		qu.pop();
		for(int i=0;i<road[nx].size();i++)
		{
			if(road[nx][i]==r)return ans+(far[nx]+1)*t[1][1]*2;
			if(!visit[road[nx][i]])
			{
				far[road[nx][i]]=far[nx]+1;
				visit[road[nx][i]]=1;
				qu.push(road[nx][i]);
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","W",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			for(int k=1;k<j;k++)
			{
				road[a[i][j]].push(a[i][k]);
				road[a[i][k]].push(a[i][j]);
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<bfs(x,y)<<"\n";
	}
	return 0;
}

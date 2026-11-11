#include<bits/stdc++.h>
using namespace std;
long long edge[501][100001];
long long vis[501][100001];
const int N=5e5+10;
long long w[N];
int c,n,m,d,q;
long long dis(int a,int b)
{
	int k,p;
	long long minn=1e15;
	for(int i=1;i<=n;i++)
	{
		if(edge[i][a]!=0)
		{
			k=i;//k是起点所在路 
			vis[i][a]=1;
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(edge[i][b]!=0)
		{
			p=i;//p是终点所在路 
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i==k&&edge[i][j]!=0&&vis[i][j]==0)
			{
				vis[i][j]=1;
				return minn=min(dis(j,b)+edge[i][j],minn);
			}
			if(j==a&&edge[i][j]!=0&&vis[i][j]==0)
			{
				vis[i][j]=1;
				return minn=min(dis(j,b)+edge[i][a],minn);
			}
		}
		
	}
}



int main()
{
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)//第i条路 
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)//该路上有k个地铁站 
		{
			int x,y;
			cin>>x>>y;
			edge[i][x]=y;
		}
	}
	for(int i=1;i<=q;i++)
	{
		
		int qd,zd;
		cin>>qd>>zd;
		cout<<dis(qd,zd)+w[qd]+w[zd]<<endl;	
	}
	return 0;
}

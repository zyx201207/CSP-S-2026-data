#include<bits/stdc++.h>
using namespace std;
int cnt=0;
int w[1005];
int a[1005][1005],t[1005][1005],flag[1005],k[1005]; 
int mintime;
void dfs(int x,int y,int timee)
{
	if(x==y)
	{
		mintime=min(mintime,timee+w[y]);
		return ;
	}
	else if(flag[x]==1)
	{
		return ;
	}
	flag[x]=1;
	for(int i=x+1;i<=k[x];i++)
	{
		if(a[x][i]==1)
		{
			dfs(i,y,timee+t[x][x]+t[x][i]);
		}
	}
	flag[x]=0;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,p;
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int v;
			cin>>v;
			a[i][v]=1;
			a[v][i]=1;
			int tim;
			cin>>tim;
			t[i][v]=tim;
			t[v][i]=tim;
		}
	}
	for(int i=1;i<=p;i++)
	{
		mintime=1000000;
		memset(flag,'0',sizeof(flag));
		int x,y;
		cin>>x>>y;
		dfs(x,y,w[x]);
		cout<<mintime<<endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[500005][505],w[500005],n,b[1005][1005];
vector<int> xl[505];
vector<int> bb[1005];
bool p[500005];
int tot=INT_MAX;
void dfs(int x,int y,int cnt)
{
	if(x==y)
	{
		tot=min(tot,cnt);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[x][i]!=0)
		{
			for(int j=0;j<xl[i].size();j++)
			{
				if(xl[i][j]==x)
				{
					for(int k=j+1;k<xl[i].size();k++)
					{
						cnt+=a[x][i]+a[xl[i][k]][i];
						dfs(xl[i][k],y,cnt);
						cnt-=a[x][i]+a[xl[i][k]][i];
					}
				}
			}
		}
	}
}
void dfs1(int x,int y,int cnt)
{
	if(x==y)
	{
		tot=min(tot,cnt);
		return;
	}
	if(bb[x].size())
	{
		for(int i=0;i<bb[x].size();i++)
		{
			if(p[bb[x][i]]==0)
			{
				p[bb[x][i]]=1;
				dfs1(bb[x][i],y,cnt+b[x][bb[x][i]]);
				p[bb[x][i]]=0;
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	bool ff=0;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		if(x>2)ff=1;
		if(x==2)
		{
			int y1,z1,y2,z2;
			cin>>y1>>z1>>y2>>z2;
			bb[y1].push_back(y2);
			bb[y2].push_back(y1);
			if(b[y1][y2]!=0)b[y1][y2]=min(b[y1][y2],z1+z2);
			else b[y1][y2]=z1+z2;
			if(b[y2][y1]!=0)b[y2][y1]=min(b[y2][y1],z1+z2);
			else b[y2][y1]=z1+z2;
		}
		else for(int j=1;j<=x;j++)
		{
			int y,z;
			cin>>y>>z;
			xl[i].push_back(y);
			a[y][i]=z;
		}
	}
	if(ff==0)
	{
		while(q--)
		{
			memset(p,0,sizeof(p));
			tot=INT_MAX;
			int x,y;
			cin>>x>>y;
			if(b[x][y]!=0)
			{
				cout<<w[x]+w[y]+b[x][y]<<'\n';
			}
			else
			{
				dfs1(x,y,0);
				cout<<w[x]+w[y]+tot<<'\n';
			}
		}
	}
	else while(q--)
	{
		tot=INT_MAX;
		int x,y;
		cin>>x>>y;
		dfs(x,y,0);
		cout<<w[x]+w[y]+tot<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/

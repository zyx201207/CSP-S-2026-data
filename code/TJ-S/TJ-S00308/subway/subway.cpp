#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int MAXN=2500;
int w[MAXN],mp[MAXN][MAXN];
struct Node
{
	int l;
	int station;
	int spend;
}node[MAXN];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	memset(mp,0x3f3f3f3f,sizeof(mp));
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	if(c>=7&&c<=11)
	{
		for(int i=1;i<=n;i++)
		{
			int x;
			cin>>x;
			int x1,x2,y1,y2;
			cin>>x1>>y1>>x2>>y2;
			mp[x1][x2]=mp[x2][x1]=y1+y2;
		}
		for(int i=1;i<=q;i++)
		{
			int x,y;
			cin>>x>>y;
			for(int j=1;j<=m;j++)
			{
				for(int k=j+1;k<=m;k++)
				{
					for(int o=k+1;o<=m;o++)
					{
						mp[j][k]=min(mp[j][k],mp[j][o]+mp[k][o]);
					}
				}
			}
			cout<<mp[x][y]+w[x]+w[y]<<endl;
		} 
	}
	else
	{
		int tot=1;
		for(int i=1;i<=n;i++)
		{
			int x;
			cin>>x;
			for(int j=1;j<=x;j++)
			{
				int a,t;
				cin>>a>>t;
				node[tot].l=i;
				node[tot].station=a;
				node[tot].spend=t;
				tot++;
			}
		}
		for(int i=1;i<=tot;i++)
		{
			for(int j=1;j<=tot;j++)
			{
				if(node[i].l==node[j].l)
				{
					mp[node[i].station][node[j].station]=mp[node[j].station][node[i].station]=node[i].spend+node[j].spend;
				}
			}
		}
		/*
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cout<<mp[i][j]<<" ";
			}
			cout<<endl;
		}
		*/
		for(int i=1;i<=q;i++)
		{
			int x,y;
			cin>>x>>y;
				for(int j=1;j<=m;j++)
				{
					for(int k=1;k<=m;k++)
					{
						for(int o=1;o<=m;o++)
						{
							mp[j][k]=min(mp[j][k],mp[j][o]+mp[k][o]);
						}
					}
				}
			cout<<mp[x][y]+w[x]+w[y]<<endl;
		}
	}
	return 0;
} 

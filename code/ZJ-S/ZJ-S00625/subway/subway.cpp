#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y,tim=0;
int cnt=1;
int map[500005][505];
int w[500005];//每个站点口到厅的距离 
struct Node{
	int id;//经过站点数 
	int a[500005],t[500005];// 经过哪个站点，这个站点厅到台的距离 
}k[505];//每条地铁线 

void g(int x,int y)
{
	bool vis=0;
	for (int i=1;i<=m;i++)
	{
		tim+=k[i].t[x]+k[i].t[y];
	}
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++) cin>>w[i];
	for (int i=1;i<=n;i++)
	{
		cin>>k[i].id;
		for (int j=1;j<=k[i].id;j++)
		{
			cin>>k[i].a[j]>>k[i].t[k[i].a[j]];
			map[k[i].a[j]][cnt++]=i;
		}
	}
	while (q--)
	{
		tim=tim+w[x]+w[y];
		cin>>x>>y;
		bool vis=0;
		for (int i=1;i<=map[x].size();i++)
		{
			for (int j=1;j<=map[y].size();j++)
			{
				if (map[x][i]==map[y][j])
				{
					cout<<tim+k[map[y][j]].t[x]+k[map[y][j]].t[y]<<endl;
					vis=1;
					break;
				}
			}
		}
		if (vis==0)
		{
			g(x,y);
		    cout<<tim<<endl;
		}
	}
	
	return 0;
}

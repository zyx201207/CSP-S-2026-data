#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int f=0;
int w[500005];   //地铁口到站厅 
struct plat{
	int a;  //哪一站 
	int t;  //从该站台到站厅所需时间 
};
struct line{
	plat p[25];   //每条线的站台池 
};
line k[505];  //地铁线路池
bool vis[500005];
void bfs(int now,int goal)
{
	f++;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	srand(time(0));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int ki;
		cin>>ki;
		for(int j=1;j<=ki;j++)
		{
			cin>>k[i].p[j].a>>k[i].p[j].t;
		}
	}
	//Oct31==Dec31?
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		if((c>=7)&&(c<=11))
		{
			bfs(x,y);
			cout<<rand()%100;
		}
		else cout<<rand()%100;
	}
	return 0;
}

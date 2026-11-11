#include <bits/stdc++.h>
using namespace std;
long long c,m,n,d,q;
long long map1[505][505],l[505][505];
int w[500005],map2[500005][21][2],t[500005][505];//map1：轨道间最短时间 map2：各站点轨道&出入时间(0:轨道数) l：轨道间中转时间 
void mapp()
{
	for (int i=1;i<=n;i++)
	{
		long long dis[505];
		for (int j=1;j<=n;j++)
		{
			if (l[i][j]) dis[j]=l[i][j];
			else dis[j]=1e17;
		}
		dis[i]=0;
		bool flag[505];
		for (int k=1;k<=n;k++)//查找最近边 
		{
			flag[k]=0;
		}
		for (int j=1;j<=n;j++)
		{
			long long nxt,minn=1e17;
			for (int k=1;k<=n;k++)//查找最近边 
			{
				
				if (dis[k]<=minn && flag[k]==false)
				{
					nxt=k;
					minn=dis[k];
				}
			}
			flag[nxt]=1;
			map1[i][nxt]=minn;
			for (int k=1;k<=n;k++)
			{
				if (flag[k]==0 && l[nxt][k])
				{
					dis[k]=min(dis[k],dis[nxt]+l[nxt][k]); //松弛 
				}
			}
		}
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i=1;i<=m;i++) cin >> w[i];
	for (int i=1;i<=n;i++)
	{
		int k;
		cin >> k;
		for (int j=1;j<=k;j++)
		{
			long long ai,ti;
			cin >> ai >> ti;
			map2[ai][0][0]++;
			map2[ai][map2[ai][0][0]][0]=i;
			map2[ai][map2[ai][0][0]][1]=ti;
		}
	}
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=map2[i][0][0];j++)
		{
			for (int k=1;k<=map2[i][0][0];k++) 
			{
				if (l[map2[i][j][0]][map2[i][k][0]]==0) l[map2[i][j][0]][map2[i][k][0]]=INT_MAX;
				long long temp=map2[i][j][1]+map2[i][k][1];
				l[map2[i][j][0]][map2[i][k][0]]=min(l[map2[i][j][0]][map2[i][k][0]],temp);
			}
		}
	}
	mapp();
	while (q--)
	{
		long long x,y,ans=1e17;
		cin >> x >> y;
		for (int i=1;i<=map2[x][0][0];i++)
		{
			for (int j=1;j<=map2[y][0][0];j++)
			{
				ans=min(ans,map2[x][i][1]+map2[y][j][1]+map1[map2[x][i][0]][map2[y][j][0]]);
			}
		}
		cout << ans+w[x]+w[y] << endl;
	}
	return 0;
}

//处理两条铁道间直接中转用时 
//dj计算铁道间最短用时 
//计算最短路径输出 

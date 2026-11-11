#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int N1=2e6+10,N2=500,inf=1e18+10;
int n,c,T,d;
int x[N1],f[N2][N2],dis[N2][N2];
void init()
{
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			f[i][j]=0;
			dis[i][j]=inf;
		}
	}
	for(int i=1;i<=n;i++)
	{
		f[i][i]=1;
		dis[i][i]=0;
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		init();
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		int ans=0;
//		for(int i=1;i<n;i++)
//		{
//			if(x[i+1]-x[i]<=d)
//			{
//				dis[i][i+1]=1;
//				f[i][i+1]=1;
//			}
//			else
//			{
//				dis[i][i+1]=inf;
//				f[i][i+1]=0;
//			}
//		}
		for(int len=2;len<=n;len++)
		{
			for(int u=1,v=u+len-1;v<=n;v++,u++)
			{
				if(x[v]-x[u]<=d)
				{
					//cout<<u<<' '<<v<<endl;
					dis[u][v]=dis[v][u]=1;
					f[u][v]=f[v][u]=1;
					continue;
				}
				for(int k=u+1;k<=v-1;k++)
				{		
					if(x[k]-x[u]>d)	continue;			
//					if(u==1&&v==4)
//					{
//						cout<<k<<endl;
//						cout<<' '<<dis[u][k]<<' '<<f[u][k]<<endl;
//						cout<<' '<<dis[k][v]<<' '<<f[k][v]<<endl;
//					}
					if(dis[u][k]==inf||dis[k][v]==inf)	continue;
					if(dis[u][v]==dis[u][k]+dis[k][v])
					{
						f[u][v]+=f[u][k]*f[k][v];
					}
					else if(dis[u][v]>dis[u][k]+dis[k][v])
					{
						f[u][v]=f[u][k]*f[k][v];
						dis[u][v]=dis[u][k]+dis[k][v];
					}

				}
				if(f[u][v]==2&&dis[u][v]!=inf)	ans++;
				//cout<<u<<' '<<v<<' '<<dis[u][v]<<' '<<f[u][v]<<endl;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 1
10 3
0 3 6 7 8 9 10 13 16 19
*/

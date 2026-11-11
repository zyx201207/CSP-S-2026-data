#include<bits/stdc++.h>
using namespace std;
const int M=5e5+7;
const int N=505;
const int Q=1e5+7;
int w[M];
int a[N][N],t[N][M],x[Q],y[Q],k[N],dis[405][405];
vector<int >d[M];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,dm,q;
	cin>>c>>n>>m>>dm>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){//i=第几条线路 
		cin>>k[i];//第i条经过的地铁站数 
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j];
			cin>>t[i][a[i][j]];
			//a[i][j]为第i条线路经过第j个地铁站编号是 
			//t[i][j]为第i条线到第j个地铁站站厅的时间 
			d[a[i][j]].push_back(i);//每个地铁站分别有哪些线路经过 
		}
	}
	for(int i=1;i<=q;i++)cin>>x[i]>>y[i];
	if(1<=c&&c<=8){
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				dis[i][j]=1000000007;
		for(int i=1;i<=m;i++)
		{
			for(int j=0;j<d[i].size();j++)
			{
				for(int z=1;z<=k[d[i][j]];z++)
				{
					dis[i][a[d[i][j]][z]]=t[d[i][j]][i]+t[d[i][j]][a[d[i][j]][z]];
				}
			}
		}

		for(int i=1;i<=m;i++)dis[i][i]=0;
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				for(int z=1;z<=m;z++)
				{
					dis[i][j]=min(dis[i][j],dis[i][z]+dis[z][j]);
				}
			}
		}
		int ans=0;
//		for(int i=1;i<=m;i++)
//		{
//			for(int j=1;j<=m;j++)
//			{
//				cout<<dis[i][j]<<" ";
//			}
//			cout<<endl;
//		}
		for(int i=1;i<=q;i++)
		{
			ans=w[x[i]]+w[y[i]]+dis[x[i]][y[i]];
//			cout<<w[x[i]]<<" "<<w[y[i]]<<" "<<dis[x[i]][y[i]]<<" ";
			cout<<ans<<"\n";
		}
	}
	return 0;
}

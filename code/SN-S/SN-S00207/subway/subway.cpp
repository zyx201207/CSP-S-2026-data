#include<bits/stdc++.h>
//#define int long long
using namespace std;
int c,n,m,d,q,du[500010];
long long w[500010],dis[510][510];
vector<int> vec1[500010];
vector<long long> vec2[500010];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k,a,t;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a>>t;
			du[a]++;
			vec1[a].push_back(i);
			vec2[a].push_back(t);
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++) 
	{
		for(int j=0;j<du[i];j++)
		{
			for(int k=j+1;k<du[i];k++)
			{
				int tp1=vec1[i][j],tp2=vec1[i][k];
				dis[tp1][tp2]=min(dis[tp1][tp2],vec2[i][j]+vec2[i][k]); 
				dis[tp2][tp1]=dis[tp1][tp2]; 
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(i!=k && j!=k)
				{
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
					dis[j][i]=dis[i][j];
				}
			}
		}
	}
	int x,y;
	while(q--)
	{
		cin>>x>>y;
		long long ans=0x3f3f3f3f3f3f3f3f;
		for(int i=0;i<du[x];i++)
		{
			for(int j=0;j<du[y];j++)
			{
				ans=min(ans,dis[vec1[x][i]][vec1[y][j]]+vec2[x][i]+vec2[y][j]);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}

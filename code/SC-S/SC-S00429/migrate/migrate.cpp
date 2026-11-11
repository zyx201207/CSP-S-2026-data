#include<bits/stdc++.h>
using namespace std;
#define int long long
#define da dis[x][y][0]
#define db dis[x][y][1]
#define dc dis[x][y][2]
const int N=3e2+5;
int num,t,n,d,w[N],dis[N][N][3],sum;
void init(int x,int y,int z)
{
	if(!da)da=z;
	else if(da>z)dc=db,db=da,da=z;
	else if(da<=z&&!db)db=z;
	else if(da<=z&&db>z)dc=db,db=z;
	else if(da<=z&&db<=z&&(!dc||dc>z))dc=z;
}
bool ok(int j,int k,int o,int l,int r)
{
	if(!dis[j][o][l])return 0;
	if(!dis[o][k][r])return 0;
	if(dis[j][o][l]!=dis[j][o][0])return 0;
	return (dis[o][k][r]==dis[o][k][0]);
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>num>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>d;
		memset(dis,0,sizeof(dis));
		sum=0;
		for(int j=1;j<=n;j++)cin>>w[j];
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				dis[j][k][0]=(abs(w[j]-w[k])<=d);
		for(int o=1;o<=n;o++)
			for(int j=1;j<o;j++)
				for(int k=o+1;k<=n;k++)
					for(int l=0;l<3;l++)
						for(int r=0;r<3;r++)
							if(ok(j,k,o,l,r))init(j,k,dis[j][o][l]+dis[o][k][r]);
		for(int j=1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				sum+=(dis[j][k][0]&&dis[j][k][0]==dis[j][k][1]&&dis[j][k][2]!=dis[j][k][1]);
		cout<<sum<<'\n';
	}
	return 0;
}
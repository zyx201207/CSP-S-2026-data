#include<bits/stdc++.h>
#define ll long long
#define pir pair<int,int>
using namespace std;
const int N=505,M=500005,K=500005;
int c,n,m,d,q;
int w[M];
int k[N];
int a[N][K],t[N][K];
ll dis[N][N];
vector<pir>line[M];//every station has which line
/*
	输入的第一行包含五个非负整数 c, n, m, d, q 
	测试点编号 				c 0≤c≤25
	地铁线路数 				n 1≤n≤500
	地铁站数 					m 1≤m≤500005
	每个地铁站最多被几条线路经过	d 1≤d≤20
	以及出行计划数				q 1≤q≤100005
*/
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			line[a[i][j]].push_back({i,t[i][j]});
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int pp=1;pp<=m;pp++)//every station
	{
		vector<pir>tmp=line[pp];//this station connect which line and walk time
		int cnt=tmp.size();
		for(int i=0;i<cnt;i++)
		{
			for(int j=0;j<i;j++)
			{
				dis[tmp[i].first][tmp[j].first]=min(dis[tmp[i].first][tmp[j].first],(ll)tmp[i].second+tmp[j].second);
				dis[tmp[j].first][tmp[i].first]=dis[tmp[i].first][tmp[j].first];
			}
		}
	}
	for(int p=1;p<=n;p++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][p]+dis[p][j]);
			}
		}
	}
	while(q--)
	{
		ll x,y,ans=1e17;
		cin>>x>>y;
		for(auto aa:line[x])
		{
			for(auto bb:line[y])
			{
				ll in_station_time=dis[aa.first][bb.first];
				ll enter_station_time=aa.second+bb.second;
				ans=min(ans,in_station_time+enter_station_time);
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<endl;
	}
	return 0;
}

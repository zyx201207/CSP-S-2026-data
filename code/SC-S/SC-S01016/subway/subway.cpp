/*
空间 1024 应该炸不了
时间上应该跑不满
大样例 0.3
把贡献拆开
口->厅->线->转->线->厅->口
显然拆成  厅->线->转->线->厅
再拆 线->转->线
然后 floyd 最短路就行了
每个点处理一下中转即可 
exp:100pts
fin:15:38
*/
#include<bits/stdc++.h>
using namespace std;
const int M=500050;
const int N=550;
vector<pair<int,int>>e[M];//存 v,w 
long long dis[N][N];
int sid,n,m,d,q;
int W[M];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof dis);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>sid>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>W[i];
	for(int i=1;i<=n;i++)
	{
		dis[i][i]=0;
		int k;
		cin>>k;
		while(k--)
		{
			int v,w;
			cin>>v>>w;
			e[v].push_back({i,w});
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<(int)e[i].size();j++)
		{
			for(int k=j+1;k<(int)e[i].size();k++)
			{
				if(e[i][j].first==e[i][k].first) continue;
				dis[e[i][k].first][e[i][j].first]=dis[e[i][j].first][e[i][k].first]=min(dis[e[i][j].first][e[i][k].first],(long long)e[i][j].second+e[i][k].second);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		long long sum=1e18;
		for(int j=0;j<(int)e[x].size();j++)
		{
			for(int k=0;k<(int)e[y].size();k++)
			{
				sum=min(sum,dis[e[x][j].first][e[y][k].first]+e[x][j].second+e[y][k].second);
			}
		}
		sum+=W[x];
		sum+=W[y];
		cout<<sum<<'\n';
	}
	return 0;
}
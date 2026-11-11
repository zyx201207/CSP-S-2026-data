//俩图论？
#include<bits/stdc++.h>
#define mian main
#define int long long
using namespace std;
const int M=1e6+5,N=505;
int c,m,d,n,q;
int w[M];
vector<pair<int,int> >in[M];
int dis[N][N];
mian()//   =)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=LONG_LONG_MAX;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		dis[i][i]=0;
		int len;
		cin>>len;
		for(int j=1,v,w;j<=len;j++)
		{
			cin>>v>>w;
			in[v].push_back({i,w});
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int l1=0;l1<in[i].size();l1++)
		{
			int u=in[i][l1].first,uw=in[i][l1].second;
			for(int l2=l1+1;l2<in[i].size();l2++)
			{
				int v=in[i][l2].first,vw=in[i][l2].second;
				dis[u][v]=dis[v][u]=vw+uw;
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(dis[i][k]==LONG_LONG_MAX||dis[k][j]==LONG_LONG_MAX)continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--)
	{
		int x,y,ans=LONG_LONG_MAX;
		cin>>x>>y;
		for(auto i:in[x])
		{
			for(auto j:in[y])
			{
				int u=i.first,v=j.first;
				int uw=i.second,vw=j.second;
				ans=min(ans,dis[u][v]+uw+vw);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}/*
抽中⑨号考场的⑨号位，有说法
Luogu Kanycta
Bilibili UN_kny
QQ 2098401034
Wechat gensokyo524
Endfield 哈撒韦 诺亚
WoT Asia UN_Kanycta
Warthunder Kanycta
哦不不不我又歪羊我无疑是愤怒的
*/
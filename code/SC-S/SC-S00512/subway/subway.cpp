//freopen!!
//only output!! 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505;
const int M=5e5+5;
const int D=25;
//vector<int>a[N];
//struct lines
//{
//	int k;
//	vector<int>a;
////	vector<int>t;
//};
//lines l[N];
//int t[N][M];
bool vis[N][M];
vector<int>chg[M];
//struct stations
//{
////	int line
//	int cost[N];
//};
//vector<stations>t;
vector<int>t[N];
int cnt[M];
int k[N];
int w[M];
struct edge
{
//	int u;
	int v;
	int w;
};
//vector<edge>g[N];
int dp[N][N];
//int zer[N]={0};
vector<int>zer;
//int z[M]={0};
//const int Q=1e5+5;
//int output[Q];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%lld",&w[i]);
//	cout<<"cin1"<<endl;
//	for(int i=1;i<=m;i++)
//		t.push_back({zer});
	for(int i=1;i<=m;i++)
		zer.push_back(0);
	for(int i=1;i<=n;i++)	//line
	{
//		for(int j=1;j<=m;j++)
//			t[i].push_back(0);
//		t.push_back(z);
//		memset(t[i],0,);
		t[i]=zer;
		scanf("%lld",&k[i]);
//		cout<<"cin2 "<<i<<" k\n";
		for(int j=1;j<=k[i];j++)
		{
//			int aij;
//			cout<<"11111\n";
			int aij,tij;
			scanf("%lld%lld",&aij,&tij);
//			l[i].a.push_back(aij);
//			cout<<"22222\n";
//			l[i].t.push_back(tij);
			t[i][aij]=tij;
//			t[aij].cost[i]=tij;
//			cout<<"33333\n";
			vis[i][aij]=1;
			chg[aij].push_back(i);
			cnt[aij]++;
//			cout<<"cin2 "<<i<<" "<<j<<"\n";
		}
//		cout<<"cin2 "<<i<<"\n";
	}
//	cout<<"cin2"<<endl;
	//set
//	for(int i=1;i<=m;i++)	//station
//	{
//		for(int j=1;j<=n;j++)	//line
//			if(vis[j][i])
//			{
//				chg[i].push_back(j);
//				cnt[i]++;
//			}
//	}
//	cout<<"set1"<<endl;
	memset(dp,0x3f,sizeof dp);
	for(int i=1;i<=m;i++)	//station
	{
		for(int u=0;u<cnt[i];u++)	//line
			for(int v=u+1;v<cnt[i];v++)	//line
			{
				int uu=chg[i][u],vv=chg[i][v];
				int w=t[uu][i]+t[vv][i];
//				g[u].push_back({v,w});
//				g[v].push_back({u,w});
				dp[uu][vv]=min(dp[uu][vv],w);
//				dp[vv][uu]=min(dp[vv][vv],w);
			}
	}
//	cout<<"set2"<<endl;
	for(int i=1;i<=n;i++)
		dp[i][i]=0;
//	for(int i=1;i<=n;i++)
//		for(int j=i-1;j>=1;j--)
//			dp[i][j]=dp[j][i];
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
//	cout<<"floyd"<<endl;
	for(int cs=1;cs<=q;cs++)
	{
		int u,v;
		scanf("%lld%lld",&u,&v);
		int ans=1e18;
		for(int i=0;i<cnt[u];i++)
			for(int j=0;j<cnt[v];j++)
			{
				int rt=dp[chg[u][i]][chg[v][j]]+w[u]+w[v]+t[chg[u][i]][u]+t[chg[v][j]][v];
				ans=min(ans,rt);
			}
		printf("%lld\n",ans);
//		output[cs]=ans;
	}
	//check
//	freopen("subway7.ans","r",stdin);
//	for(int cs=1;cs<=q;cs++)
//	{
//		int ls;
//		scanf("%lld",&ls);
//		if(ls!=output[cs])
//		{
//			cout<<"WA on line "<<cs;
//			return 0;
//		}
//	}
//	cout<<"AC";
	
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//			cout<<dp[i][j]<<' ';
//		cout<<"\n";
//	}
//	cout<<"\n";
//	for(int i=1;i<=m;i++)
//	{
//		cout<<cnt[i]<<" ";
//		for(int j=0;j<cnt[i];j++)
//			cout<<chg[i][j]<<' ';
//		cout<<"\n";
//	}
//	cout<<"\n";
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//			cout<<vis[i][j]<<' ';
//		cout<<"\n";
//	}
//	cout<<"\n";
//	for(int i=1;i<=m;i++)
//		cout<<w[i]<<' ';
	return 0;
}
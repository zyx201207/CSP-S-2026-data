#include<bits/stdc++.h>
#define MAXN 10000000000000000
using namespace std;
struct node{
	long long xian,ti;
};
long long c,n,m,d,q;
long long w[500005],k[505];
vector<node> a[500005];
long long ma[505][505];
long long dis[505][505];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=n;i++)
		for(long long j=1;j<=n;j++)
			ma[i][j]=MAXN;
	for(long long i=1;i<=m;i++) cin>>w[i];
	for(long long i=1;i<=n;i++)
	{
		cin>>k[i];
		for(long long j=1;j<=k[i];j++)
		{
			node T;long long lin; 
			cin>>lin>>T.ti;
			T.xian=i;
			for(long long no=0;no<a[lin].size();no++)
			{
				node now=a[lin][no];
				if(ma[now.xian][i]>T.ti+now.ti)
				{
					ma[now.xian][i]=T.ti+now.ti;
					ma[i][now.xian]=T.ti+now.ti;
				}
			}
			a[lin].push_back(T);
		}
	}
	for(long long i=1;i<=n;i++) ma[i][i]=0;
	//for(long long i=1;i<=n;i++,cout<<endl)
	//	for(long long j=1;j<=n;j++)
	//		cout<<ma[i][j]<<' ';
	for(long long i=1;i<=n;i++)
		for(long long j=1;j<=n;j++)
			dis[i][j]=ma[i][j];
	for(long long i=1;i<=n;i++)
		for(long long j=1;j<=n;j++)
			for(long long mid=1;mid<=n;mid++)
				dis[i][j]=min(dis[i][j],dis[i][mid]+dis[j][mid]);
	//for(long long i=1;i<=n;i++,cout<<endl)
	//	for(long long j=1;j<=n;j++)
	//		cout<<dis[i][j]<<' ';
			
	while(q--)
	{
		long long s,t,ans=MAXN;
		cin>>s>>t;
		for(long long i=0;i<a[s].size();i++)
			for(long long j=0;j<a[t].size();j++)
				ans=min(ans,dis[a[s][i].xian][a[t][j].xian]+a[s][i].ti+a[t][j].ti);
		cout<<ans+w[s]+w[t]<<endl;
	}
	return 0;
}

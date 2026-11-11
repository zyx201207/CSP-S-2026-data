#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=525;
const int M=5e5+25;
int c,n,m,d,q;
int val[M];
struct edge
{
	int to;
	int val;
};
vector<edge> st[M];
int dis[N][N];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	cin>>c>>n>>m>>d>>q;
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
//	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=N-20;i++)
	{
		for(int j=1;j<=N-20;j++)
		{
			if(i==j)
			{
				dis[i][j]=0;
			}
			else
			{
				dis[i][j]=0x3f3f3f3f3f3f3f3f;
			}
		}
	}
//	m is the subway station!!!
//  n is the subway!!!
	for(int i=1;i<=m;i++)
	{
//		cin>>val[i];	
		scanf("%lld",&val[i]);
	}	
	for(int i=1;i<=n;i++)
	{
		int now=i;
		int k;
		cin>>k;
		for(int i=1;i<=k;i++)
		{
			int to,time;
//			cin>>to>>time;
			scanf("%lld %lld",&to,&time);
			if(st[to].size())
			{
//				cout<<to<<" A\n";
				for(int i=0;i<st[to].size();i++)
				{
					int to_s=st[to][i].to;
					int to_t=st[to][i].val;
					dis[now][to_s]=min(dis[now][to_s],to_t+time);
					dis[to_s][now]=min(dis[to_s][now],to_t+time);
				}
			}	
			st[to].push_back({now,time});
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
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			cout<<dis[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int t=1;t<=q;t++)
	{
		int ans=0x3f3f3f3f3f3f3f3f;
		int a,b;
//		cin>>a>>b;
		scanf("%lld %lld",&a,&b);
//		cout<<"ab:"<<a<<" "<<b<<"\n";
		int cost=val[a]+val[b];
//		for(int i=0;i<st[a].size();i++)
//		{
//			cout<<st[a][i].to<<" ";
//		}
//		cout<<"\n";
//		for(int i=0;i<st[b].size();i++)
//		{
//			cout<<st[b][i].to<<" ";
//		}
//		cout<<"\n";
		for(int i=0;i<st[a].size();i++)
		{
			int cc=st[a][i].val;
			int fs=st[a][i].to;
			for(int j=0;j<st[b].size();j++)
			{
				int ss=st[b][j].to;
				cc+=st[b][j].val;
//				cout<<"fsss:"<<fs<<" "<<ss<<endl;
				ans=min(ans,cost+dis[ss][fs]+cc);
				cc=st[a][i].val;
			}
		}
//		cout<<ans<<"\n";
		printf("%lld\n",ans);
	}
	return 0;
}
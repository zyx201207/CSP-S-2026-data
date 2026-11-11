#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=0x3f3f3f3f3f3f;
int c,n,m,d,q,w[500005],ans=0,dis[505][505];
vector<int> l[100005],a[505],t[505];//l:点所在的地铁线 a:第一维：i号线 第二维：第j个站 
signed main()
{
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=505;i++)
	{
		for(int j=1;j<=505;j++)
		{
			if(i!=j)dis[i][j]=MAXN;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int len;
		cin>>len;
		for(int j=1;j<=len;j++)
		{
			int a1,t1;
			cin>>a1>>t1;
			a[i].push_back(a1);
			t[i].push_back(t1);
			l[a1].push_back(i);
			//cout<<a1<<endl;
		}
	}
//	for(int i=1;i<=m;i++)cout<<l[i].size()<<endl; 
	
	for(int i=1;i<=m;i++)cout<<l[i].size()<<endl; 
	for(int i=1;i<=m;i++)//点 
	{
		cout<<l[i].size()<<endl; 
		if(l[i].size()>1)
		{
			for(int j=0;j<l[i].size();j++)
			{
				for(int k=0;k<l[i].size();k++)
				{
					if(j==k) continue;
					int u=l[i][j],v=l[i][k],t1,t2;
					for(int e=0;e<a[u].size();e++)
					{
						if(a[u][e]==i)
						{
							t1=t[u][e];
							break;
						}
					}
					for(int e=0;e<a[v].size();e++)
					{
						if(a[v][e]==i)
						{
							t2=t[v][e];
							break;
						}
					}
					dis[u][v]=dis[v][u]=min(dis[u][v],t1+t2);
				}
			}
		}
	}
	for(int k=1;k<=m;k++)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
			 } 
		}
	}
	cout<<dis[1][2]<<endl;
	while(q--)
	{
		int st,ed;
		cin>>st>>ed;
		int ans=MAXN; 
		for(int i=0;i<l[st].size();i++)
		{
			for(int j=0;j<l[ed].size();j++)
			{
			 	int u=l[st][i],v=l[ed][j];
			 	ans=min(ans,dis[u][v]+w[st]+w[ed]+t[u][st]+t[v][ed]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
 } 

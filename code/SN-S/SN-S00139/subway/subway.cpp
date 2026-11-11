#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+5,N=505,inf=1e18+1;
int w[M],k[N];
int dis[N][N];//两个线路之间最短路程 
vector<pair<int,int> > v[M];//第i个车站所在线路 
int c,n,m,d,q;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q; 
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		int a,t; 
		for(int j=1;j<=k[i];j++) 
		{
			cin>>a>>t;
			v[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=inf; 
	for(int i=1;i<=m;i++)
	{
		for(auto u:v[i])
		{
			for(auto k:v[i])
			{
				dis[u.first][k.first]=min(dis[u.first][k.first],u.second+k.second);
				dis[k.first][u.first]=min(dis[k.first][u.first],u.second+k.second);
			}
		}
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[j][k]); 
	for(int i=1;i<=n;i++) dis[i][i]=0;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int ans=inf;
		for(auto u:v[x]) 
		{
			for(auto k:v[y]) 
			{
				
				ans=min(dis[u.first][k.first]+u.second+k.second,ans); 
		//		cout<<u.first<<" "<<k.first<<" "<<ans<<endl;
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
//15:44   T2有想法
//16:19   T2AC所有大样例。 
//FJY I love u，as long as I AC T2!!!!!!!!!!! 

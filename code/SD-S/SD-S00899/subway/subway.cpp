#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<cstdio>
#include<string>
using namespace std;
#define int long long
const int N=510,M=5e5+10;
struct Node{
	int id,t;
};
int c,n,m,d,q,w[M],dis[N][N],k[N];
vector<Node> mp[M];
signed main(){
	ios::sync_with_stdio(false);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		int a,t;
		for(int j=1;j<=k[i];j++)
		{
			cin>>a>>t;
			Node r;
			r.id=i,r.t=t;
			mp[a].push_back(r);
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int u1=0;u1<mp[i].size();u1++)
		{
			Node u=mp[i][u1];
			for(int v1=0;v1<mp[i].size();v1++)
			{
				Node v=mp[i][v1];
				dis[u.id][v.id]=dis[v.id][u.id]=min(dis[u.id][v.id],u.t+v.t);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		dis[i][i]=0;
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
		int xr,yr,ans=1e18+7;
		cin>>xr>>yr;
		for(int u1=0;u1<mp[xr].size();u1++)
		{
			Node u=mp[xr][u1];
			for(int v1=0;v1<mp[yr].size();v1++)
			{
				Node v=mp[yr][v1];
				ans=min(ans,dis[u.id][v.id]+w[xr]+w[yr]+u.t+v.t);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

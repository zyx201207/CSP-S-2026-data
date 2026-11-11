#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int test,n,m,d,T,f[510][510],c[N],vis1[510],vis2[510];
struct node{
	int to,w;
};
vector<node>q[N];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>test>>n>>m>>d>>T;
	for(int i=1;i<=m;i++)
		cin>>c[i];
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		for(int j=1;j<=x;j++)
		{
			int y,z;
			cin>>y>>z;
			q[y].push_back({i,z});
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=1e16;
	for(int i=1;i<=n;i++)
		f[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<q[i].size();j++)
		{
			int x=q[i][j].to,w=q[i][j].w;
			for(int k=j+1;k<q[i].size();k++)
			{
				int y=q[i][k].to;
				w+=q[i][k].w;
				f[x][y]=f[y][x]=min(f[x][y],w);
				w-=q[i][k].w;
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(T--)
	{
		int x,y,ans=1e18;
		cin>>x>>y;
		for(int i=1;i<=n;i++)
			vis1[i]=vis2[i]=1e16;
		for(int i=0;i<q[x].size();i++)
			vis1[q[x][i].to]=min(vis1[q[x][i].to],q[x][i].w);
		for(int i=0;i<q[y].size();i++)
			vis2[q[y][i].to]=min(vis2[q[y][i].to],q[y][i].w);
		for(int i=0;i<q[x].size();i++)
			for(int j=0;j<q[y].size();j++)
				ans=min(ans,vis1[q[x][i].to]+vis2[q[y][j].to]+f[q[x][i].to][q[y][j].to]);
		cout<<ans+c[x]+c[y]<<"\n";
	}
	return 0;
}

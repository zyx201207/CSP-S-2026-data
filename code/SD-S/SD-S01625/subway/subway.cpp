#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,d,q,w[M],f[N][N];
struct node
{
	int id,x;
};
vector<node> v[M];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x,y;
			cin>>x>>y;
			v[x].push_back((node){i,y});
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			for(int k=j+1;k<v[i].size();k++)
			{
				f[v[i][j].id][v[i][k].id]=min(f[v[i][j].id][v[i][k].id],v[i][j].x+v[i][k].x);
			}
		}
	}
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				f[i][j]=min(f[i][j],f[min(i,k)][max(i,k)]+f[min(j,k)][max(j,k)]);
			}
		}
	}
	while(q--)
	{
		int x,y,ans=1e18;
		cin>>x>>y;
		for(int i=0;i<v[x].size();i++)
		{
			for(int j=0;j<v[y].size();j++)
			{
				ans=min(ans,w[x]+w[y]+v[x][i].x+v[y][j].x+f[min(v[x][i].id,v[y][j].id)][max(v[x][i].id,v[y][j].id)]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;	
} 

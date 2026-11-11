#include<bits/stdc++.h>
#define int long long
using namespace std;
int w[500005];
vector<int> e[505];
vector<int> g[500005];
vector<int> t[505];//线对点 
vector<int> t2[500005];//点对线 
int k[505];
int f[505][505];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
		ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int x,y;cin>>x>>y;
			e[i].push_back(x);
			g[x].push_back(i);
			t[i].push_back(y);
			t2[x].push_back(y);
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++)
	{
		f[i][i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<k[i];j++)
		{
			for(int k=0;k<g[e[i][j]].size();k++)
			{
				//链接边g[e[i][j]][k];
				//点e[i][j] 
				if(g[e[i][j]][k]==i)
				{
					continue;
				}
				f[i][g[e[i][j]][k]]=min(f[i][g[e[i][j]][k]],t[i][j]+t2[e[i][j]][k]);	
			
			}		
		} 
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
			{
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		int ans=0x3f3f3f3f3f3f3f3f;
		cin>>x>>y;
		for(int i=0;i<g[x].size();i++)
		{
			for(int j=0;j<g[y].size();j++)
			{
				ans=min(ans,f[g[x][i]][g[y][j]]+w[x]+w[y]+t2[x][i]+t2[y][j]);
			}
		}
		cout<<ans<<"\n";
	}
	
}

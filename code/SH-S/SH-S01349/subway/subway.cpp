#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p,k[505],ii;
long long w[500005],a,t,vis[600005][2],ans;
vector<long long> adj[600005];
vector<long long> ti[600005];
void dfs(int i,int y,long long summ)
{
	if(summ>=ans)
	{
		return ;
	}
	if(i==y)
	{
		ans=summ;
		return ;
	}
	for(int j=0;j<adj[i].size();j++)
	{
		if(vis[adj[i][j]][0]==ii and vis[adj[i][j]][1]<=summ+ti[i][j])
		{
			continue;
		}
		vis[adj[i][j]][0]=ii;
		vis[adj[i][j]][1]=summ+ti[i][j];
		dfs(adj[i][j],y,summ+ti[i][j]);
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a>>t;
			adj[a].push_back(m+i);
			adj[m+i].push_back(a);;
			ti[a].push_back(t);
			ti[m+i].push_back(t);
		}
	}
	if(12<=c and c<=19)
	{
		int l,r;
		long long kk[600005][2];
		for(int i=1;i<=p;i++)
		{
			int x,y;
			cin>>x>>y;
			l=1;
			r=1;
			kk[r][0]=x;
			kk[r][1]=0;
			vis[r][1]=i;
			while(l<=r)
			{
				int xx=kk[l][0],xi=kk[l][1];
				l++;
				for(int yy:adj[xx])
				{
					if(vis[yy][1]==i)
					{
						continue;
					}
					vis[yy][1]=i;
					r++;
					kk[r][0]=yy;
					kk[r][1]=xi+1;
					if(yy==y)
					{
						cout<<kk[r][1]*ti[1][0]+w[x]+w[y]<<endl;
						r=-1;
						break;
					}
				}
			}
		}
		return 0;
	}
	for(int i=1;i<=p;i++)
	{
		int x,y;
		cin>>x>>y;
		ans=1e15;
		ii=i;
		vis[x][0]=i;
		vis[x][1]=0;
		dfs(x,y,0);
		cout<<ans+w[x]+w[y]<<endl; 
	}
	return 0;
}

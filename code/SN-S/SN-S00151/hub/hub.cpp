#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
int subtask,T,n,m,cnt,ans,h[N],to[N<<1],nt[N<<1],dis[20][20];
bool f[20],in[20];
vector<int> E;
inline void add(int u,int v)
{
	cnt++;
	to[cnt]=v;
	nt[cnt]=h[u];
	h[u]=cnt;
}
void dfss(int p)
{
	f[p]=true;
	for(int i=h[p];i;i=nt[i])
		if (!f[to[i]]&&in[to[i]])
			dfss(to[i]);
}
void dfs(int p,int nds,int st)
{
	if (nds>m||n-p+1<m-nds)
		return;
	if (p==n+1)
	{
		if (nds==m)
		{
			E.clear();
			int s=0,sum=0;
			for(int i=1;i<=n;i++)
			{
				f[i]=in[i]=false;
				if ((1<<(i-1))&st)
				{
					E.push_back(i);
					in[i]=true;
				}
			}
			for(int i=0;i<m;i++)
			{
				int k=E[i];
				if (!f[k])
				{
					dfss(k);
					sum++;
				}
			}
			if (sum>2)
				return;
			for(int i=1;i<=n;i++)
			{
				int d=1e8;
				for(int j=0;j<m;j++)
					d=min(d,dis[i][E[j]]);
				s=max(d,s);
			}
			ans=min(ans,s);
		}
		return;
	}
	dfs(p+1,nds+1,st|(1<<(p-1)));
	dfs(p+1,nds,st);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>subtask>>T;
	if (subtask<=3)
	{
		while(T--)
		{
			cin>>n>>m;
			for(int i=1;i<=n;i++)
			{
				h[i]=0;
				for(int j=1;j<=n;j++)
					dis[i][j]=1e8;
				dis[i][i]=0;
			}
			cnt=0;
			ans=1e8;
			for(int i=1;i<n;i++)
			{
				int u,v;
				cin>>u>>v;
				dis[u][v]=dis[v][u]=1;
				add(u,v);
				add(v,u);
			}
			for(int k=1;k<=n;k++)
				for(int i=1;i<=n;i++)
					for(int j=1;j<=n;j++)
						if (i!=j&&i!=k&&j!=k)
							dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			dfs(1,0,0);
			cout<<ans<<"\n";
		}
		return 0;
	}
}

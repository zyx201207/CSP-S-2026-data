#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,a[500010],t[500010],w[500010],c2[500010],tot,d2[500010],k3[500010],a2[500010][5],t2[500010][5];
long long dis[500010];
bool vis[500010];
long long dis2[810][810];
struct node
{
	int to;
	long long v;
	bool operator <(const node &a)const
	{
		return v>a.v;
	}
};
vector<node>b[500010];
long long bfs(int x,int y)
{
	for(int i=1;i<=m;i++)
	{
		dis[i]=0x3f3f3f3f3f3f3f3f;
		vis[i]=0;
	}
	dis[x]=0;
	vis[x]=1;
	priority_queue<node>q;
	q.push({x,dis[x]});
	while(!q.empty())
	{
		int f=q.top().to;
		q.pop();
		vis[f]=0;
		if(f==y)
		{
			return dis[y];
		}
		for(int i=0;i<b[f].size();i++)
		{
			int to=b[f][i].to;
			if(dis[to]>dis[f]+b[f][i].v)
			{
				dis[to]=dis[f]+b[f][i].v;
				if(!vis[to])
				{
					vis[to]=1;
					q.push({to,dis[to]});
				}
			}
		}
	}
}
int main()
{
	//freopen("subway4.in","r",stdin);
	//freopen("subwaycppout.cpp","w",stdout);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	if(c>=7&&c<=11)
	{
		
		for(int i=1;i<=n;i++)
		{
			cin>>k3[i];
			for(int j=1;j<=k3[i];j++)
			{
				cin>>a2[i][j]>>t2[i][j];
			}
			if(k3[i]==2)
			{
				vis[a2[i][1]]=1;
				vis[a2[i][2]]=1;
			}
		}
		for(int i=1;i<=m;i++)
		{
			if(vis[i])
			{
				c2[++tot]=i;
			}
		}
		sort(c2+1,c2+1+tot);
		int m2=unique(c2+1,c2+1+tot)-c2-1;
		for(int i=1;i<=m2;i++)
		{
			d2[c2[i]]=i;
			//cout<<c2[i]<<endl;
		}
		for(int i=1;i<=m2;i++)
		{
			for(int j=1;j<=m2;j++)
			{
				dis2[i][j]=0x3f3f3f3f3f3f3f3f;
			}
			dis2[i][i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			if(k3[i]==2)
			{
				dis2[d2[a2[i][1]]][d2[a2[i][2]]]=dis2[d2[a2[i][2]]][d2[a2[i][1]]]=(1ll*t2[i][1]+1ll*t2[i][2]);
			}
		}
		for(int k2=1;k2<=m2;k2++)
		{
			for(int i=1;i<=m2;i++)
			{
				for(int j=1;j<=m2;j++)
				{
					if(dis2[i][j]>(dis2[i][k2]+dis2[k2][j]))
					{
						dis2[i][j]=dis2[j][i]=(dis2[i][k2]+dis2[k2][j]);
					}
				}
			}
		}
		for(int i=1;i<=q;i++)
		{
			int x,y;
			cin>>x>>y;
			if(x==y)
			{
				cout<<"0\n";
			}
			else
			{
				cout<<(long long)(dis2[d2[x]][d2[y]]+1ll*w[x]+1ll*w[y])<<"\n";
			}
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[j]>>t[j];
			for(int k2=1;k2<j;k2++)
			{
				b[a[j]].push_back({a[k2],1ll*t[j]+1ll*t[k2]});
				b[a[k2]].push_back({a[j],1ll*t[j]+1ll*t[k2]});
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<(long long)(1ll*bfs(x,y)+1ll*w[x]+1ll*w[y])<<"\n";
	}
	return 0;
}

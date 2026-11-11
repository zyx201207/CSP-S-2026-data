#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(f=='-')
			f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
vector<int> p[510];
int t[510][500010],n,m,d,q,vis[500010],dis[510],w[510];
int dfs(int x,int y)
{
	queue<pair<int,int>> q;
	q.push({x,0});
	vis[x]=1;
	while(!q.empty())
	{
		auto u=q.front();
		int xn=u.second;
		int z=u.first;
		q.pop();
		for(int i=1;i<=n;i++)
		{
			if(t[i][z])
			{
				if(i!=xn)
					dis[z]+=(t[i][z]+t[xn][z]);
				for(int g:p[i])
				{
					if(g==y)
						return dis[g];
					if(!vis[g])
					{
						vis[g]=1;
						q.push({g,i});
					}
				}	
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;
	cin>>c;
	n=read();
	m=read();
	d=read();
	q=read();
	memset(t,-1,sizeof(t));
	for(int i=1;i<=n;i++)
	{
		w[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a=read();
			p[i].push_back(a);
			a=read();
			t[i][p[i][j-1]]=a;
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]<<'\n';
	}
	return 0;
}
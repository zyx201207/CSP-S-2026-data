#include<bits/stdc++.h>
using namespace std;
long long int c,n,m,d,q,w[500010],k[510],a[510][50010],v[500010],vis[510][50010],t[510][50010],x,y,dis;
struct node
{
	long long int id,res,last;
};
int bfs(long long int s,long long int dd)
{
	queue<node> q;
	node u;
	u.id=s;
	u.res=w[s];
	u.last=0;
	q.push(u);
	while(!q.empty())
	{
		u=q.front();
		v[u.id]=1;
		q.pop();
		for(long long int i=1;i<=n;i++)
		{
			if(i==u.last)
			{
				continue;
			}
			if(vis[i][u.id])
			{
				node nt;
				nt.res=u.res+t[u.last][vis[u.last][u.id]]+t[i][vis[i][u.id]];
				nt.last=i;
				for(long long int j=1;j<=k[i];j++)
				{
					if(u.id==a[i][j])
					{
						continue;
					}
					nt.id=a[i][j];
					if(a[i][j]==dd)
					{
						nt.res+=t[i][vis[i][a[i][j]]];
						dis=min(dis,nt.res);
					}
					else if(v[a[i][j]]==0)
					{
						q.push(nt);
					}
				}
			}
		} 
	}
	return 0;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(long long int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(long long int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			vis[i][a[i][j]]=j;
		}
	}
	while(q--)
	{
		cin>>x>>y;
		memset(v,0,sizeof(v));
		dis=1e18;
		bfs(x,y);
		cout<<dis+w[y]<<endl;
	}
	return 0;
}

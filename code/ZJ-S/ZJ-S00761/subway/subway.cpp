#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
struct node{
	int u,v,id;
}c[N];
struct node1{
	int x,y;
}nd[N];
vector<int>a[N],b[N],e[N],f[N];
int d[N],n,used[N],id,m,t,pc[N],q,fl[N],ans[N],aqpc,p[2][N];
bool cmp1(node1 x,node1 y)
{
	return x.x<y.x;
}
bool cmp(node x,node y)
{
	if(x.u==y.u)
		return x.v<y.v;
	return x.u<y.u;
}
void dj(int st)
{
	d[st]=0;
	memset(used,0,sizeof(used));
	for(int i=st+1;i<=n;i++)
		d[i]=1e18;
	priority_queue<pair<int,int> >q;
	q.push(make_pair(0,st));
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(used[u])	continue;
		used[u]=1;
		for(int i=0;i<e[u].size();i++)
		{
			for(int j=f[u][i];j<a[e[u][i]].size();j++)
			{
				int v=a[e[u][i]][j];
				if(d[v]>d[u]+b[e[u][i]][f[u][i]-1]+b[e[u][i]][j])
				{
					d[v]=d[u]+b[e[u][i]][f[u][i]-1]+b[e[u][i]][j];
					q.push(make_pair(-d[v],v));
				}
			}
		}
	}
}
void wcypc()
{
	for(int i=0;i<=1;i++)
	{
		int k;
		cin>>k;
		for(int j=1,x,y;j<=k;j++)
		{
			cin>>x>>y;
			fl[x]+=i+1;
			p[i][x]=y;
		}
	}
	int res=1e18;
	for(int i=1;i<=n;i++)
		if(fl[i]==3)
			res=min(res,p[1][i]+p[2][i]);
	while(q--)
	{
		int u,v;
		cin>>u>>v;
		int ans=0;
		if(fl[u]==1)
		{
			if(fl[v]==1)
				ans=p[1][u]+p[1][v];
			else
				ans=min(p[1][u]+res+p[2][v],p[1][u]+p[1][v]);
		}
		else if(fl[u]==2)
		{
			ans=p[2][u]+p[2][v];
			if(fl[v]==3)
				ans=min(ans,p[2][u]+res+p[1][v]);
		}
		else
		{
			if(fl[v]==3)
				ans=min(min(p[1][u]+res+p[2][v],p[1][u]+p[1][v]),min(p[2][u]+res+p[1][v],p[2][u]+p[2][v]));
			else if(fl[v]==1)
				ans=min(p[1][u]+p[1][v],p[2][u]+res+p[1][v]);
			else
				ans=min(p[2][u]+p[2][v],p[1][u]+res+p[2][v]);
		}
		cout<<ans+pc[u]+pc[v]<<"\n";
	}
}
signed main()
{
 	freopen("subway.in","r",stdin);
 	freopen("subway.out","w",stdout);
 	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>id>>m>>n>>aqpc>>q;
	for(int i=1;i<=n;i++)	cin>>pc[i];
	if(id==20||id==21)
	{
		wcypc();
		return 0;
	}
	for(int i=1,k;i<=m;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
			cin>>nd[j].x>>nd[j].y;
		sort(nd+1,nd+1+k,cmp1);
		for(int j=1;j<=k;j++)
		{
			a[i].push_back(nd[j].x);
			b[i].push_back(nd[j].y);
			e[nd[j].x].push_back(i);
			f[nd[j].x].push_back(j);
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>c[i].u>>c[i].v;
		c[i].id=i;
		if(c[i].u>c[i].v)
			swap(c[i].u,c[i].v);
	}
	sort(c+1,c+1+q,cmp);
	for(int i=1;i<=q;i++)
	{
		if(!fl[c[i].u])
		{
			fl[c[i].u]=1;
			dj(c[i].u);
		}
		ans[c[i].id]=d[c[i].v]+pc[c[i].u]+pc[c[i].v];
	}
	for(int i=1;i<=q;i++)	
		cout<<ans[i]<<"\n";
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef const int cint;
cint N=3000; 
ll fl[N][N];
ll lu[N][25],w[N][25],len[N],jin[N],dis[N],vis[N];
ll c,n,m,d,q;
ll mackdis(int u,int v)
{
	int ju=1;
	ll s=1e17;
	for(int i=1;i<=len[v];i++)
	{
		while(ju<len[u]&&lu[v][i]>lu[u][ju])
		{
			ju++;
		}
		if(lu[u][ju]==lu[v][i])
		{
			s=min(s,w[u][ju]+w[v][i]);
		}
	}
	return s;
}
ll dij(int f,int e)
{
	priority_queue<pair<ll,ll> > q;
	q.push({0,f});
	memset(vis,0,sizeof vis);
	memset(dis,0x3f,sizeof dis);
	ll x,y,ny;
	while(q.size())
	{
		x=q.top().second;
		y=-q.top().first;
		q.pop();
		if(vis[x]==1)continue;
		vis[x]=1;
		if(x==e)return y;
		for(int i=1;i<=m;i++)
		{
			ny=y+fl[x][i];
			if(y<dis[i])
			{
				dis[i]=ny;
				q.push({-dis[i],i});
			}
		} 
	} 
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>jin[i];
	}
	for(int k,i=1;i<=n;i++)
	{
		cin>>k;
		for(int a,t,j=1;j<=k;j++)
		{
			cin>>a>>t;
			len[a]++;
			lu[a][len[a]]=i;
			w[a][len[a]]=t;
		}
	}
//	cout<<lu[1][1]<<" "<<lu[3][1]<<endl;
	for(int u=1;u<=m;u++)
	{
		for(int v=1;v<=m;v++)
		{
			fl[u][v]=1e17;
			if(u==v)fl[u][v]=0;
			else fl[u][v]=mackdis(u,v);
		}
	}
//	cout<<fl[1][3]<<endl;
	int x,y;
	if(q<=3000)
	{
		
		while(q--)
		{
			cin>>x>>y;
			cout<<jin[x]+jin[y]+dij(x,y)<<'\n';
		}
	}
	else
	{
		for(int i=1;i<=m;i++)
		{
			for(int u=1;u<=m;u++)
			{
				for(int v=1;v<=m;v++)
				{
					fl[u][v]=min(fl[u][i]+fl[i][v],fl[u][v]);
				}
			}
		}
		int x,y;
		while(q--)
		{
			cin>>x>>y;
			cout<<jin[x]+jin[y]+fl[x][y]<<'\n';
		}
	}

	return 0;
}




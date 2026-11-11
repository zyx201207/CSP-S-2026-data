#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=507;
const int M=500067;
ll o,n,m,d,q,w[M],k[N];
vector<pair<ll,ll> >a[M];
vector<pair<ll,ll> >g[N];
map<pair<ll,ll>,ll> vis;
vector<pair<ll,ll> >gg[N];
ll ans;ll dis[N<<1][N<<1];
int vi[N];
int f(int id,int u)
{
	for(int i=0;i<a[id].size();i++)
		if(a[id][i].first==u) return a[id][i].second;
	return -1;
}
int f2(int idp,int idn,int u)
{
	int res=0;
	for(int i=0;i<a[idp].size();i++)
		if(a[idp][i].first==u) res+=a[idp][i].second;
	for(int i=0;i<a[idn].size();i++)
		if(a[idn][i].first==u) res+=a[idn][i].second;
	return res;
}
void dfs(ll u,ll stt,ll tot,ll ed,ll now)
{
	if(u==ed)
	{
		ans=min(ans,tot+f(now,u));
		return;
	}
	for(int i=0;i<g[u].size();i++)
	{
		int v=g[u][i].first,bel=g[u][i].second;
		if(vis[make_pair(v,bel)]) continue;
		if(u==stt)
		{
			vis[make_pair(v,bel)]=1;
			dfs(v,stt,tot+f(bel,u),ed,bel);
			vis[make_pair(v,bel)]=0;
		}
		else if(bel==now)
		{
			vis[make_pair(v,bel)]=1;
			dfs(v,stt,tot,ed,bel);
			vis[make_pair(v,bel)]=0;
		}
		else
		{
			vis[make_pair(v,bel)]=1;
			dfs(v,stt,tot+f2(now,bel,u),ed,bel);
			vis[make_pair(v,bel)]=0;
		}
	}
	return;
}
void work1()
{
	while(q--)
	{
		ll s,t;cin >> s >> t;
		vis.clear();
		ans=1e18;
		dfs(s,s,0,t,0);
		cout << w[s]+w[t]+ans << '\n';
	}
	return;
}
void dij(int s)
{
	memset(vi,0,sizeof(vi));
	priority_queue<pair<int,int> >q;
	q.push(make_pair(0,s));
	dis[s][s]=0;
	while(!q.empty())
	{
		int u=q.top().second;q.pop();
		if(vi[u]) continue;vi[u]=1;
		for(int i=0;i<gg[u].size();i++)
		{
			int v=gg[u][i].first,w=gg[u][i].second;
			if(dis[s][u]+w<dis[s][v])
			{
				dis[s][v]=dis[s][u]+w;
				q.push(make_pair(-dis[s][v],v));
			}
		}
	}
}
void work2()
{
	for(int i=1;i<=n;i++)
		for(int j=0;j<a[i].size()-1;j++)
		{
			int u=a[i][j].first,v=a[i][j+1].first;
			gg[u].push_back(make_pair(v,a[i][j].second+a[i][j+1].second));
			gg[v].push_back(make_pair(u,a[i][j].second+a[i][j+1].second));
		}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++)
		dij(i);
	while(q--)
	{
		ll s,t;
		cin >> s >> t;
		cout << dis[s][t]+w[s]+w[t] << '\n';
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> o >> n >> m >> d >> q;
	for(int i=1;i<=m;i++)
		cin >> w[i];
	for(int i=1;i<=n;i++)//line i
	{
		cin >> k[i];
		for(int j=1;j<=k[i];j++)
		{
			int id,zz;
			cin >> id >> zz;
			a[i].push_back(make_pair(id,zz));
			//zz:station id hall->platform i
			//first:"a" second:"t"
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<a[i].size()-1;j++)
		{
			g[a[i][j].first].push_back(make_pair(a[i][j+1].first,i));
			g[a[i][j+1].first].push_back(make_pair(a[i][j].first,i));
		}
			
	}
	if(o<=6) work1();//24pts
	else if(o<=11) work2();//44pts
	else cout << "end.";
	return 0;
}
//16:52 44pts

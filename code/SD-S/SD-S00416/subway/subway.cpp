#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX=5e5;
const ll inf=1e17;
int c;
vector<pair<ll,ll> >G[MX+10];
ll n,m,dd,qq,i,ii,jj,j,mx,w[510],k[510],a[510][5],t[510][5],d[MX+10],vis[MX+10],x[MX+10],y[MX+10];
ll ans[MX+10];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>dd>>qq;
	for(i=1;i<=m;i++)cin>>w[i];
	for(i=1;i<=n;i++)
	{
		cin>>k[i];
		for(j=1;j<=k[i];j++)cin>>a[i][j]>>t[i][j],mx=max(mx,a[i][j]);
	}
	for(i=1;i<=qq;i++)
	{
		cin>>x[i]>>y[i];
		if(x[i]>y[i])swap(x[i],y[i]);
	}
	if(c>=7&&c<=11)
	{
		for(i=1;i<=n;i++)
		{
			ans[a[i][2]]+=t[i][1]+t[i][2];
		}
		for(i=2;i<=mx;i++)ans[i]+=ans[i-1];
		for(ii=1;ii<=qq;ii++)
		{
			cout<<ans[y[ii]]-ans[x[ii]]+w[x[ii]]+w[y[ii]]<<'\n';
		}
	}
	if(c>=1&&c<=6)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=k[i];j++)
			{
				for(jj=1;jj<j;jj++)
				{
					ll nu=a[i][jj],nw=t[i][jj]+t[i][j];
					ll nv=a[i][j];
					G[nu].push_back({nv,nw});
					G[nv].push_back({nu,nw});
				}
			}
		}
//		for(i=1;i<=100;i++)
//		{
//			for(j=0;j<G[i].size();j++)
//			{
//				cout<<G[i][j].first<<" "<<G[i][j].second<<'\n';
//			}
//		}
		for(ii=1;ii<=qq;ii++)
		{
			priority_queue<pair<ll,ll> >q;
			for(i=1;i<=500;i++)d[i]=inf;
			memset(vis,0,sizeof(vis));
			q.push({0,x[ii]});
			d[x[ii]]=0;
			while(!q.empty())
			{
				ll u=q.top().second;
				q.pop();
				if(vis[u])continue;
				vis[u]=1;
				for(i=0;i<G[u].size();i++)
				{
					int vv=G[u][i].first,ww=G[u][i].second;
					if(d[vv]>d[u]+ww)
					{
						d[vv]=d[u]+ww;
					//	cout<<d[vv]<<" ";
						q.push({-d[vv],vv});
					//	cout<<"**"<<" ";
					}
				}
			}
			cout<<d[y[ii]]+w[y[ii]]+w[x[ii]]<<'\n';
		}
	}
	return 0;
}

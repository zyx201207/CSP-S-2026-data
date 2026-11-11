//好想被 OI 折磨成小楠梁 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll ID,n,m,d,q;
ll w[500005];
vector<ll> e[500005],t[500005];
ll dis[505][505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>ID>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		ll k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			ll id,dis;
			cin>>id>>dis;
			e[id].push_back(i);
			t[id].push_back(dis);
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=1e16;
	for(int i=1;i<=n;i++)
		dis[i][i]=0;
	for(int i=1;i<=m;i++)
		for(int j=0;j<e[i].size();j++)
			for(int k=j+1;k<e[i].size();k++)
				if(dis[e[i][j]][e[i][k]]>t[i][j]+t[i][k])
					dis[e[i][j]][e[i][k]]=dis[e[i][k]][e[i][j]]=t[i][j]+t[i][k];
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(dis[i][j]>dis[i][k]+dis[k][j])
					dis[i][j]=dis[i][k]+dis[k][j];
	for(int i=1;i<=q;i++)
	{
		int u,v;
		cin>>u>>v;
		ll mn=1e16;
		for(int j=0;j<e[u].size();j++)
			for(int k=0;k<e[v].size();k++)
				mn=min(mn,dis[e[u][j]][e[v][k]]+t[u][j]+t[v][k]);
		cout<<mn+w[u]+w[v]<<"\n";
	}
	return 0;
}
//CSP-S 2026 rp+=infinty

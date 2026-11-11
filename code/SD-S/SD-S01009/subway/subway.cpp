#include<bits/stdc++.h>
#define lltt long long
using namespace std;
const lltt inf=1e16;
int C,n,m,d,q;
lltt dis[505][505],w[500005];
vector<pair<int,lltt> >v[500005];
int main()
{
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	scanf("%d%d%d%d%d",&C,&n,&m,&d,&q);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			dis[i][j]=inf;
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++)
		scanf("%lld",&w[i]);
	for(int id=1;id<=n;id++)
	{
		int k;
		scanf("%d",&k);
		for(int i=1;i<=k;i++)
		{
			int x;
			lltt val;
			scanf("%d%lld",&x,&val);
			for(auto it:v[x])
			{
				dis[id][it.first]=min(dis[id][it.first],val+it.second);
				dis[it.first][id]=dis[id][it.first];
			}
			v[x].push_back({id,val});
		}
	} 
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//			cout<<dis[i][j]<<" ";
//		cout<<"\n";
//	}
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		lltt ans=inf;
		for(auto it1:v[x])
			for(auto it2:v[y])
				ans=min(ans,w[x]+w[y]+it1.second+it2.second+dis[it1.first][it2.first]);
		cout<<ans<<"\n";
	}
	return 0;
}

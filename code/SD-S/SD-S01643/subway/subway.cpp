#include<bits/stdc++.h>
using namespace std;
const long long inf=1e18;
long long c,n,m,d,q;
long long w[500005];
long long dis[505][505];
vector<pair<long long,long long> > nod[500005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++) cin>>w[i];
	for(long long i=1;i<=n;i++)
	{
		long long k=0,pos=0,tim=0;
		cin>>k;
		for(long long j=1;j<=k;j++)
		{
			cin>>pos>>tim;
			nod[pos].push_back(make_pair(i,tim)); 
		}
	}
	memset(dis,10,sizeof(dis));
	for(long long i=1;i<=n;i++) dis[i][i]=0; 
	for(long long i=1;i<=m;i++)
	{
		for(long long x=0;x<(long long)nod[i].size();x++)
		{
			for(long long y=x+1;y<(long long)nod[i].size();y++)
			{
				long long id1=nod[i][x].first,id2=nod[i][y].first;
				long long val=nod[i][x].second+nod[i][y].second;
				dis[id1][id2]=min(dis[id1][id2],val);
				dis[id2][id1]=min(dis[id2][id1],val);
			}
		}
	}
	for(long long k=1;k<=n;k++)
	{
		for(long long i=1;i<=n;i++)
		{
			for(long long j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(long long i=1;i<=q;i++)
	{
		long long s=0,t=0,ans=inf;
		cin>>s>>t;
		for(long long j=0;j<(long long)nod[s].size();j++)
		{
			for(long long k=0;k<(long long)nod[t].size();k++)
			{
				long long res=0;
				res+=dis[nod[s][j].first][nod[t][k].first];
				res+=nod[s][j].second+nod[t][k].second;
				res+=w[s]+w[t];
				ans=min(ans,res);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

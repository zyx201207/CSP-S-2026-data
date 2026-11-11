#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p,k,xx,yy,x[500005],y,w[500005];
queue<int>q;
long long dist[500005],b[1005][1005],a[500005];
bool f[500005],dp[1005][1005];
vector<int>ll[500005];
void spfa()
{
	memset(dist,0x3f,sizeof(dist));
	memset(f,false,sizeof(f));
	dist[xx]=w[xx];
	q.push(xx);
	f[xx]=true;
	while(q.size())
	{
		int t=q.front();
		q.pop();
		f[t]=false;
		for(int i=0;i<ll[t].size();i++)
		{
			int j=ll[t][i];
			if(dist[j]>dist[t]+b[t][j])
			{
				dist[j]=dist[t]+b[t][j];
				q.push(j);
				f[j]=true;
			}
		}
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	memset(b,0x3f,sizeof(b));
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>x[j]>>y;
			a[x[j]]=y;
		}
		for(int j=1;j<=k-1;j++)
		{
			for(int l=2;l<=k;l++)
			{
				if(dp[x[j]][x[l]]==false)
				{
					dp[x[j]][x[l]]=true;
					dp[x[l]][x[j]]=true;
					ll[x[j]].push_back(x[l]);
					ll[x[l]].push_back(x[j]);
				}
				b[x[j]][x[l]]=b[x[l]][x[j]]=min(b[x[j]][x[l]],a[x[j]]+a[x[l]]);
			}
		}
	}
	for(int i=1;i<=p;i++)
	{
		cin>>xx>>yy;
		spfa();
		cout<<dist[yy]+w[yy]<<endl;
	}
	return 0;
} 